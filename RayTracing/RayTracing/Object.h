#pragma once

namespace Geom
{


class GeometryExtent3D;

class Object
{

public:
	Object() {}
	~Object() {}

	virtual const GeometryExtent3D& GetGeometryExtent() const = 0;

};


}