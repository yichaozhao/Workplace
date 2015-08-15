#pragma once
#include "Point3D.h"

namespace Utils
{


class Ray
{

private:
	Point3D m_origin;
	Point3D m_direction;

public:
	Ray(Point3D origin, Point3D direction) :
		m_origin(origin),
		m_direction(direction)
	{}

	~Ray() {}
};


}