#pragma once
#include "gtest/gtest.h"
#include "MathUtils.h"
#include "Point3D.h"


TEST(MathUtilsTest, precision)
{
	EXPECT_EQ(1e-9, Math::PRECISION_DOUBLE);
}

TEST(MathUtilsTest, IsEqual)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 100;
	double c = a + Math::PRECISION_DOUBLE/10;
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

	EXPECT_TRUE(Math::IsEqual(extent.GetLower().getX(), 1));
	EXPECT_TRUE(Math::IsEqual(extent.GetUpper().getX(), 5));

	EXPECT_TRUE(Math::IsEqual(extent.GetLower().getY(), -3));
	EXPECT_TRUE(Math::IsEqual(extent.GetUpper().getY(), 8));

	EXPECT_TRUE(Math::IsEqual(extent.GetLower().getZ(), -1));
	EXPECT_TRUE(Math::IsEqual(extent.GetUpper().getZ(), 10));
}

TEST(MathUtilsTest, HasIntersection)
{
	Geom::Point3D p1(1, 1, 1);
	Geom::Point3D p2(2, 2, 2);
	Geom::Point3D p3(3, 3, 3);
	Geom::Point3D p4(4, 4, 4);

	Geom::GeometryExtent3D e12(p1, p2);
	Geom::GeometryExtent3D e34(p3, p4);

	EXPECT_FALSE(Math::HasIntersection(e12, e34));

	Geom::GeometryExtent3D e23(p2, p3);
	EXPECT_TRUE(Math::HasIntersection(e12, e23));
	EXPECT_TRUE(Math::HasIntersection(e23, e12));

	Geom::GeometryExtent3D e13(p1, p3);
	Geom::GeometryExtent3D e24(p2, p4);
	EXPECT_TRUE(Math::HasIntersection(e13, e24));
	EXPECT_TRUE(Math::HasIntersection(e24, e13));
}