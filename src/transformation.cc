#include "transformation.hpp"

height_service::Transformation::Transformation(OGRSpatialReference *from,
                                               OGRSpatialReference *to) {
  _transf = OGRCreateCoordinateTransformation(from, to);
}

height_service::Transformation::~Transformation() {
  if (_transf != nullptr) {
    delete _transf;
  }
}

OGRErr height_service::Transformation::Transform(OGRSpatialReference *from,
                                                 OGRSpatialReference *to,
                                                 OGRGeometry &geom) {
  Transformation trans(from, to);
  return geom.transform(trans.Get());
}
