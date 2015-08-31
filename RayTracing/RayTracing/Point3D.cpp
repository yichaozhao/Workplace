#include "Point3D.h"
#include "MathUtils.h"

namespace Geom
{

bool Point3D::operator== (const Point3D& point) const
{
	return
		Math::IsEqual(m_x, point.GetX()) &&
		Math::IsEqual(m_y, point.GetY()) &&
		Math::IsEqual(m_z, point.GetZ());
}

Point3D Point3D::operator+ (const Vector3D& vector) const
{
	return Point3D(m_x + vector.GetX(), m_y + vector.GetY(), m_z + vector.GetZ());
}

Point3D Point3D::operator- (const Vector3D& vector) const
{
	return Point3D(m_x - vector.GetX(), m_y - vector.GetY(), m_z - vector.GetZ());
}

Vector3D Point3D::VectorTo(const Point3D& point) const
{
	return Vector3D(point.GetX() - m_x, point.GetY() - m_y, point.GetZ() - m_z);
}

}