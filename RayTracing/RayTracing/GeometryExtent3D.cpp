#include "GeometryExtent3D.h"
#include "MathUtils.h"
#include <assert.h>

namespace Geom
{

GeometryExtent3D::GeometryExtent3D(Point3D lower, Point3D upper) :
	m_upper(upper),
	m_lower(lower)
{
	assert(Math::IsGreaterEqual(upper.getX(), lower.getX()));
	assert(Math::IsGreaterEqual(upper.getY(), lower.getY()));
	assert(Math::IsGreaterEqual(upper.getZ(), lower.getZ()));
}

}