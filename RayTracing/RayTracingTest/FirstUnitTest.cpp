#include "gtest/gtest.h"
#include "Point3D.h"
#include "Sphere.h"


namespace Utils
{


TEST(testStack, simpleTest)
{
	Point3D p(0.0, 0.0, 0.0);
	Sphere s(p, 3.0);
	EXPECT_EQ(s.GetOrigin().getX(), 0.0);
}


}
