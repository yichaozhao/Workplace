#pragma once
#include "Object.h"
#include "Point3D.h"
#include "GeometryExtent3D.h"

namespace Geom
{


class Sphere : public Object
{

private:
	Point3D m_origin;
	double m_radius;
	GeometryExtent3D m_extent;

public:
	Sphere(Point3D origin, double radius);
	~Sphere() {}

	virtual GeometryExtent3D& GetGeometryExtent3D() override { return m_extent; }

	Point3D& GetOrigin() { return m_origin; }
	double GetRadius() { return m_radius; }

};


}