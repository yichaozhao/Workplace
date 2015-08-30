#include "gtest/gtest.h"
#include "Geometries.h"
#include "MathUtils.h"


TEST(SphereTest, constructor)
{
	const double p_x = 0.13232;
	const double p_y = 0.213123;
	const double p_z = 0.2131;
	const double radius = 12312.2;
	Geom::Point3D point(p_x, p_y, p_z);
	Geom::Sphere sphere(point, radius);

	EXPECT_TRUE(Math::isEqual(sphere.GetOrigin().getX(), p_x));
	EXPECT_TRUE(Math::isEqual(sphere.GetOrigin().getY(), p_y));
	EXPECT_TRUE(Math::isEqual(sphere.GetOrigin().getZ(), p_z));
	EXPECT_TRUE(Math::isEqual(sphere.GetRadius(), radius));

	EXPECT_TRUE(Math::isEqual(sphere.GetGeometryExtent3D().GetUpper().getX(), p_x + radius));
	EXPECT_TRUE(Math::isEqual(sphere.GetGeometryExtent3D().GetLower().getX(), p_x - radius));

	EXPECT_TRUE(Math::isEqual(sphere.GetGeometryExtent3D().GetUpper().getY(), p_y + radius));
	EXPECT_TRUE(Math::isEqual(sphere.GetGeometryExtent3D().GetLower().getY(), p_y - radius));

	EXPECT_TRUE(Math::isEqual(sphere.GetGeometryExtent3D().GetUpper().getZ(), p_z + radius));
	EXPECT_TRUE(Math::isEqual(sphere.GetGeometryExtent3D().GetLower().getZ(), p_z - radius));
}

