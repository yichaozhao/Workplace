#include "gtest/gtest.h"
#include "Color.h"
#include "MathUtils.h"

TEST(ColorTest, constructor)
{
	float red = 0.12f;
	float green = 0.42f;
	float blue = 0.643f;
	float alpha = 0.3f;

	Color color(red, green, blue, alpha);
	EXPECT_TRUE(Math::IsEqual(color.GetRed(), red));
	EXPECT_TRUE(Math::IsEqual(color.GetGreen(), green));
	EXPECT_TRUE(Math::IsEqual(color.GetBlue(), blue));
	EXPECT_TRUE(Math::IsEqual(color.GetAlpha(), alpha));

	Color colorDefaultAlpha(red, green, blue);
	EXPECT_TRUE(Math::IsEqual(colorDefaultAlpha.GetAlpha(), 1));

	Color colorAllDefault;
	EXPECT_TRUE(Math::IsEqual(colorAllDefault.GetRed(), 0));
	EXPECT_TRUE(Math::IsEqual(colorAllDefault.GetGreen(), 0));
	EXPECT_TRUE(Math::IsEqual(colorAllDefault.GetBlue(), 0));
	EXPECT_TRUE(Math::IsEqual(colorAllDefault.GetAlpha(), 1));
}

TEST(ColorTest, invalid_color)
{
	EXPECT_DEATH(Color color(-0.5, 0.5, 0.5, 0.5), "a");
}

TEST(ColorTest, equality)
{
	float red = 0.12f;
	float green = 0.42f;
	float blue = 0.643f;
	float alpha = 0.3f;

	Color color(red, green, blue, alpha);
	EXPECT_EQ(color, Color(red, green, blue, alpha));
	EXPECT_NE(color, Color(red, 0, 0, 0));
}