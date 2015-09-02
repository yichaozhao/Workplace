#include "Sphere.h"
#include "MathUtils.h"

namespace Geom
{

GeometryExtent3D CalculateGeometryExtent(Point3D origin, double radius)
{
	Point3D upper(origin.GetX() + radius, origin.GetY() + radius, origin.GetZ() + radius);
	Point3D lower(origin.GetX() - radius, origin.GetY() - radius, origin.GetZ() - radius);

	return GeometryExtent3D(lower, upper);
}

Sphere::Sphere(const Point3D& origin, double radius) :
	m_origin(origin),
	m_radius(radius),
	m_extent(CalculateGeometryExtent(origin, radius))
{}

bool Sphere::operator== (const Sphere& sphere) const
{
	return m_origin == sphere.GetOrigin() && Math::IsEqual(m_radius, sphere.GetRadius());
}

}
