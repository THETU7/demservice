/*
        Use of this source code is governed by a BSD-style license

        Author: 	 ZongYang
        Date: 		 2022-08-22
        Description: RAII Class for OGRCoordinateTransformation
        Version: 	 0.0.1
*/

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "gdal_priv.h"

namespace height_service {

class Transformation {
public:
  explicit Transformation(OGRSpatialReference *, OGRSpatialReference *);
  Transformation(const Transformation &) = delete;
  ~Transformation();

  static OGRErr Transform(OGRSpatialReference *from, OGRSpatialReference *to,
                          OGRGeometry &geom);
  OGRCoordinateTransformation *Get() { return _transf; }

private:
  OGRCoordinateTransformation *_transf;
};

} // namespace height_service

#endif /* TRANSFORMATION_H */
