#pragma once
#include "Object.h"
#include "Point3D.h"

namespace Geom
{


class Triangle : public Object
{

private:
	Point3D m_a;
	Point3D m_b;
	Point3D m_c;

public:
	Triangle(Point3D a, Point3D b, Point3D c) :
		m_a(a),
		m_b(b),
		m_c(c)
	{}
	~Triangle() {}

	Point3D& GetPointA() { return m_a; };
	Point3D& GetPointB() { return m_b; };
	Point3D& GetPointC() { return m_c; };

};


}