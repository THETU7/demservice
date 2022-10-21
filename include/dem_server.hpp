#ifndef DEM_SERVER
#define DEM_SERVER

#include "gdal_priv.h"
#include "height_reader.hpp"
#include "proto/dem_service.grpc.pb.h"
#include "proto/dem_service.pb.h"
#include "spatial_reference.hpp"
#include <grpc/support/log.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/status_code_enum.h>
#include <regex>

using dem_service::Heighter;

class DemServiceImpl final : public Heighter::Service {
  grpc::Status GetHeight(grpc::ServerContext *context,
                         const dem_service::GetHeightRequest *request,
                         dem_service::GetHeightReply *reply) override;

public:
  const std::string ReaderPoint(const std::string &wkt, bool isTrans) const;
  const std::string ReaderLineString(const std::string &wkt,
                                     bool isTrans) const;
  const std::string Read(const std::string &wkt, bool isTrans) const;
  static void Init(const std::string &path, int limitBlock = INT_MAX);
  static void DestoryHeightReader();

private:
  static height_service::HeightReader *reader;
  static std::mutex _mutex;
};

#endif // !DEM_SERVCE
