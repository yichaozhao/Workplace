#pragma once
#include "Object.h"
#include "Point3D.h"

namespace Utils
{


class Sphere : public Object
{

private:
	Point3D m_origin;
	double m_radius;

public:
	Sphere(Point3D origin, double radius) :
		m_origin(origin),
		m_radius(radius)
	{}
	~Sphere() {}

	Point3D& GetOrigin() { return m_origin; }
};


}