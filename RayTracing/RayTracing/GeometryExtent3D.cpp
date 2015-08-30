#include "GeometryExtent3D.h"
#include "MathUtils.h"
#include <assert.h>

namespace Geom
{

GeometryExtent3D::GeometryExtent3D(Point3D upper, Point3D lower) :
	m_upper(upper),
	m_lower(lower)
{
	assert(Math::isGreaterEqual(upper.getX(), lower.getX()));
	assert(Math::isGreaterEqual(upper.getY(), lower.getY()));
	assert(Math::isGreaterEqual(upper.getZ(), lower.getZ()));
}

}