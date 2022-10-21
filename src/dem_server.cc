#include "dem_server.hpp"
#include "transformation.hpp"
#include <cmath>
#include <grpcpp/support/status_code_enum.h>
#include <stdexcept>

OGRLineString *WktToLinestring(const std::string &wkt) {
  OGRLineString line;
  const char *str = wkt.c_str();
  line.assignSpatialReference(
      height_service::SpatialReference::GetFromEPSG(4326));
  OGRErr err = line.importFromWkt((const char **)&str);
  if (err != OGRERR_NONE) {
    throw std::invalid_argument("wkt参数错误");
  }
  return line.clone();
}

/**
 * @brief 欧式距离
 *
 * @param rhs const OGRPint &
 * @param lhs const OGRPoint &
 * @return 两点间的距离
 */
double DistanceOfTwoPoint(const OGRPoint &rhs, const OGRPoint &lhs) {
  double x1, x2, y1, y2;
  x1 = rhs.getX();
  x2 = lhs.getX();
  y1 = rhs.getY();
  y2 = rhs.getY();
  return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

OGRLineString *PickLine(const OGRLineString *line, int nums = 20) {
  double lenght = line->get_Length();
  double clipLen = lenght / nums;
  OGRLineString reline;
  reline.assignSpatialReference(
      height_service::SpatialReference::GetFromEPSG(4326));
  for (int i = 0; i < line->getNumPoints() - 1; ++i) {
    OGRPoint point1, point2;
    line->getPoint(i, &point1);
    line->getPoint(i + 1, &point2);
    double distanceOfTwoPoint = DistanceOfTwoPoint(point1, point2);
    if (distanceOfTwoPoint < clipLen) {
      reline.addPoint(point1.clone());
      continue;
    }
  }
  return nullptr;
}

grpc::Status
DemServiceImpl::GetHeight(grpc::ServerContext *context,
                          const dem_service::GetHeightRequest *request,
                          dem_service::GetHeightReply *reply) {
  const auto &wkts = request->wkts();
  for (const auto &it : wkts) {
    try {
      const std::string re = Read(it, request->is_trans());
      gpr_log(GPR_INFO, "result: %s", re.c_str());
      reply->add_wkts(re);

    } /* catch (std::runtime_error &e) {
      gpr_log(GPR_ERROR, "%s", e.what());
    } */
    catch (std::exception &e) {
      gpr_log(GPR_ERROR, "%s", e.what());
      return grpc::Status(grpc::StatusCode::INTERNAL, e.what());
    }
  }
  return grpc::Status::OK;
}

const std::string DemServiceImpl::Read(const std::string &wkt,
                                       bool isTrans) const {

  if (std::regex_match(
          wkt, std::regex("^ *Point.*$", std::regex_constants::icase))) {
    return ReaderPoint(wkt, isTrans);
  } else if (std::regex_match(wkt, std::regex("^ *LineString.*$",
                                              std::regex_constants::icase))) {
    return ReaderLineString(wkt, isTrans);
  } else {
    throw std::invalid_argument("参数错误");
  }
}

height_service::HeightReader *DemServiceImpl::reader = nullptr;
std::mutex DemServiceImpl::_mutex;

void DemServiceImpl::Init(const std::string &path, int limit) {
  reader = new height_service::HeightReader(path, limit);
}

void DemServiceImpl::DestoryHeightReader() {
  _mutex.lock();
  if (reader != nullptr) {
    delete reader;
  }
  _mutex.unlock();
}

const std::string DemServiceImpl::ReaderPoint(const std::string &wkt,
                                              bool isTrans) const {
  OGRPoint point;
  const char *str = wkt.c_str();
  point.importFromWkt((const char **)(&str));
  {
    std::lock_guard<std::mutex> lock(_mutex);
    point.assignSpatialReference(
        height_service::SpatialReference::GetFromEPSG(4326));
    gpr_log(GPR_INFO, "Beign Reader: %s", wkt.c_str());
    reader->ReadHeight(point);
    if (isTrans) {
      int epsg = 32600;
      if (point.getY() < 0) {
        epsg = 32500;
      }
      epsg += point.getX() / 6 + 31;
      height_service::Transformation::Transform(
          height_service::SpatialReference::GetFromEPSG(4326),
          height_service::SpatialReference::GetFromEPSG(epsg), point);
    }
  }
  gpr_log(GPR_INFO, "Result Point (%lf, %lf, %lf).", point.getX(), point.getY(),
          point.getZ());
  return point.exportToWkt();
}

const std::string DemServiceImpl::ReaderLineString(const std::string &wkt,
                                                   bool isTrans) const {
  OGRLineString line;

  const char *str = wkt.c_str();
  OGRErr err = line.importFromWkt((const char **)&str);
  if (err != OGRERR_NONE) {
    throw std::invalid_argument("wkt参数错误");
  }
  {
    std::lock_guard<std::mutex> lock(_mutex);
    line.assignSpatialReference(
        height_service::SpatialReference::GetFromEPSG(4326));
    gpr_log(GPR_INFO, "Beign Reader: %s", wkt.c_str());
    reader->ReadHeight(line);
    // 根据几何质心转换
    if (isTrans) {
      int epsg = 32600;
      OGRPoint point;
      line.Centroid(&point);
      if (point.getY() < 0) {
        epsg = 32500;
      }
      epsg += point.getX() / 6 + 31;
      height_service::Transformation::Transform(
          height_service::SpatialReference::GetFromEPSG(4326),
          height_service::SpatialReference::GetFromEPSG(epsg), line);
    }
  }
  return line.exportToWkt();
}
