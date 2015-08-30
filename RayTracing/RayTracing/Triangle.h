#pragma once
#include "Object.h"
#include "Point3D.h"
#include "GeometryExtent3D.h"


namespace Geom
{

class GeometryExtent3D;

class Triangle : public Object
{

private:
	Point3D m_a;
	Point3D m_b;
	Point3D m_c;
	GeometryExtent3D m_extent;

public:
	Triangle(Point3D a, Point3D b, Point3D c);
	~Triangle() {}

	virtual GeometryExtent3D& GetGeometryExtent3D() override { return m_extent; }

	Point3D& GetPointA() { return m_a; };
	Point3D& GetPointB() { return m_b; };
	Point3D& GetPointC() { return m_c; };

};


}