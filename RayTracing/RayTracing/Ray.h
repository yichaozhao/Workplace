#pragma once
#include "Point3D.h"
#include "Vector3D.h"

namespace Geom
{


class Ray
{

private:
	Point3D m_origin;
	Vector3D m_direction;

public:
	Ray(const Point3D& origin, const Vector3D& direction) :
		m_origin(origin),
		m_direction(direction)
	{}
	~Ray() {}

	const Point3D& GetOrigin() const { return m_origin; };
	const Vector3D& GetDirection() const { return m_direction; }

	bool operator== (const Ray& ray) const;
	bool operator!= (const Ray& ray) const { return !operator==(ray); }
};


}