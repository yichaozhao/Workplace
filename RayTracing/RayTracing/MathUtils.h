#pragma once
#include "GeometryExtent3D.h"
#include "Point3D.h"
#include <vector>
#include <cmath>

namespace Geom
{
class Object;
}

namespace Math
{

static const double PRECISION_DOUBLE = 1e-9;
static const float PRECISION_FLOAT = 1e-5f;

bool IsEqual(double a, double b, double precision = PRECISION_DOUBLE);
bool IsEqual(float a, float b, float precision = PRECISION_FLOAT);

bool IsLess(double a, double b, double precision = PRECISION_DOUBLE);

bool IsLessEqual(double a, double b, double precision = PRECISION_DOUBLE);

bool IsGreater(double a, double b, double precision = PRECISION_DOUBLE);

bool IsGreaterEqual(double a, double b, double precision = PRECISION_DOUBLE);

Geom::GeometryExtent3D CalculateGeometryExtentFromObjects(const std::vector<Geom::Object*>& objectVector);
Geom::GeometryExtent3D CalculateGeometryExtent(int argCount, Geom::Point3D ...);

bool IsTwoExtentsIntersecting(Geom::GeometryExtent3D extent1, Geom::GeometryExtent3D extent2);

}