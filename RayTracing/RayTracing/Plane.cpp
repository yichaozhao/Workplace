#include "Plane.h"
#include "MathUtils.h"
#include <assert.h>
#include "Vector3D.h"

namespace Geom
{

Plane::Plane(const Point3D& p, const Point3D& q, const Point3D& r, const Point3D& s) :
	m_p(p),
	m_q(q),
	m_r(r),
	m_s(s),
	m_extent(Math::CalculateGeometryExtent(4, &m_p, &m_q, &m_r, &m_s))
{
	assert(IsFourPointOnSamePlane(p, q, r, s));
}

bool Plane::operator== (const Plane& plane) const
{
	return
		m_p == plane.GetPointP() &&
		m_q == plane.GetPointQ() &&
		m_r == plane.GetPointR() &&
		m_s == plane.GetPointS();
}

bool Plane::IsFourPointOnSamePlane(const Point3D& p, const Point3D& q, const Point3D& r, const Point3D& s)
{
	Geom::Vector3D p_q = p.VectorTo(q);
	Geom::Vector3D p_r = p.VectorTo(r);
	Geom::Vector3D p_s = p.VectorTo(s);

	return Math::IsEqual(p_s.Dot(p_q.Cross(p_r)), 0);
}

}
