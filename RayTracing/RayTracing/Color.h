#pragma once

class Color
{

private:
	float m_red = 0;		// [0, 1] red
	float m_green = 0;	// [0, 1] green
	float m_blue = 0;		// [0, 1] blue
	float m_alpha = 1;	// [0, 1] alpha

public:
	Color() {}
	Color(float red, float green, float blue, float alpha = 1);
	~Color() {}

	float GetRed() const { return m_red; }
	float GetGreen() const { return m_green; }
	float GetBlue() const { return m_blue; }
	float GetAlpha() const { return m_alpha; }

	bool operator== (const Color& color) const;
	bool operator!= (const Color& color) const { return !operator==(color); }
};