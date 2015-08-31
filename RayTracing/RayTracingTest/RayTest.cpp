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

	EXPECT_EQ(ray.GetOrigin(), origin);
	EXPECT_EQ(ray.GetDirection(), direction);
}

TEST(RayTest, equality)
{
	Geom::Point3D origin(0, 0, 0);
	Geom::Point3D direction(1, 1, 1);

	Geom::Ray ray1(origin, direction);
	Geom::Ray ray2(origin, direction);
	EXPECT_EQ(ray1, ray2);

	Geom::Ray ray3(origin, origin);
	EXPECT_NE(ray1, ray3);
}

