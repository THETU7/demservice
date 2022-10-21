/*
        Use of this source code is governed by a BSD-style license

        Author: 	 ZongYang
        Date: 		 2022-08-21
        Description: Rall Class for GDALDataset
        Version: 	 0.0.1
*/

#ifndef RASTER_DATASET_H
#define RASTER_DATASET_H

#include "dem_priv.hpp"
#include "gdal_priv.h"
#include <memory>
#include <string>

namespace height_service {

class RasterDataset {
public:
  RasterDataset(const std::string &path);
  RasterDataset(const RasterDataset &) = delete;
  RasterDataset(const RasterDataset &&) = delete;
  ~RasterDataset();

  // 通过路径获取目标波段的 Reader对象
  static std::shared_ptr<BandReader> GetBandReader(const std::string &path,
                                                   int index = 1);

  inline GDALDataset &Get() const { return *_dataset; };

private:
  GDALDataset *_dataset;
};

} // namespace height_service

#endif /* RASTER_DATASET_H */
