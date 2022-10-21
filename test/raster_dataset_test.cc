#include "band_reader.hpp"
#include "gdal_priv.h"
#include "height_reader.hpp"
#include "raster_band.hpp"
#include "raster_dataset.hpp"
#include "spatial_reference.hpp"
#include "transformation.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace height_service;

TEST(TESTRASTERDATASET, FUNCTIONTEST) {
  GDALRegister_GTiff();
  const std::string path = "/data/srtm90/data/8/60/29.tiff";
  ASSERT_NO_THROW(RasterDataset("/data/srtm90/data/8/60/29.tiff"));
  ASSERT_THROW(std::make_shared<RasterDataset>("test.tiff"),
               std::invalid_argument);
  std::shared_ptr<RasterDataset> dem = std::make_shared<RasterDataset>(path);
  ASSERT_NE(dem, nullptr);
  ASSERT_NO_THROW(dem->Get().GetRasterCount());

  std::shared_ptr<RasterBand> band = std::make_shared<RasterBand>(dem);
  ASSERT_NE(band, nullptr);
  ASSERT_NO_THROW(band->Get());

  std::unique_ptr<BandReader> reader = std::make_unique<BandReader>(band);
  ASSERT_NE(reader, nullptr);
  OGRSpatialReference wgs;
  OGRPoint point(13, 22);
  auto err = wgs.importFromEPSG(4326);
  if (err != OGRERR_NONE) {
    std::cerr << err << std::endl;
  }
  // point.assignSpatialReference(&wgs);
  // reader->Read(point);

  // ASSERT_THROW(RasterDataset("test"), std::invalid_argument);
}

TEST(TESTSP, TESTGET) {
  OGRSpatialReference *sp2 = SpatialReference::GetFromEPSG(4326);
  ASSERT_NE(sp2, nullptr);

  EXPECT_STREQ(sp2->GetName(), "WGS 84");

  OGRPoint point(13, 22);
  // point.assignSpatialReference(sp2);
  OGRSpatialReference *sp = SpatialReference::GetFromEPSG(4491);
  ASSERT_NE(sp, nullptr);
  // Transformation::Transform(sp2, sp, point);
  // std::cout << "X:" << point.getX() << ", Y:" << point.getY() << std::endl;
  for (int i = 0; i < 10; i++) {
    sp = SpatialReference::GetFromEPSG(4326);
    ASSERT_NE(sp, nullptr);
  }
  OGRPoint point2;
  OGRSpatialReference *sp3 = SpatialReference::GetFromEPSG(4326);
  sp3->SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
  point2.assignSpatialReference(sp3);
  std::string test = "POINT(91.37703888888888 41.55848611111111)";
  const char *wkt = test.c_str();
  point2.importFromWkt((const char **)&wkt);
  EXPECT_EQ(point2.getX(), 91.37703888888888);
  EXPECT_EQ(point2.getY(), 41.55848611111111);
  Transformation::Transform(sp3, SpatialReference::GetFromEPSG(4491), point2);
  std::cout << "X:" << point2.getX() << ", Y:" << point2.getY() << std::endl;
}

TEST(TESTREADER, READGEOM) {
  std::shared_ptr<RasterDataset> dataset =
      std::make_shared<RasterDataset>("/data/srtm90/data/8/60/30.tiff");

  std::shared_ptr<RasterBand> band = std::make_shared<RasterBand>(dataset);

  BandReader reader(band);
  PixPoint point(0, 0);
  reader.Read(point);
  EXPECT_EQ(point.z, 1488);
  PixPoint point2(1198, 1198);
  reader.Read(point2);
  EXPECT_EQ(point2.z, 1902);
  PixPoint point3(1198, 1);
  reader.Read(point3);
  EXPECT_EQ(point3.z, 518);
  PixPoint point4(347, 235);
  reader.Read(point4);
  EXPECT_EQ(point4.z, 1492);
}

TEST(TESTHEIGHTREADER, FUNCTIONTEST) {
  HeightReader reader("/data/srtm90/data/");
  OGRPoint point(60, 30);
  point.assignSpatialReference(SpatialReference::GetFromEPSG(4326));
  reader.ReadHeight(point);
  EXPECT_EQ(point.getZ(), 1488);
  OGRPoint point2(60.1, 30);
  point2.assignSpatialReference(SpatialReference::GetFromEPSG(4326));
  reader.ReadHeight(point2);
  EXPECT_EQ(point2.getZ(), 1735);
  OGRPoint point3(60, 29.8);
  point3.assignSpatialReference(SpatialReference::GetFromEPSG(4326));
  reader.ReadHeight(point3);
  EXPECT_EQ(point3.getZ(), 1323);
  OGRPoint point4(60, 29.3);
  point4.assignSpatialReference(SpatialReference::GetFromEPSG(4326));
  reader.ReadHeight(point4);
  std::cout << "Nums of Point Dim:" << point4.getDimension() << std::endl;
}

TEST(TESTREADER, TESTLINE) {
  HeightReader reader("/data/srtm90/data/");
  OGRLineString line;
  line.assignSpatialReference(SpatialReference::GetFromEPSG(4326));
  const char *str =
      "LINESTRING(86.37644869918307 41.55706383994678,86.36768460315534 "
      "41.54469765749401,86.35778264819183 41.533620023029,86.3577148643886 "
      "41.53355190500478,86.34817720368873 41.52368817225186,86.33729502839756 "
      "41.51065996113326)";
  line.importFromWkt((const char **)&str);
  reader.ReadHeight(line);
  for (auto &point : line) {
    printf("Point(%lf, %lf, %lf)\n", point.getX(), point.getY(), point.getZ());
  }
  std::cout << line.exportToWkt() << std::endl;
}
