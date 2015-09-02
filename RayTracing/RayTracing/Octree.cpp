#include "Octree.h"
#include <assert.h>
#include "MathUtils.h"
#include "Utils.h"

void Octree::CreateOctree(Octree*& pOctree, std::vector<Geom::Object*>& pObjectVector)
{
	pOctree = new Octree(Math::CalculateGeometryExtentFromObjects(pObjectVector));
	for (const auto& pObject : pObjectVector)
	{
		pOctree->AddObject(pObject);
	}
}

Octree::~Octree()
{
	if (m_pOctreeVector.size() != 0)
	{
		for (const auto& pOctree : m_pOctreeVector)
			delete pOctree;
	}

	DebugW(L"deleting octree, level = " + std::to_wstring(m_level) + L" with " + std::to_wstring(m_pObjectVector.size()) + L" object\n");

	if (m_pObjectVector.size() != 0)
		m_pObjectVector.clear();
}

void Octree::AddObject(Geom::Object* pObject)
{
	assert(pObject);
	if (m_pOctreeVector.size() == 0)
	{
		if (m_pObjectVector.size() < MAX_OBJECT_COUNT)
		{
			// put it in the object vector, if still have room
			m_pObjectVector.emplace_back(pObject);
		}
		else
		{
			// max count reached, need to divide octree
			InitializeChildOctrees();

			// add existing objects
			for (const auto& pExistingObject : m_pObjectVector)
			{
				AddObjectIntoSubOctree(pExistingObject);
			}

			// add new object
			AddObjectIntoSubOctree(pObject);

			// clear current object vector
			m_pObjectVector.clear();
		}
	}
	else
	{
		// add new object
		AddObjectIntoSubOctree(pObject);
	}
}

void Octree::InitializeChildOctrees()
{
	// should only split once, when object reach max count
	assert(m_pOctreeVector.size() == 0);
	assert(m_pObjectVector.size() == MAX_OBJECT_COUNT);

	// resize child octree vector
	m_pOctreeVector.resize(OCTREE_CHILD_COUNT);

	// initialize each child octree with corresponding extent
	// center
	const Geom::Point3D& lower = m_extent.GetLower();
	const Geom::Point3D& upper = m_extent.GetUpper();
	const Geom::Vector3D vector = lower.VectorTo(upper);

	// calculate 8 point of the cube, which will be joint with center point individually to calculate
	// extent for each child octree
	Geom::Point3D p_x0y0z0 = lower + Geom::Vector3D(0,				0,				0				);
	Geom::Point3D p_x0y1z0 = lower + Geom::Vector3D(0,				vector.GetY(),	0				);
	Geom::Point3D p_x0y0z1 = lower + Geom::Vector3D(0,				0,				vector.GetZ()	);
	Geom::Point3D p_x0y1z1 = lower + Geom::Vector3D(0,				vector.GetY(),	vector.GetZ()	);
	Geom::Point3D p_x1y0z0 = lower + Geom::Vector3D(vector.GetX(),	0,				0				);
	Geom::Point3D p_x1y1z0 = lower + Geom::Vector3D(vector.GetX(),	vector.GetY(),	0				);
	Geom::Point3D p_x1y0z1 = lower + Geom::Vector3D(vector.GetX(),	0,				vector.GetZ()	);
	Geom::Point3D p_x1y1z1 = lower + Geom::Vector3D(vector.GetX(),	vector.GetY(),	vector.GetZ()	);

	// initialize child octrees
	const int extentPointCount = 2;
	const Geom::Point3D center = lower + vector * 0.5 /* Half */;
	m_pOctreeVector[X0Y0Z0] = new Octree(Math::CalculateGeometryExtent(extentPointCount, p_x0y0z0, center), m_level + 1);
	m_pOctreeVector[X0Y1Z0] = new Octree(Math::CalculateGeometryExtent(extentPointCount, p_x0y1z0, center), m_level + 1);
	m_pOctreeVector[X0Y0Z1] = new Octree(Math::CalculateGeometryExtent(extentPointCount, p_x0y0z1, center), m_level + 1);
	m_pOctreeVector[X0Y1Z1] = new Octree(Math::CalculateGeometryExtent(extentPointCount, p_x0y1z1, center), m_level + 1);
	m_pOctreeVector[X1Y0Z0] = new Octree(Math::CalculateGeometryExtent(extentPointCount, p_x1y0z0, center), m_level + 1);
	m_pOctreeVector[X1Y1Z0] = new Octree(Math::CalculateGeometryExtent(extentPointCount, p_x1y1z0, center), m_level + 1);
	m_pOctreeVector[X1Y0Z1] = new Octree(Math::CalculateGeometryExtent(extentPointCount, p_x1y0z1, center), m_level + 1);
	m_pOctreeVector[X1Y1Z1] = new Octree(Math::CalculateGeometryExtent(extentPointCount, p_x1y1z1, center), m_level + 1);
}

void Octree::AddObjectIntoSubOctree(Geom::Object* pObject)
{
	assert(m_pOctreeVector.size() == OCTREE_CHILD_COUNT);
	const Geom::GeometryExtent3D& objectExtent = pObject->GetGeometryExtent();

	for (int index = 0; index < OCTREE_CHILD_COUNT; index++)
	{
		Octree* pChildOctree = m_pOctreeVector[index];
		if (Math::IsTwoExtentsIntersecting(objectExtent, pChildOctree->GetGeometryExtent()))
			pChildOctree->AddObject(pObject);
	}
}

int Octree::DebugCountObject() const
{
	if (m_pObjectVector.size() != 0)
		return m_pObjectVector.size();

	int count = 0;

	for (const auto& pOctree : m_pOctreeVector)
	{
		count += pOctree->DebugCountObject();
	}

	return count;
}

bool Octree::DebugVolumeChecksum() const
{
	// leaf
	if (m_pObjectVector.size() != 0)
		return true;

	double volumeSum = 0;
	for (const auto& pOctree : m_pOctreeVector)
	{
		volumeSum += pOctree->GetGeometryExtent().CalculateVolume();
	}

	return Math::IsEqual(m_extent.CalculateVolume(), volumeSum);
}