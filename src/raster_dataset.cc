#include "raster_dataset.hpp"
#include "band_reader.hpp"
#include "gdal_priv.h"

height_service::RasterDataset::RasterDataset(const std::string &path) {
  _dataset = (GDALDataset *)GDALOpen(path.c_str(), GA_ReadOnly);
  if (nullptr == _dataset) {
    throw std::invalid_argument("文件不存在");
  }
}

height_service::RasterDataset::~RasterDataset() { GDALClose(_dataset); }

std::shared_ptr<height_service::BandReader>
height_service::RasterDataset::GetBandReader(const std::string &path,
                                             int index) {
  std::shared_ptr<RasterDataset> dataset =
      std::make_shared<RasterDataset>(path);

  std::shared_ptr<RasterBand> band = std::make_shared<RasterBand>(dataset);

  std::shared_ptr<BandReader> reader = std::make_shared<BandReader>(band);
  return reader;
}
