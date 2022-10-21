#include "dem_server.hpp"
#include "gdal_priv.h"
#include <memory>

void RunServer() {
  std::string server_address("0.0.0.0:50040");
  DemServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;

  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  gpr_set_log_verbosity(GPR_LOG_SEVERITY_INFO);
  server->Wait();
}

int main(int argc, char **argv) {
  GDALAllRegister();
  if (argc < 2) {
    std::cerr << "Usage dem_service path_to_dem_data [limit_max_read_block]"
              << std::endl;
    return 1;
  }
  if (argc == 2) {
    DemServiceImpl::Init(argv[1]);
  } else {
    DemServiceImpl::Init(argv[1], std::stoi(argv[2]));
  }
  RunServer();
  // 正常情况下不会运行
  DemServiceImpl::DestoryHeightReader();
  return 0;
}
