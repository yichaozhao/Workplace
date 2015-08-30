#pragma once
#include "Point3D.h"

namespace Geom
{

class GeometryExtent3D
{

private:
	Point3D m_upper;
	Point3D m_lower;

public:
	GeometryExtent3D(Point3D upper, Point3D lower);
	~GeometryExtent3D() {}

	Point3D& GetUpper() { return m_upper; }
	Point3D& GetLower() { return m_lower; }

};


}