#pragma once
#include "gtest/gtest.h"
#include "MathUtils.h"
#include "Geometries.h"


TEST(MathUtilsTest, precision)
{
	EXPECT_EQ(1e-9, Math::PRECISION_DOUBLE);
}

TEST(MathUtilsTest, IsEqual_double)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 100;
	double c = a + Math::PRECISION_DOUBLE/10;
	EXPECT_FALSE(Math::IsEqual(a, b));
	EXPECT_TRUE(Math::IsEqual(a, c));
}

TEST(MathUtilsTest, IsEqual_float)
{
	float a = 1;
	float b = a + Math::PRECISION_FLOAT * 100;
	float c = a + Math::PRECISION_FLOAT/10;
	EXPECT_FALSE(Math::IsEqual(a, b));
	EXPECT_TRUE(Math::IsEqual(a, c));
}

TEST(MathUtilsTest, isLess)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 2;
	double c = a + Math::PRECISION_DOUBLE / 2;
	EXPECT_TRUE(Math::IsLess(a, b));
	EXPECT_FALSE(Math::IsLess(a, c));
}

TEST(MathUtilsTest, isLessEqual)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 2;
	double c = a - Math::PRECISION_DOUBLE * 2;
	double d = a + Math::PRECISION_DOUBLE / 2;
	double e = a - Math::PRECISION_DOUBLE / 2;
	EXPECT_TRUE(Math::IsLessEqual(a, b));
	EXPECT_FALSE(Math::IsLessEqual(a, c));
	EXPECT_TRUE(Math::IsLessEqual(a, d));
	EXPECT_TRUE(Math::IsLessEqual(a, e));
}

TEST(MathUtilsTest, isGreater)
{
	double a = 1;
	double b = a - Math::PRECISION_DOUBLE * 2;
	double c = a - Math::PRECISION_DOUBLE / 2;
	EXPECT_TRUE(Math::IsGreater(a, b));
	EXPECT_FALSE(Math::IsGreater(a, c));
}

TEST(MathUtilsTest, isGreaterEqual)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 2;
	double c = a - Math::PRECISION_DOUBLE * 2;
	double d = a + Math::PRECISION_DOUBLE / 2;
	double e = a - Math::PRECISION_DOUBLE / 2;
	EXPECT_FALSE(Math::IsGreaterEqual(a, b));
	EXPECT_TRUE(Math::IsGreaterEqual(a, c));
	EXPECT_TRUE(Math::IsGreaterEqual(a, d));
	EXPECT_TRUE(Math::IsGreaterEqual(a, d));
}

TEST(MathUtilsTest, CalculateGeometryExtent)
{
	Geom::Point3D p1(2, 8, -1);
	Geom::Point3D p2(1, -3, 2);
	Geom::Point3D p3(5, 2, 10);

	Geom::GeometryExtent3D extent = Math::CalculateGeometryExtent(3, p1, p2, p3);

	EXPECT_TRUE(Math::IsEqual(extent.GetLower().GetX(), 1));
	EXPECT_TRUE(Math::IsEqual(extent.GetUpper().GetX(), 5));

	EXPECT_TRUE(Math::IsEqual(extent.GetLower().GetY(), -3));
	EXPECT_TRUE(Math::IsEqual(extent.GetUpper().GetY(), 8));

	EXPECT_TRUE(Math::IsEqual(extent.GetLower().GetZ(), -1));
	EXPECT_TRUE(Math::IsEqual(extent.GetUpper().GetZ(), 10));
}

TEST(MathUtilsTest, CalculateGeometryExtent2)
{
	Geom::Point3D p_x0y0z0(0, 0, 0);
	Geom::Point3D p_x0y1z0(0, 1, 0);
	Geom::Point3D p_x0y0z1(0, 0, 1);
	Geom::Point3D p_x0y1z1(0, 1, 1);
	Geom::Point3D p_x1y0z0(1, 0, 0);
	Geom::Point3D p_x1y1z0(1, 1, 0);
	Geom::Point3D p_x1y0z1(1, 0, 1);
	Geom::Point3D p_x1y1z1(1, 1, 1);

	Geom::GeometryExtent3D extent1 = Math::CalculateGeometryExtent(2, p_x0y0z0, p_x1y1z1);
	Geom::GeometryExtent3D extent2 = Math::CalculateGeometryExtent(2, p_x0y1z0, p_x1y0z1);
	Geom::GeometryExtent3D extent3 = Math::CalculateGeometryExtent(2, p_x0y0z1, p_x1y1z0);
	Geom::GeometryExtent3D extent4 = Math::CalculateGeometryExtent(2, p_x0y1z1, p_x1y0z0);
	Geom::GeometryExtent3D expectedExtent = Geom::GeometryExtent3D(Geom::Point3D(0, 0, 0), Geom::Point3D(1, 1, 1));

	EXPECT_EQ(extent1, expectedExtent);
	EXPECT_EQ(extent2, expectedExtent);
	EXPECT_EQ(extent3, expectedExtent);
	EXPECT_EQ(extent4, expectedExtent);
}

TEST(MathUtilsTest, CalculateGeometryExtentFromObjects)
{
	Geom::Sphere sphere1(Geom::Point3D(0, 0, 0), 2);
	Geom::Sphere sphere2(Geom::Point3D(0, 0, 0), 3);
	Geom::Sphere sphere3(Geom::Point3D(10, 10, 10), 2);

	Geom::GeometryExtent3D expectedExtent(Geom::Point3D(-3, -3, -3), Geom::Point3D(12, 12, 12));
	EXPECT_EQ(Math::CalculateGeometryExtentFromObjects({&sphere1, &sphere2, &sphere3}), expectedExtent);
}

TEST(MathUtilsTest, IsTwoExtentsIntersecting)
{
	Geom::Point3D p1(1, 1, 1);
	Geom::Point3D p2(2, 2, 2);
	Geom::Point3D p3(3, 3, 3);
	Geom::Point3D p4(4, 4, 4);

	Geom::GeometryExtent3D e12(p1, p2);
	Geom::GeometryExtent3D e34(p3, p4);

	EXPECT_FALSE(Math::IsTwoExtentsIntersecting(e12, e34));

	Geom::GeometryExtent3D e23(p2, p3);
	EXPECT_TRUE(Math::IsTwoExtentsIntersecting(e12, e23));
	EXPECT_TRUE(Math::IsTwoExtentsIntersecting(e23, e12));

	Geom::GeometryExtent3D e13(p1, p3);
	Geom::GeometryExtent3D e24(p2, p4);
	EXPECT_TRUE(Math::IsTwoExtentsIntersecting(e13, e24));
	EXPECT_TRUE(Math::IsTwoExtentsIntersecting(e24, e13));
}