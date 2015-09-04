#pragma once
#include "Object.h"
#include "Point3D.h"
#include "GeometryExtent3D.h"

namespace Geom
{

class Plane : public Object
{

private:
	Point3D m_p;
	Point3D m_q;
	Point3D m_r;
	Point3D m_s;
	GeometryExtent3D m_extent;

	bool IsFourPointOnSamePlane(const Point3D& p, const Point3D& q, const Point3D& r, const Point3D& s);

public:
	Plane(const Point3D& p, const Point3D& q, const Point3D& r, const Point3D& s);
	~Plane() {}

	const Point3D& GetPointP() const { return m_p; }
	const Point3D& GetPointQ() const { return m_q; }
	const Point3D& GetPointR() const { return m_r; }
	const Point3D& GetPointS() const { return m_s; }

	virtual const GeometryExtent3D& GetGeometryExtent() const override { return m_extent; }
	bool operator== (const Plane& plane) const;
	bool operator!= (const Plane& plane) const { return !operator==(plane); }
};

}