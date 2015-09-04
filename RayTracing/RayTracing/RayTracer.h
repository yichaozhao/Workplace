#pragma once
#include <vector>
#include "Color.h"

class Octree;

class RayTracer
{

private:
	const Octree& m_octree;

public:
	RayTracer(const Octree& octree) :
		m_octree(octree)
	{}
	~RayTracer() {}

	void GeneratePicture(std::vector<std::vector<const Color>>& colorMatrix);
};