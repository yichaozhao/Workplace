#pragma once
#include "gtest/gtest.h"
#include "Geometries.h"
#include "MathUtils.h"


TEST(TriangleTest, constructor)
{
	double p_a_x = 0, p_a_y = 1, p_a_z = 2;
	double p_b_x = 3, p_b_y = 4, p_b_z = 5;
	double p_c_x = 6, p_c_y = 7, p_c_z = 8;
	Geom::Point3D p_a(p_a_x, p_a_y, p_a_z);
	Geom::Point3D p_b(p_b_x, p_b_y, p_b_z);
	Geom::Point3D p_c(p_c_x, p_c_y, p_c_z);

	Geom::Triangle triangle(p_a, p_b, p_c);

	EXPECT_EQ(triangle.GetPointA().getX(), p_a_x);
	EXPECT_EQ(triangle.GetPointA().getY(), p_a_y);
	EXPECT_EQ(triangle.GetPointA().getZ(), p_a_z);

	EXPECT_EQ(triangle.GetPointB().getX(), p_b_x);
	EXPECT_EQ(triangle.GetPointB().getY(), p_b_y);
	EXPECT_EQ(triangle.GetPointB().getZ(), p_b_z);

	EXPECT_EQ(triangle.GetPointC().getX(), p_c_x);
	EXPECT_EQ(triangle.GetPointC().getY(), p_c_y);
	EXPECT_EQ(triangle.GetPointC().getZ(), p_c_z);

	EXPECT_EQ(triangle.GetGeometryExtent3D().GetLower().getX(), 0);
	EXPECT_EQ(triangle.GetGeometryExtent3D().GetUpper().getX(), 6);

	EXPECT_EQ(triangle.GetGeometryExtent3D().GetLower().getY(), 1);
	EXPECT_EQ(triangle.GetGeometryExtent3D().GetUpper().getY(), 7);

	EXPECT_EQ(triangle.GetGeometryExtent3D().GetLower().getZ(), 2);
	EXPECT_EQ(triangle.GetGeometryExtent3D().GetUpper().getZ(), 8);
}

