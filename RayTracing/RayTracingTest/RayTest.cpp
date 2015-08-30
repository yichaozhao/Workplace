#pragma once
#include "gtest/gtest.h"
#include "Geometries.h"
#include "MathUtils.h"


TEST(RayTest, constructor)
{
	double origin_x = 0, origin_y = 1, origin_z = 2;
	double direction_x = 3, direction_y = 4, direction_z = 5;

	Geom::Point3D origin(origin_x, origin_y, origin_z);
	Geom::Point3D direction(direction_x, direction_y, direction_z);

	Geom::Ray ray(origin, direction);

	EXPECT_EQ(origin.getX(), origin_x);
	EXPECT_EQ(origin.getY(), origin_y);
	EXPECT_EQ(origin.getZ(), origin_z);

	EXPECT_EQ(direction.getX(), direction_x);
	EXPECT_EQ(direction.getY(), direction_y);
	EXPECT_EQ(direction.getZ(), direction_z);
}

