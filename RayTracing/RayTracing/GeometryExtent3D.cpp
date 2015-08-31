#include "GeometryExtent3D.h"
#include "MathUtils.h"
#include <assert.h>

namespace Geom
{

GeometryExtent3D::GeometryExtent3D(Point3D lower, Point3D upper) :
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

}