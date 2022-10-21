add_library(dem raster_dataset.cc raster_band.cc band_reader.cc spatial_reference.cc transformation.cc height_reader.cc dem_server.cc)
target_link_libraries(dem PUBLIC GDAL::GDAL)
