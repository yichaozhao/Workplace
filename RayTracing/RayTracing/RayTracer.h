#pragma once
#include <vector>
#include "Color.h"
#include "Point3D.h"

class Octree;

class RayTracer
{

private:
	const Octree& m_octree;
	Geom::Point3D m_eyePosition = Geom::Point3D(0, 0, 0);
public:
	RayTracer(const Octree& octree) :
		m_octree(octree)
	{}
	~RayTracer() {}

	void SetEyePosition(Geom::Point3D point) { m_eyePosition = point; }

	void RayTrace(std::vector<std::vector<const Color>>& colorMatrix);
};