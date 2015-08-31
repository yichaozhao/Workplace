#include "gtest\gtest.h"
#include "Geometries.h"
#include "MathUtils.h"

TEST(GeometryExtent3DTest, constructor)
{
	double lower_x = 1, lower_y = 2, lower_z = 3;
	double upper_x = 4, upper_y = 5, upper_z = 6;

	Geom::Point3D upper(upper_x, upper_y, upper_z);
	Geom::Point3D lower(lower_x, lower_y, lower_z);

	Geom::GeometryExtent3D extent(lower, upper);

	EXPECT_EQ(extent.GetLower(), lower);
	EXPECT_EQ(extent.GetUpper(), upper);
}

TEST(GeometryExtent3DTest, constructor_assert)
{
	Geom::Point3D upper(0, 0, 0);
	Geom::Point3D lower(1, 1, 1);

	EXPECT_DEATH(Geom::GeometryExtent3D(lower, upper), "1");
}

TEST(GeometryExtent3DTest, equality)
{
	Geom::Point3D lower(0, 0, 0);
	Geom::Point3D upper(1, 1, 1);

	Geom::GeometryExtent3D extent1(lower, upper);
	Geom::GeometryExtent3D extent2(lower, upper);
	EXPECT_EQ(extent1, extent2);

	Geom::GeometryExtent3D extent3(lower, lower);
	EXPECT_NE(extent1, extent3);
}