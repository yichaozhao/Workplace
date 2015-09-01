#include "Color.h"
#include <assert.h>
#include "MathUtils.h"

Color::Color(float red, float green, float blue, float alpha) :
	m_red(red),
	m_green(green),
	m_blue(blue),
	m_alpha(alpha)
{
	assert(Math::IsGreaterEqual(red, 0) && Math::IsLessEqual(red, 1));
	assert(Math::IsGreaterEqual(green, 0) && Math::IsLessEqual(green, 1));
	assert(Math::IsGreaterEqual(blue, 0) && Math::IsLessEqual(blue, 1));
	assert(Math::IsGreaterEqual(alpha, 0) && Math::IsLessEqual(alpha, 1));
}

bool Color::operator== (const Color& color) const
{
	return
		Math::IsEqual(m_red, color.GetRed()) &&
		Math::IsEqual(m_green, color.GetGreen()) &&
		Math::IsEqual(m_blue, color.GetBlue()) &&
		Math::IsEqual(m_alpha, color.GetAlpha());
}