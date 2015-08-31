#include "Octree.h"
#include <assert.h>
#include "MathUtils.h"

void Octree::CreateOctree(Octree*& pOctree, std::vector<Geom::Object*> pObjectVector)
{
	pOctree = new Octree(Geom::GeometryExtent3D(Geom::Point3D(0, 0, 0), Geom::Point3D(8, 8, 8)));
}

void Octree::AddObject(Geom::Object* pObject)
{
	assert(pObject);
	if (m_pOctreeVector.size() == 0)
	{
		if (m_pObjectVector.size() < MAX_OBJECT_COUNT)
		{
			// put into vector
		}
		else
		{
			// need divide octree
			assert(m_pObjectVector.size() == MAX_OBJECT_COUNT); // should just reach max count
			// resize Octree vector to OCTREE_CHILD_COUNT, to indicate the octree node itself will not be storing object anymore
			m_pOctreeVector.resize(OCTREE_CHILD_COUNT);

			// loop all existing object + new one
			// insert into x0y0z0 if needed
			// insert into x0y1z0 if needed
			// insert into x0y0z1 if needed
			// insert into x0y1z1 if needed
			// insert into x1y0z0 if needed
			// insert into x1y1z0 if needed
			// insert into x1y0z1 if needed
			// insert into x1y1z1 if needed

			
			m_pObjectVector.clear();
		}
	}
	else
	{
		// insert into x0y0z0 if needed
		// insert into x0y1z0 if needed
		// insert into x0y0z1 if needed
		// insert into x0y1z1 if needed
		// insert into x1y0z0 if needed
		// insert into x1y1z0 if needed
		// insert into x1y0z1 if needed
		// insert into x1y1z1 if needed
	}
}

void Octree::AddObjectIntoSubOctree(Geom::Object* pObject)
{
	assert(m_pObjectVector.size() == 0 && m_pOctreeVector.size() == OCTREE_CHILD_COUNT);
	const Geom::GeometryExtent3D& extent = pObject->GetGeometryExtent3D();

	// insert into x0y0z0 if needed
	Geom::Point3D p_x0y0z0 = m_extent.GetLower();
	// insert into x0y1z0 if needed
	// insert into x0y0z1 if needed
	// insert into x0y1z1 if needed
	// insert into x1y0z0 if needed
	// insert into x1y1z0 if needed
	// insert into x1y0z1 if needed
	// insert into x1y1z1 if needed
	Geom::Point3D p_x1y1z1 = m_extent.GetUpper();
}
