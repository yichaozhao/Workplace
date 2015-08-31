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

	virtual const GeometryExtent3D& GetGeometryExtent3D() const override { return m_extent; }

	const Point3D& GetPointA() const { return m_a; };
	const Point3D& GetPointB() const { return m_b; };
	const Point3D& GetPointC() const { return m_c; };

	bool operator== (const Triangle& triangle) const;
	bool operator!= (const Triangle& triangle) const { return !operator==(triangle); }
};


}