cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
PROJECT(demservice VERSION 0.1)

SET(CMAKE_CXX_FLAG "-O2 ${CMAKE_CXX_FLAG}")

find_package(GDAL CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(PROJ CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR} )

add_subdirectory(src)
add_subdirectory(proto)
add_subdirectory(include)
add_subdirectory(test)

#find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
#message("find_program ${_GRPC_CPP_PLUGIN_EXECUTABLE}")

#get_filename_component(hw_proto "./proto/helloworld.proto" ABSOLUTE)
#get_filename_component(hw_proto_path "${hw_proto}" PATH)

#set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pd.cc")
#set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pd.h")
#set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.cc")
#set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.h")

add_library(proto proto/dem_service.pb.cc proto/dem_service.grpc.pb.cc)
target_link_libraries(proto PUBLIC gRPC::grpc++ gRPC::grpc++_reflection protobuf::libprotobuf )

foreach(_target dem_service)
	add_executable(${_target} "src/${_target}.cc")
	target_link_libraries(${_target} PRIVATE
		dem proto PROJ::proj)
#gRPC::grpc gRPC::gpr gRPC::upb  gRPC::grpc++ gRPC::grpc++_reflection protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite
#PRIVATE 
#GDAL::GDAL
endforeach()
