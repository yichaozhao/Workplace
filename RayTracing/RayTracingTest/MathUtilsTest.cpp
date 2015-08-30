#pragma once
#include "gtest/gtest.h"
#include "MathUtils.h"
#include "Point3D.h"


TEST(MathUtilsTest, precision)
{
	EXPECT_EQ(1e-9, Math::PRECISION_DOUBLE);
}

TEST(MathUtilsTest, isEqual)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 100;
	double c = a + Math::PRECISION_DOUBLE/10;
	EXPECT_FALSE(Math::isEqual(a, b));
	EXPECT_TRUE(Math::isEqual(a, c));
}

TEST(MathUtilsTest, isLess)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 2;
	double c = a + Math::PRECISION_DOUBLE / 2;
	EXPECT_TRUE(Math::isLess(a, b));
	EXPECT_FALSE(Math::isLess(a, c));
}

TEST(MathUtilsTest, isLessEqual)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 2;
	double c = a - Math::PRECISION_DOUBLE * 2;
	double d = a + Math::PRECISION_DOUBLE / 2;
	double e = a - Math::PRECISION_DOUBLE / 2;
	EXPECT_TRUE(Math::isLessEqual(a, b));
	EXPECT_FALSE(Math::isLessEqual(a, c));
	EXPECT_TRUE(Math::isLessEqual(a, d));
	EXPECT_TRUE(Math::isLessEqual(a, e));
}

TEST(MathUtilsTest, isGreater)
{
	double a = 1;
	double b = a - Math::PRECISION_DOUBLE * 2;
	double c = a - Math::PRECISION_DOUBLE / 2;
	EXPECT_TRUE(Math::isGreater(a, b));
	EXPECT_FALSE(Math::isGreater(a, c));
}

TEST(MathUtilsTest, isGreaterEqual)
{
	double a = 1;
	double b = a + Math::PRECISION_DOUBLE * 2;
	double c = a - Math::PRECISION_DOUBLE * 2;
	double d = a + Math::PRECISION_DOUBLE / 2;
	double e = a - Math::PRECISION_DOUBLE / 2;
	EXPECT_FALSE(Math::isGreaterEqual(a, b));
	EXPECT_TRUE(Math::isGreaterEqual(a, c));
	EXPECT_TRUE(Math::isGreaterEqual(a, d));
	EXPECT_TRUE(Math::isGreaterEqual(a, d));
}

TEST(MathUtilsTest, CalculateGeometryExtent)
{
	Geom::Point3D p1(2, 8, -1);
	Geom::Point3D p2(1, -3, 2);
	Geom::Point3D p3(5, 2, 10);

	Geom::GeometryExtent3D extent = Math::CalculateGeometryExtent(3, p1, p2, p3);

	EXPECT_TRUE(Math::isEqual(extent.GetLower().getX(), 1));
	EXPECT_TRUE(Math::isEqual(extent.GetUpper().getX(), 5));

	EXPECT_TRUE(Math::isEqual(extent.GetLower().getY(), -3));
	EXPECT_TRUE(Math::isEqual(extent.GetUpper().getY(), 8));

	EXPECT_TRUE(Math::isEqual(extent.GetLower().getZ(), -1));
	EXPECT_TRUE(Math::isEqual(extent.GetUpper().getZ(), 10));
}