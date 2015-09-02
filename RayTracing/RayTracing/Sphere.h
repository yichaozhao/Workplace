#pragma once
#include "Object.h"
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

	virtual const GeometryExtent3D& GetGeometryExtent() const override { return m_extent; }

	const Point3D& GetOrigin() const { return m_origin; }
	double GetRadius() const { return m_radius; }

	bool operator== (const Sphere& sphere) const;
	bool operator!= (const Sphere& sphere) const { return !operator==(sphere); }
};


}