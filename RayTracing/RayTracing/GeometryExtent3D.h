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

	const Point3D& GetUpper() const { return m_upper; }
	const Point3D& GetLower() const { return m_lower; }
	double GetLengthX() const;
	double GetLengthY() const;
	double GetLengthZ() const;
	double CalculateVolume() const;

	bool operator== (const GeometryExtent3D& extent) const;
	bool operator!= (const GeometryExtent3D& extent) const { return !operator==(extent); }
};


}