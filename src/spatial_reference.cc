#include "spatial_reference.hpp"
#include <iostream>

std::map<int, std::unique_ptr<height_service::sp_times>>
    height_service::SpatialReference::_sp_map{};

OGRSpatialReference *height_service::SpatialReference::GetFromEPSG(int index) {
  for (auto it = _sp_map.begin(); it != _sp_map.end(); it++) {
    it->second->times--;

    if (it->second->times == 0 && it->second->sp->GetReferenceCount() == 1) {
      if (it->second->sp->GetEPSGGeogCS() != index) {
        it = _sp_map.erase(it);
        it--;
      }
    }
  }
  const auto &it = _sp_map.find(index);
  if (it != _sp_map.end()) {
    it->second->times++;
    return it->second->sp;
  }

  _sp_map[index] = std::make_unique<sp_times>(index);
  if (_sp_map[index]->sp == nullptr) {
    _sp_map.erase(index);
    return nullptr;
  }
  return _sp_map[index]->sp;
}

height_service::sp_times::sp_times(int epsg) {
  sp = new OGRSpatialReference();
  if (sp == nullptr) {
    std::cerr << "内存分配失败\n";
    return;
  }
  /* 设置坐标顺序为经度在前，纬度在后 */
  sp->SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
  OGRErr err = sp->importFromEPSG(epsg);
  if (err != OGRERR_NONE) {
    std::cerr << "不存在该坐标\n";
  }
}

height_service::sp_times::~sp_times() {
  if (sp != nullptr) {
    // std::cout << "DestroySpatialReference:" << sp->GetName() << std::endl;
    // delete sp;
    OGRSpatialReference::DestroySpatialReference(sp);
  }
}

void height_service::SpatialReference::SPDestroy() { _sp_map.clear(); }
