#pragma once
#include <vector>
#include "Object.h"
#include "GeometryExtent3D.h"
#include "Ray.h"

class Octree
{

private:
	static const int MAX_OBJECT_COUNT = 8;
	static const int OCTREE_CHILD_COUNT = 8; /* Please don't change */

	/*
	* For what it means, See Octree.jpg in References
	*/
	static const int X0Y0Z0 = 0;
	static const int X0Y0Z1 = 1;
	static const int X0Y1Z0 = 2;
	static const int X0Y1Z1 = 3;
	static const int X1Y0Z0 = 4;
	static const int X1Y0Z1 = 5;
	static const int X1Y1Z0 = 6;
	static const int X1Y1Z1 = 7;
	static const int _EXIT_   = OCTREE_CHILD_COUNT;

	// 0 1 2
	static const int BIT_TWO	= 1 << 0; // 1
	static const int BIT_ONE	= 1 << 1; // 2
	static const int BIT_ZERO	= 1 << 2; // 4

	Geom::GeometryExtent3D m_extent;
	int m_level;

	std::vector<Geom::Object*> m_pObjectVector = std::vector<Geom::Object*>(0);
	std::vector<Octree*> m_pOctreeVector = std::vector<Octree*>(0);

	Octree(const Geom::GeometryExtent3D& extent, int level = 0) :
		m_extent(extent),
		m_level(level)
	{}

	void AddObjectIntoSubOctree(Geom::Object* pObject);
	void InitializeChildOctrees();
	void SearchOctree(double tx0, double ty0, double tz0, double tx1, double ty1, double tz1, int bit, std::vector<const Octree*>& resultVector) const;
	int CalculateFirstChildOctree(const Geom::Vector3D& t0, const Geom::Vector3D& tm) const;
	int CalculateNextChildOctree(double x, int indexX, double y, int indexY, double z, int indexZ) const;

public:
	~Octree();

	static void CreateOctree(Octree*& pOctree, std::vector<Geom::Object*>& pObjectVector);
	static void CalculateIntersectingOctrees(const Octree& octree, const Geom::Ray& ray, std::vector<const Octree*>& resultVector);
	void AddObject(Geom::Object* pObject);
	bool IsLeaf() const { return m_pOctreeVector.size() == 0; }
	Octree* GetChildOctree(int index) { return m_pOctreeVector.at(index); }
	const Geom::GeometryExtent3D& GetGeometryExtent() const { return m_extent; }

	/* Debug Usage */
	int DebugCountObject() const;
	bool DebugVolumeChecksum() const;
};