#include "height_reader.hpp"
#include "spatial_reference.hpp"
#include "transformation.hpp"
#include <cmath>
#include <grpc/support/log.h>
#include <iostream>
#include <sstream>

bool height_service::operator<(const lat_long &lhs, const lat_long &rhs) {

  if (lhs.latitude < rhs.latitude) {
    return true;
  } else if (lhs.latitude == rhs.latitude) {
    if (lhs.longtitude < rhs.longtitude) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

/* 后续须将此改为支持windows:  <23-08-22, ZongYang> */
const std::string height_service::HRDefaultFormatFunc(const lat_long &pos) {
  std::stringstream ss;
  ss << (pos.longtitude + 180) / 30 << "/" << pos.longtitude << "/"
     << pos.latitude << ".tiff";
  return ss.str();
}

void height_service::HeightReader::ReadHeight(OGRPoint &point) {
  OGRPoint point_copy = point;
  OGRSpatialReference *sp = point_copy.getSpatialReference();
  if (sp == nullptr) {
    return;
  }

  if (sp->GetEPSGGeogCS() != 4326) {
    OGRErr err = Transformation::Transform(
        sp, SpatialReference::GetFromEPSG(4326), point_copy);
    if (err != OGRERR_NONE) {
      return;
    }
  }

  // 默认起始点位于左上角，须将y坐标向上取整
  lat_long pos(point_copy.getX(), std::ceil(point_copy.getY()));
  int xPx, yPx;

  const auto &find = _map.find(pos);
  if (find != _map.end()) {
    find->second->Read(point_copy);
  } else {
    // 如果大于最大内存，则进行清空
    if (_map.size() > _max_size) {
      _map.clear();
    }
    std::string path = _path + _format(pos);
    std::shared_ptr<BandReader> reader = RasterDataset::GetBandReader(path);
    _map[pos] = reader;
    gpr_log(GPR_INFO, "Open File %s", path.c_str());
    reader->Read(point_copy);
  }
  point.setZ(point_copy.getZ());
}

void height_service::HeightReader::ReadHeight(OGRLineString &line) {
  for (int i = 0; i < line.getNumPoints(); ++i) {
    OGRPoint point;
    point.assignSpatialReference(SpatialReference::GetFromEPSG(4326));
    line.getPoint(i, &point);
    ReadHeight(point);
    line.setZ(i, point.getZ());
  }
  /* for (auto it = line.begin(); it != line.end(); ++it) {
    ReadHeight((*it));
  } */
  /* for (auto &point : line) {
    point.assignSpatialReference(SpatialReference::GetFromEPSG(4326));
    ReadHeight(point);
  } */
}
