/*
        Use of this source code is governed by a BSD-style license

        Author: 	 ZongYang
        Date: 		 2022-08-23
        Description: Class For Read Height By Latitude And Longtitude
        Version: 	 0.0.1
*/

#ifndef HEIGHT_READER_H
#define HEIGHT_READER_H

#include "band_reader.hpp"
#include "gdal_priv.h"
#include "raster_dataset.hpp"
#include <functional>
#include <map>

namespace height_service {

struct lat_long {
  // 经度在前，纬度在后
  explicit lat_long(short longtitude, short latitude)
      : longtitude(longtitude), latitude(latitude) {}
  short longtitude;
  short latitude;
};

bool operator<(const lat_long &lhs, const lat_long &rhs);

using HRFormatFunc = std::function<const std::string(const lat_long &)>;

const std::string HRDefaultFormatFunc(const lat_long &);

class HeightReader {
public:
  HeightReader(const std::string &path, int maxSize = INT_MAX,
               HRFormatFunc format = HRDefaultFormatFunc)
      : _path(path), _format(format), _max_size(maxSize){};
  HeightReader(const HeightReader &) = delete;
  ~HeightReader(){};
  void ReadHeight(OGRPoint &);
  void ReadHeight(OGRLineString &);

private:
  std::map<lat_long, std::shared_ptr<BandReader>> _map;
  std::string _path;
  // 用于确定目标的组织格式，默认为 "${longtitude}/${latitude}.tiff"
  HRFormatFunc _format;
  const int _max_size;
};

} // namespace height_service

#endif /* HEIGHT_READER_H */
