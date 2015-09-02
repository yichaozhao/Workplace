#include "gtest/gtest.h"
#include "Geometries.h"
#include "MathUtils.h"


TEST(SphereTest, constructor)
{
	const double p_x = 0.13232;
	const double p_y = 0.213123;
	const double p_z = 0.2131;
	const double radius = 12312.2;
	Geom::Point3D origin(p_x, p_y, p_z);
	Geom::Sphere sphere(origin, radius);

	EXPECT_EQ(sphere.GetOrigin(), origin);
	EXPECT_TRUE(Math::IsEqual(sphere.GetRadius(), radius));
	
	Geom::Point3D expectedExtentLower(p_x - radius, p_y - radius, p_z - radius);
	Geom::Point3D expectedExtentUpper(p_x + radius, p_y + radius, p_z + radius);
	Geom::GeometryExtent3D expectedExtent(expectedExtentLower, expectedExtentUpper);
	EXPECT_EQ(expectedExtent, sphere.GetGeometryExtent());
}

TEST(SphereTest, equality)
{
	const double p_x = 0.13232;
	const double p_y = 0.213123;
	const double p_z = 0.2131;
	const double radius = 12312.2;
	Geom::Point3D origin(p_x, p_y, p_z);

	Geom::Sphere sphere1(origin, radius);
	Geom::Sphere sphere2(origin, radius);
	EXPECT_EQ(sphere1, sphere2);

	Geom::Sphere sphere3(origin, radius + 0.5);
	EXPECT_NE(sphere1, sphere3);
}
