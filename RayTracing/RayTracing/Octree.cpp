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
	m_pOctreeVector[X0Y0Z0] = new Octree(Math::CalculateGeometryExtent(extentPointCount, &p_x0y0z0, &center), m_level + 1);
	m_pOctreeVector[X0Y1Z0] = new Octree(Math::CalculateGeometryExtent(extentPointCount, &p_x0y1z0, &center), m_level + 1);
	m_pOctreeVector[X0Y0Z1] = new Octree(Math::CalculateGeometryExtent(extentPointCount, &p_x0y0z1, &center), m_level + 1);
	m_pOctreeVector[X0Y1Z1] = new Octree(Math::CalculateGeometryExtent(extentPointCount, &p_x0y1z1, &center), m_level + 1);
	m_pOctreeVector[X1Y0Z0] = new Octree(Math::CalculateGeometryExtent(extentPointCount, &p_x1y0z0, &center), m_level + 1);
	m_pOctreeVector[X1Y1Z0] = new Octree(Math::CalculateGeometryExtent(extentPointCount, &p_x1y1z0, &center), m_level + 1);
	m_pOctreeVector[X1Y0Z1] = new Octree(Math::CalculateGeometryExtent(extentPointCount, &p_x1y0z1, &center), m_level + 1);
	m_pOctreeVector[X1Y1Z1] = new Octree(Math::CalculateGeometryExtent(extentPointCount, &p_x1y1z1, &center), m_level + 1);
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

/*static*/ void Octree::CalculateIntersectingOctrees(const Octree& octree, const Geom::Ray& ray, std::vector<const Octree*>& resultVector)
{
	const Geom::GeometryExtent3D& extent = octree.GetGeometryExtent();
	const Geom::Point3D& rayOrigin = ray.GetOrigin();
	const Geom::Vector3D& rayDirection = ray.GetDirection();

	double originX = rayOrigin.GetX(), originY = rayOrigin.GetY(), originZ = rayOrigin.GetZ();
	double directionX = rayDirection.GetX(), directionY = rayDirection.GetY(), directionZ = rayDirection.GetZ();

	int bit = 0;
	if (rayDirection.GetX() < 0.0)
	{
		originX = extent.GetLengthX() - rayOrigin.GetX();
		directionX = -rayDirection.GetX();
		bit |= BIT_ZERO;
	}
	if (rayDirection.GetY() < 0.0)
	{
		originY = extent.GetLengthY() - rayOrigin.GetY();
		directionY = -rayDirection.GetY();
		bit |= BIT_ONE;
	}
	if (rayDirection.GetZ() < 0.0)
	{
		originZ = extent.GetLengthZ() - rayOrigin.GetZ();
		directionZ = -rayDirection.GetZ();
		bit |= BIT_TWO;
	}

	const Geom::Ray adjustRay(Geom::Point3D(originX, originY, originZ), Geom::Vector3D(directionX, directionY, directionZ));
	const Geom::Point3D& adjustRayOrigin = adjustRay.GetOrigin();
	const Geom::Vector3D& adjustRayDirection = adjustRay.GetDirection();

	Geom::Vector3D t0(
		(extent.GetLower().GetX() - adjustRayOrigin.GetX()) / adjustRayDirection.GetX(),
		(extent.GetLower().GetY() - adjustRayOrigin.GetY()) / adjustRayDirection.GetY(),
		(extent.GetLower().GetZ() - adjustRayOrigin.GetZ()) / adjustRayDirection.GetZ());

	Geom::Vector3D t1(
		(extent.GetUpper().GetX() - adjustRayOrigin.GetX()) / adjustRayDirection.GetX(),
		(extent.GetUpper().GetY() - adjustRayOrigin.GetY()) / adjustRayDirection.GetY(),
		(extent.GetUpper().GetZ() - adjustRayOrigin.GetZ()) / adjustRayDirection.GetZ());

	double maxLower = std::max<double>(t0.GetX(), std::max<double>(t0.GetY(), t0.GetZ()));
	double minUpper = std::min<double>(t1.GetX(), std::min<double>(t1.GetY(), t1.GetZ()));

	if (maxLower < minUpper)
	{
		octree.SearchOctree(t0.GetX(), t0.GetY(), t0.GetZ(), t1.GetX(), t1.GetY(), t1.GetZ(), bit, resultVector);
	}
}

