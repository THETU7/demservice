/*
        Use of this source code is governed by a BSD-style license

        Author: 	 ZongYang
        Date: 		 2022-08-21
        Description: Singletons of OGRSpatialReference
        Version: 	 0.0.1
*/

#ifndef SPATIAL_REFERENCE_H
#define SPATIAL_REFERENCE_H

#include "ogr_spatialref.h"
#include <map>
#include <memory>

namespace height_service {

/**
 * @struct sp_times
 * @brief A RAII Struct And Set Axis Strategy with traditional make 
 * 		the longtitude is first, and latitude is second 
 */
struct sp_times {
  sp_times(int epsg = 4326);
  ~sp_times();
  OGRSpatialReference *sp;
  short times{10};
};

class SpatialReference {
public:
  static OGRSpatialReference *GetFromEPSG(int index);
  static void SPDestroy();

private:
  SpatialReference() = delete;
  SpatialReference(const SpatialReference &) = delete;
  static std::map<int, std::unique_ptr<sp_times>> _sp_map;
};

} // namespace height_service

#endif /* SPATIAL_REFERENCE_H */
