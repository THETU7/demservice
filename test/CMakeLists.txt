include(FetchContent)

FetchContent_Declare(
	googletest 
	URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
	)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
	raster_dataset_test
	raster_dataset_test.cc)

target_link_libraries(
	raster_dataset_test
	gtest_main
	dem
	gRPC::grpc++
)

include(GoogleTest)
gtest_discover_tests(raster_dataset_test)
