#include "Point3D.h"
#include "MathUtils.h"

namespace Geom
{

bool Point3D::operator== (const Point3D& point3D) const
{
	return
		Math::IsEqual(m_x, point3D.GetX()) &&
		Math::IsEqual(m_y, point3D.GetY()) &&
		Math::IsEqual(m_z, point3D.GetZ());
}

}