#include "gtest/gtest.h"
#include "Geometries.h"
#include "MathUtils.h"


TEST(Point3DTest, constructor)
{
	Geom::Point3D point(0.13232, 0.2131, 0.32423);
	EXPECT_EQ(point.getX(), 0.13232);
	EXPECT_EQ(point.getY(), 0.2131);
	EXPECT_EQ(point.getZ(), 0.32423);
}

TEST(Point3DTest, equality)
{
	double x = 0.112312;
	double y = 1.123123;
	double z = 2.24312321;

	Geom::Point3D p1(x, y, z);
	Geom::Point3D p2(x + Math::PRECISION_DOUBLE / 2, y + Math::PRECISION_DOUBLE / 2, z + Math::PRECISION_DOUBLE / 2);
	EXPECT_EQ(p1, p2);

	Geom::Point3D p3(x + Math::PRECISION_DOUBLE * 2, y + Math::PRECISION_DOUBLE / 2, z + Math::PRECISION_DOUBLE / 2);
	EXPECT_NE(p1, p3);
}
