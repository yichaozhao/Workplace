#pragma once

namespace Geom
{


class Point3D
{

private:
	double m_x;
	double m_y;
	double m_z;

public:
	Point3D(double x, double y, double z) :
		m_x(x),
		m_y(y),
		m_z(z)
	{}

	~Point3D() {}

	double getX() const { return m_x; }
	double getY() const { return m_y; }
	double getZ() const { return m_z; }

	bool operator== (const Point3D& point3D) const;
	bool operator!= (const Point3D& point3D) const { return !operator==(point3D); }
};


}
