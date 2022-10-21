/*
        Use of this source code is governed by a BSD-style license

        Author: 	 ZongYang
        Date: 		 2022-08-21
        Description: RAII Class For RasterBand
        Version: 	 0.0.1
*/

#ifndef RASTER_BAND_H
#define RASTER_BAND_H

#include <memory>

class GDALRasterBand;

namespace height_service {
class RasterDataset;

class RasterBand {
public:
  RasterBand(std::shared_ptr<RasterDataset> dataset);
  RasterBand(const RasterBand &) = delete;
  // RasterBand(const RasterBand &&) = delete;
  ~RasterBand(){};

  GDALRasterBand &Get() const { return *_band; }

private:
  // 保证dataset不被提前释放
  std::shared_ptr<RasterDataset> _dataset;
  GDALRasterBand *_band;
};

} // namespace height_service

#endif /* RASTER_BAND_H */
