# DEMService

dem 高程服务，通过本地搭建的 dem 文件系统通过 gdal 进行读取，并通过 grpc 发布服务

## Usage

```bash
# demservice [path to dem directory] [缓冲区块大小]
dem_service /data/srtm90/data/ 10
```

## Build

使用 [vcpkg](https://vcpkg.io/en/getting-started.html) 进行包管理，依赖于 `vcpkg`

```
cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
cmake --build [build directory]
```
