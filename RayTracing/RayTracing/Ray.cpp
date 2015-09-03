#include "Ray.h"

namespace Geom
{

Ray::Ray(const Point3D& origin, const Vector3D& direction) :
	m_origin(origin),
	m_direction(direction)
{
	m_direction.Normalize();
}

bool Ray::operator== (const Ray& ray) const
{
	return m_direction == ray.GetDirection() && m_origin == ray.GetOrigin();
}

}