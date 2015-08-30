#pragma once

namespace Geom
{


class GeometryExtent3D;

class Object
{

public:
	Object() {}
	~Object() {}

	virtual GeometryExtent3D& GetGeometryExtent3D() = 0;

};


}