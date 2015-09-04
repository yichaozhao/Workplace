#include "gtest\gtest.h"
#include "Geometries.h"
#include "MathUtils.h"

TEST(PlaneTest, constructor)
{
	Geom::Point3D p(0, 0, 0);
	Geom::Point3D q(1, 0, 0);
	Geom::Point3D r(0, 1, 1);
	Geom::Point3D s(1, 1, 1);
	Geom::Plane plane(p, q, r, s);

	EXPECT_EQ(plane.GetPointP(), p);
	EXPECT_EQ(plane.GetPointQ(), q);
	EXPECT_EQ(plane.GetPointR(), r);
	EXPECT_EQ(plane.GetPointS(), s);
	EXPECT_EQ(plane.GetGeometryExtent(), Math::CalculateGeometryExtent(4, &p, &q, &r, &s));
}

TEST(PlaneTest, constructor_assert)
{
	Geom::Point3D p(0, 0, 0);
	Geom::Point3D q(1, 0, 0);
	Geom::Point3D r(0, 1, 1);
	Geom::Point3D s(1, 1, 2);
	EXPECT_DEATH(Geom::Plane plane(p, q, r, s), "a");
}

TEST(PlaneTest, equality)
{
	Geom::Point3D p(0, 0, 0);
	Geom::Point3D q(1, 0, 0);
	Geom::Point3D r(0, 1, 1);
	Geom::Point3D s(1, 1, 1);
	Geom::Point3D s_(2, 2, 2);

	Geom::Plane plane1(p, q, r, s);
	Geom::Plane plane2(p, q, r, s);
	Geom::Plane plane_(p, q, r, s_);

	EXPECT_EQ(plane1, plane2);
	EXPECT_NE(plane1, plane_);
}