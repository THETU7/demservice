#include "band_reader.hpp"
#include "raster_band.hpp"
#include "spatial_reference.hpp"
#include "transformation.hpp"
#include <cmath>
#include <iostream>
//#include <ogr_geometry.h>

height_service::BandReader::BandReader(const std::shared_ptr<RasterBand> band)
    : _band(band) {
  band->Get().GetBlockSize(&_nXClipCounts, &_nYClipCounts);
  _nXPx = band->Get().GetXSize();
  _nYPx = band->Get().GetYSize();
}

height_service::BandReader::~BandReader() {}

void height_service::BandReader::Read(OGRPoint &point) const {
  double x, y;
  x = point.getX();
  y = point.getY();
  point.setZ(_band->Get().GetNoDataValue());
  double trans[6];
  _band->Get().GetDataset()->GetGeoTransform(trans);
  int longtitude = std::round(trans[0]);
  int latitude = std::round(trans[3]);
  // printf("Orgin(%lf, %lf)\n", trans[0], trans[3]);
  if (y <= latitude - 1 || y > latitude) {
    return;
  } else if (x < longtitude || x > longtitude + 1) {
    return;
  }

  int xPx, yPx;
  yPx = (_nXPx - 1) * (latitude - y);
  xPx = (_nYPx - 1) * (x - longtitude);
  PixPoint px(xPx, yPx);
  // printf("PixPoint: %d, %d\n", xPx, yPx);
  Read(px);
  // printf("Coord(%lf, %lf) Height: %lf\n", x, y, px.z);
  point.setZ(px.z);
}

void height_service::BandReader::Read(OGRLineString &line) const {
  for (auto &it : line) {
    Read(it);
  }
}

void height_service::BandReader::Read(PixPoint &point) const {
  point.z = _band->Get().GetNoDataValue();
  if (point.x >= _nXPx || point.y >= _nYPx) {
    return;
  }
  PixPoint block_point = Pix2BlockCoord(point);
  GDALDataType type = _band->Get().GetRasterDataType();
  GDALRasterBlock *block =
      _band->Get().GetLockedBlockRef(block_point.x, block_point.y);
  GInt16 *data = (GInt16 *)block->GetDataRef();
  int nXoffice, nYoffice;

  nXoffice = point.x % _nXClipCounts;
  nYoffice = point.y % _nYClipCounts;

  double z = AccessDataByType(nXoffice, nYoffice, data);
  block->DropLock();
  point.z = z;
}

void height_service::BandReader::Read(PixLineString &line) const {
  for (auto &it : line) {
    Read(it);
  }
}

const height_service::PixPoint
height_service::BandReader::Pix2BlockCoord(const PixPoint &point) const {
  return PixPoint(point.x / _nXClipCounts, point.y / _nYClipCounts);
}

double height_service::BandReader::AccessDataByType(int nXOffice, int nYOffice,
                                                    void *data) const {
  GDALDataType type = _band->Get().GetRasterDataType();
  double result = _band->Get().GetNoDataValue();
  switch (type) {
  case GDT_Byte: {
    GByte *read_buf = (GByte *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_Unknown:
    break;
  case GDT_UInt16: {
    GUInt16 *read_buf = (GUInt16 *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_CInt16:
  case GDT_Int16: {
    GInt16 *read_buf = (GInt16 *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_UInt32: {
    GUInt32 *read_buf = (GUInt32 *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_CInt32:
  case GDT_Int32: {
    GInt32 *read_buf = (GInt32 *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_UInt64: {
    GUInt64 *read_buf = (GUInt64 *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_Int64: {
    GInt64 *read_buf = (GInt64 *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_CFloat32:
  case GDT_Float32: {
    float *read_buf = (float *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_CFloat64:
  case GDT_Float64: {
    double *read_buf = (double *)data;
    result = static_cast<double>(read_buf[nXOffice + nYOffice * _nXPx]);
    break;
  }
  case GDT_TypeCount:
    break;
  }
  return result;
}
