#include "gtest/gtest.h"
#include "Geometries.h"
#include "MathUtils.h"


TEST(Vector3DTest, constructor)
{
	Geom::Vector3D vector(0.13232, 0.2131, 0.32423);
	EXPECT_EQ(vector.GetX(), 0.13232);
	EXPECT_EQ(vector.GetY(), 0.2131);
	EXPECT_EQ(vector.GetZ(), 0.32423);
}

TEST(Vector3DTest, equality)
{
	double x = 0.112312;
	double y = 1.123123;
	double z = 2.24312321;

	Geom::Vector3D v1(x, y, z);
	Geom::Vector3D v2(x + Math::PRECISION_DOUBLE / 2, y + Math::PRECISION_DOUBLE / 2, z + Math::PRECISION_DOUBLE / 2);
	EXPECT_EQ(v1, v2);

	Geom::Vector3D v3(x + Math::PRECISION_DOUBLE * 2, y + Math::PRECISION_DOUBLE / 2, z + Math::PRECISION_DOUBLE / 2);
	EXPECT_NE(v1, v3);
}

TEST(Vector3DTest, negative)
{
	double x = 0.31529;
	double y = 0.76236;
	double z = 0.24495;
	Geom::Vector3D vector(x, y, z);
	EXPECT_EQ(-vector, Geom::Vector3D(-x, -y, -z));
}

TEST(Vector3DTest, plus_minus)
{
	double x1 = 0.31529;
	double y1 = 0.76236;
	double z1 = 0.24495;
	double x2 = 0.21552;
	double y2 = 0.33258;
	double z2 = 0.46381;

	Geom::Vector3D v1(x1, y1, z1);
	Geom::Vector3D v2(x2, y2, z2);
	EXPECT_EQ(v1 + v2, Geom::Vector3D(x1 + x2, y1 + y2, z1 + z2));
	EXPECT_EQ(v2 + v1, Geom::Vector3D(x1 + x2, y1 + y2, z1 + z2));
	EXPECT_EQ(v1 - v2, Geom::Vector3D(x1 - x2, y1 - y2, z1 - z2));
	EXPECT_EQ(v2 - v1, Geom::Vector3D(x2 - x1, y2 - y1, z2 - z1));
}

TEST(Vector3DTest, multiply_divide)
{
	double x = 0.04339;
	double y = 0.33489;
	double z = 0.49184;
	double coeff = 0.87210;
	Geom::Vector3D vector(x, y, z);

	EXPECT_EQ(vector * coeff, Geom::Vector3D(x * coeff, y * coeff, z * coeff));
	EXPECT_EQ(vector / coeff, Geom::Vector3D(x / coeff, y / coeff, z / coeff));
}

TEST(Vector3DTest, divide_by_zero)
{
	Geom::Vector3D vector(1, 1, 1);
	double coeff = 0;
	EXPECT_DEATH(vector / coeff, "a");
}

TEST(Vector3DTest, dot_product)
{
	double x1 = 0.91;
	double y1 = 0.74;
	double z1 = 0.12;
	double x2 = 0.81;
	double y2 = 0.83;
	double z2 = 0.64;
	Geom::Vector3D v1(x1, y1, z1);
	Geom::Vector3D v2(x2, y2, z2);

	EXPECT_TRUE(Math::IsEqual(v1.Dot(v2), x1 * x2 + y1 * y2 + z1 * z2));
	EXPECT_TRUE(Math::IsEqual(v2.Dot(v1), x1 * x2 + y1 * y2 + z1 * z2));
}

TEST(Vector3DTest, cross_product)
{
	double x1 = 0.91;
	double y1 = 0.74;
	double z1 = 0.12;
	double x2 = 0.81;
	double y2 = 0.83;
	double z2 = 0.64;
	Geom::Vector3D v1(x1, y1, z1);
	Geom::Vector3D v2(x2, y2, z2);

	EXPECT_EQ(v1.Cross(v2), Geom::Vector3D(0.374, -0.4852, 0.1559));
	EXPECT_EQ(v2.Cross(v1), Geom::Vector3D(-0.374, 0.4852, -0.1559));
}

TEST(Vector3DTest, length)
{
	double x = 1;
	double y = 2;
	double z = 3;
	Geom::Vector3D vector(x, y, z);
	EXPECT_TRUE(Math::IsEqual(vector.CalculateLength(), std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2))));
}

TEST(Vector3DTest, normalize)
{
	double x = 1;
	double y = 2;
	double z = 3;
	double base = std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
	Geom::Vector3D vector(x, y, z);
	Geom::Vector3D expectedNormalizedVector(x / base, y / base, z / base);
	EXPECT_EQ(vector.Normalize(), expectedNormalizedVector);
}