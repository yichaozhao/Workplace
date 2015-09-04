#pragma once
#include "GeometryExtent3D.h"
#include "Point3D.h"
#include "Object.h"

namespace Geom
{


class Dot : public Object, public Point3D
{

private:
	GeometryExtent3D m_extent;

public:
	Dot(double x, double y, double z) :
		Point3D(x, y, z),
		m_extent(GeometryExtent3D(Point3D(x, y, z), Point3D(x, y, z)))
	{}

	~Dot() {}

	virtual const GeometryExtent3D& GetGeometryExtent() const override { return m_extent; }
	virtual std::string toString() const override;
};


}