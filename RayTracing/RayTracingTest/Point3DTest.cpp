#include "gtest/gtest.h"
#include "Geometries.h"
#include "MathUtils.h"


TEST(Point3DTest, constructor)
{
	Geom::Point3D point(0.13232, 0.2131, 0.32423);
	EXPECT_EQ(point.GetX(), 0.13232);
	EXPECT_EQ(point.GetY(), 0.2131);
	EXPECT_EQ(point.GetZ(), 0.32423);
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

TEST(Point3DTest, plus_minus_vector)
{
	double x1 = 0.55882;
	double y1 = 0.57185;
	double z1 = 0.02132;
	double x2 = 0.57178;
	double y2 = 0.83132;
	double z2 = 0.54242;

	Geom::Point3D point(x1, y1, z1);
	Geom::Vector3D vector(x2, y2, z2);

	EXPECT_EQ(point + vector, Geom::Point3D(x1 + x2, y1 + y2, z1 + z2));
	EXPECT_EQ(point - vector, Geom::Point3D(x1 - x2, y1 - y2, z1 - z2));
}

TEST(Point3DTest, vectorToPoint)
{
	double x1 = 0.55882;
	double y1 = 0.57185;
	double z1 = 0.02132;
	double x2 = 0.57178;
	double y2 = 0.83132;
	double z2 = 0.54242;

	Geom::Point3D point1(x1, y1, z1);
	Geom::Point3D point2(x2, y2, z2);

	EXPECT_EQ(point1.VectorTo(point2), Geom::Vector3D(x2 - x1, y2 - y1, z2 - z1));
	EXPECT_EQ(point2.VectorTo(point1), Geom::Vector3D(x1 - x2, y1 - y2, z1 - z2));
}