#include "gtest/gtest.h"
#include "Geometries.h"
#include "MathUtils.h"

TEST(DotTest, constructor)
{
	double x = 0.123123;
	double y = 0.23123;
	double z = 0.564234;
	Geom::Dot dot(x, y, z);
	EXPECT_EQ(dot.GetX(), x);
	EXPECT_EQ(dot.GetY(), y);
	EXPECT_EQ(dot.GetZ(), z);

	EXPECT_EQ(dot.GetGeometryExtent(), Geom::GeometryExtent3D(Geom::Point3D(x, y, z), Geom::Point3D(x, y, z)));

	Geom::Object* pObject = &dot;
	
	EXPECT_EQ(pObject->GetGeometryExtent(), Geom::GeometryExtent3D(Geom::Point3D(x, y, z), Geom::Point3D(x, y, z)));
	int a = 0;
}