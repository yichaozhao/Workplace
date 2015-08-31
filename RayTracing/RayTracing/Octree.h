#pragma once
#include <vector>
#include "Object.h"
#include "GeometryExtent3D.h"



class Octree
{

private:
	static const int MAX_OBJECT_COUNT = 8;
	static const int OCTREE_CHILD_COUNT = 8;

	/*
	* For what it means, See Octree.jpg in References
	*/
	static const int X0Y0Z0 = 0;
	static const int X0Y1Z0 = 1;
	static const int X0Y0Z1 = 2;
	static const int X0Y1Z1 = 3;
	static const int X1Y0Z0 = 4;
	static const int X1Y1Z0 = 5;
	static const int X1Y0Z1 = 6;
	static const int X1Y1Z1 = 7;

	Geom::GeometryExtent3D m_extent;
	std::vector<Octree*> m_pOctreeVector = std::vector<Octree*>(0);
	std::vector<Geom::Object*> m_pObjectVector;

	Octree(Geom::GeometryExtent3D extent) :
		m_extent(extent)
	{}

	void AddObject(Geom::Object* pObject);
	void AddObjectIntoSubOctree(Geom::Object* pObject);

public:
	~Octree() {}

	static void CreateOctree(Octree*& pOctree, std::vector<Geom::Object*> pObjectVector);

};