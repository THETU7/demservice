#include "raster_band.hpp"
#include "gdal_priv.h"
#include "raster_dataset.hpp"

height_service::RasterBand::RasterBand(std::shared_ptr<RasterDataset> dataset)
    : _dataset(dataset) {
  if (_dataset->Get().GetRasterXSize() < 0) {
    std::domain_error("band size < 1");
  }
  _band = _dataset->Get().GetRasterBand(1);
}