void Octree::SearchOctree(
	double tx0, double ty0, double tz0,
	double tx1, double ty1, double tz1,
	int bit, std::vector<const Octree*>& resultVector) const
{
	if (Math::IsLess(tx1, 0) || Math::IsLess(ty1, 0) || Math::IsLess(tz1, 0))
		return;

	if (IsLeaf())
	{
		resultVector.emplace_back(this);
		return;
	}

	const double txm = 0.5 * (tx0 + tx1), tym = 0.5 * (ty0 + ty1), tzm = 0.5 * (tz0 + tz1);
	int currentIndex = X0Y0Z0; /* first voxel */;

	do
	{
		switch (currentIndex)
		{
		case X0Y0Z0: // 0
			m_pOctreeVector[bit^X0Y0Z0]->SearchOctree(tx0, ty0, tz0, txm, tym, tzm, bit, resultVector);
			currentIndex = CalculateNextChildOctree(txm, X1Y0Z0, tym, X0Y1Z0, tzm, X0Y0Z1);
			break;
		case X0Y0Z1: // 1
			m_pOctreeVector[bit^X0Y0Z1]->SearchOctree(tx0, ty0, tzm, txm, tym, tz1, bit, resultVector);
			currentIndex = CalculateNextChildOctree(txm, X1Y0Z1, tym, X0Y1Z1, tz1, _EXIT_);
			break;
		case X0Y1Z0: // 2
			m_pOctreeVector[bit^X0Y1Z0]->SearchOctree(tx0, tym, tz0, txm, ty1, tzm, bit, resultVector);
			currentIndex = CalculateNextChildOctree(txm, X1Y1Z0, ty1, _EXIT_, tzm, X0Y1Z1);
			break;
		case X0Y1Z1: // 3
			m_pOctreeVector[bit^X0Y1Z1]->SearchOctree(tx0, tym, tzm, txm, ty1, tz1, bit, resultVector);
			currentIndex = CalculateNextChildOctree(txm, X1Y1Z1, ty1, _EXIT_, tz1, _EXIT_);
			break;
		case X1Y0Z0: // 4
			m_pOctreeVector[bit^X1Y0Z0]->SearchOctree(txm, ty0, tz0, tx1, tym, tzm, bit, resultVector);
			currentIndex = CalculateNextChildOctree(tx1, _EXIT_, tym, X1Y1Z0, tzm, X1Y0Z1);
			break;
		case X1Y0Z1: // 5
			m_pOctreeVector[bit^X1Y0Z1]->SearchOctree(txm, ty0, tzm, tx1, tym, tz1, bit, resultVector);
			currentIndex = CalculateNextChildOctree(tx1, _EXIT_, tym, X1Y1Z1, tz1, _EXIT_);
			break;
		case X1Y1Z0: // 6
			m_pOctreeVector[bit^X1Y1Z0]->SearchOctree(txm, tym, tz0, tx1, ty1, tzm, bit, resultVector);
			currentIndex = CalculateNextChildOctree(tx1, _EXIT_, ty1, _EXIT_, tzm, X1Y1Z1);
			break;
		case X1Y1Z1: // 7
			m_pOctreeVector[bit^X1Y1Z1]->SearchOctree(txm, tym, tzm, tx1, ty1, tz1, bit, resultVector);
			currentIndex = _EXIT_;
			break;
		}
	} while (currentIndex < _EXIT_);
}

int Octree::CalculateFirstChildOctree(const Geom::Vector3D& t0, const Geom::Vector3D& tm) const
{
	int bit = 0;
	if (t0.GetX() > t0.GetY())
	{
		if (t0.GetX() > t0.GetZ()) // YZ
		{
			if (tm.GetY() < t0.GetX())
				bit |= BIT_ONE;
			if (tm.GetZ() < t0.GetX())
				bit |= BIT_TWO;
		}
		else //XY
		{
			if (tm.GetX() < t0.GetZ())
				bit |= BIT_ZERO;
			if (tm.GetY() < t0.GetZ())
				bit |= BIT_ONE;
		}
	}
	// XZ
	if (tm.GetX() < t0.GetY())
		bit |= BIT_ZERO;
	if (tm.GetZ() < t0.GetY())
		bit |= BIT_TWO;

	return bit;
}

int Octree::CalculateNextChildOctree(double x, int indexX, double y, int indexY, double z, int indexZ) const
{
	if (x < y)
	{
		if (x < z)
		{
			return indexX;
		}
	}
	else
	{
		if (y < z)
			return indexY;
	}

	return indexZ;
}