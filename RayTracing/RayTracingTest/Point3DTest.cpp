#include "gtest/gtest.h"
#include "Point3D.h"


TEST(Point3DTest, constructor)
{
	Geom::Point3D point(0.13232, 0.2131, 0.32423);
	EXPECT_EQ(point.getX(), 0.13232);
	EXPECT_EQ(point.getY(), 0.2131);
	EXPECT_EQ(point.getZ(), 0.32423);
}

