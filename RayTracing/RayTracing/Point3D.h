#pragma once
#include "Vector3D.h"
#include "Object.h"

namespace Geom
{


class Point3D
{

private:
	const double m_x;
	const double m_y;
	const double m_z;

public:
	Point3D(double x, double y, double z) :
		m_x(x),
		m_y(y),
		m_z(z)
	{}

	~Point3D() {}

	double GetX() const { return m_x; }
	double GetY() const { return m_y; }
	double GetZ() const { return m_z; }

	bool operator== (const Point3D& point) const;
	bool operator!= (const Point3D& point) const { return !operator==(point); }
	Point3D operator+ (const Vector3D& vector) const;
	Point3D operator- (const Vector3D& vector) const;

	Vector3D VectorTo(const Point3D& point) const;
};


}
