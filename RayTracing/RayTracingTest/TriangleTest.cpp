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

	EXPECT_EQ(p_a.getX(), p_a_x);
	EXPECT_EQ(p_a.getY(), p_a_y);
	EXPECT_EQ(p_a.getZ(), p_a_z);

	EXPECT_EQ(p_b.getX(), p_b_x);
	EXPECT_EQ(p_b.getY(), p_b_y);
	EXPECT_EQ(p_b.getZ(), p_b_z);

	EXPECT_EQ(p_c.getX(), p_c_x);
	EXPECT_EQ(p_c.getY(), p_c_y);
	EXPECT_EQ(p_c.getZ(), p_c_z);
}

