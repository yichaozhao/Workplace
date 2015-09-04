#pragma once
#include <string>

namespace Geom
{


class GeometryExtent3D;

class Object
{

public:
	Object() {}
	~Object() {}

	virtual const GeometryExtent3D& GetGeometryExtent() const = 0;
	virtual std::string toString() const { return ""; }

};


}