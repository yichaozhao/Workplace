#include "Ray.h"

namespace Geom
{

bool Ray::operator== (const Ray& ray) const
{
	return m_direction == ray.GetDirection() && m_origin == ray.GetOrigin();
}

}