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

	EXPECT_EQ(triangle.GetPointA(), p_a);
	EXPECT_EQ(triangle.GetPointB(), p_b);
	EXPECT_EQ(triangle.GetPointC(), p_c);

	Geom::Point3D expectedExtentLower(0, 1, 2);
	Geom::Point3D expectedExtentUpper(6, 7, 8);
	Geom::GeometryExtent3D expectedExtent(expectedExtentLower, expectedExtentUpper);
	EXPECT_EQ(expectedExtent, triangle.GetGeometryExtent());
}

TEST(TriangleTest, equality)
{
	double p_a_x = 0, p_a_y = 1, p_a_z = 2;
	double p_b_x = 3, p_b_y = 4, p_b_z = 5;
	double p_c_x = 6, p_c_y = 7, p_c_z = 8;
	Geom::Point3D p_a(p_a_x, p_a_y, p_a_z);
	Geom::Point3D p_b(p_b_x, p_b_y, p_b_z);
	Geom::Point3D p_c(p_c_x, p_c_y, p_c_z);

	Geom::Triangle triangle1(p_a, p_b, p_c);
	Geom::Triangle triangle2(p_a, p_b, p_c);
	EXPECT_EQ(triangle1, triangle2);

	Geom::Triangle triangle3(p_a, p_b, p_b);
	EXPECT_NE(triangle1, triangle3);
}