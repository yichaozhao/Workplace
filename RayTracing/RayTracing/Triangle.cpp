#include "Triangle.h"
#include "MathUtils.h"


namespace Geom
{

Triangle::Triangle(Point3D a, Point3D b, Point3D c) :
	m_a(a),
	m_b(b),
	m_c(c),
	m_extent(Math::CalculateGeometryExtent(3, a, b, c))
{
}

bool Triangle::operator== (const Triangle& triangle) const
{
	return m_a == triangle.GetPointA() && m_b == triangle.GetPointB() && m_c == triangle.GetPointC();
}

}