#include "GeometryExtent3D.h"
#include "MathUtils.h"
#include <assert.h>

namespace Geom
{

GeometryExtent3D::GeometryExtent3D(const Point3D& lower, const Point3D& upper) :
	m_upper(upper),
	m_lower(lower)
{
	assert(Math::IsGreaterEqual(upper.GetX(), lower.GetX()));
	assert(Math::IsGreaterEqual(upper.GetY(), lower.GetY()));
	assert(Math::IsGreaterEqual(upper.GetZ(), lower.GetZ()));
}

bool GeometryExtent3D::operator== (const GeometryExtent3D& extent) const
{
	return m_lower == extent.GetLower() && m_upper == extent.GetUpper();
}

double GeometryExtent3D::CalculateVolume() const
{
	Vector3D vector = m_lower.VectorTo(m_upper);
	return vector.GetX() * vector.GetY() * vector.GetZ();
}

double GeometryExtent3D::GetLengthX() const
{
	return m_upper.GetX() - m_lower.GetX();
}

double GeometryExtent3D::GetLengthY() const
{
	return m_upper.GetY() - m_lower.GetY();
}

double GeometryExtent3D::GetLengthZ() const
{
	return m_upper.GetZ() - m_lower.GetZ();
}


}