/*
        Use of this source code is governed by a BSD-style license

        Author: 	 ZongYang
        Date: 		 2022-08-21
        Description: RAII Class For Read Data with raster band.
        Version: 	 0.0.1
*/

#ifndef BAND_READER_H
#define BAND_READER_H

#include "gdal_priv.h"
#include "raster_band.hpp"
#include <memory>
#include <vector>

class OGRLineString;
class OGRPoint;

namespace height_service {
// 这里指简单直角像素坐标系，不指定坐标系
// x 表示经度方向， y表示纬度方向
struct PixPoint {
  PixPoint(size_t x, size_t y) : x(x), y(y) {}
  PixPoint(size_t x, size_t y, double z) : x(x), y(y), z(z) {}
  size_t x;
  size_t y;
  double z;
};
using PixLineString = std::vector<PixPoint>;

/**
 * @class BandReader
 * @brief A Class For Read Band, Can Generate by RasterDataset
 *
 */
class BandReader {
public:
  BandReader(const std::shared_ptr<RasterBand> band);
  ~BandReader();

  /**
   * @brief Read Height by a OGRPoint
   *
   * @param point need have SpatialReference
   */
  void Read(OGRPoint &point) const;
  void Read(OGRLineString &line) const;
  void Read(PixPoint &point) const;
  void Read(PixLineString &line) const;

private:
  const PixPoint Pix2BlockCoord(const PixPoint &) const;

  // 按照 band 的DATATYPE解析data,并将坐标处的值转换为double返回,
  // 如果不存在该类型，则返回NODATA大小的数据
  double AccessDataByType(int nXOffice, int nYOffice, void *data) const;

  const std::shared_ptr<RasterBand> _band;
  int _nXPx;
  int _nYPx;
  int _nXClipCounts;
  int _nYClipCounts;
};

} // namespace height_service

#endif /* BAND_READER_H */
