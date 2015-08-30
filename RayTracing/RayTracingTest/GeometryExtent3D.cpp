#include "gtest\gtest.h"
#include "Geometries.h"
#include "MathUtils.h"

TEST(GeometryExtent3DTest, constructor)
{
	double lower_x = 1, lower_y = 2, lower_z = 3;
	double upper_x = 4, upper_y = 5, upper_z = 6;

	Geom::Point3D upper(upper_x, upper_y, upper_z);
	Geom::Point3D lower(lower_x, lower_y, lower_z);

	Geom::GeometryExtent3D extent(upper, lower);

	EXPECT_TRUE(Math::isEqual(extent.GetUpper().getX(), upper_x));
	EXPECT_TRUE(Math::isEqual(extent.GetUpper().getY(), upper_y));
	EXPECT_TRUE(Math::isEqual(extent.GetUpper().getZ(), upper_z));

	EXPECT_TRUE(Math::isEqual(extent.GetLower().getX(), lower_x));
	EXPECT_TRUE(Math::isEqual(extent.GetLower().getY(), lower_y));
	EXPECT_TRUE(Math::isEqual(extent.GetLower().getZ(), lower_z));
}

TEST(GeometryExtent3DTest, constructor_assert)
{
	Geom::Point3D upper(0, 0, 0);
	Geom::Point3D lower(1, 1, 1);

	EXPECT_DEATH(Geom::GeometryExtent3D(upper, lower), "1");
	
}