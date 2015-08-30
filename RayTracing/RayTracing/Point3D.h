#pragma once

namespace Geom
{


class Point3D
{

private:
	double m_x = 0.0;
	double m_y = 0.0;
	double m_z = 0.0;

public:
	Point3D(double x, double y, double z) :
		m_x(x),
		m_y(y),
		m_z(z)
	{}

	~Point3D() {}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

};


}
