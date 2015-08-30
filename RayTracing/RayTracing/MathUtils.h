#pragma once
#include "GeometryExtent3D.h"
#include "Point3D.h"

namespace Math
{

static const double PRECISION_DOUBLE = 1e-9;

bool isEqual(double a, double b, double precision = PRECISION_DOUBLE);

bool isLess(double a, double b, double precision = PRECISION_DOUBLE);

bool isLessEqual(double a, double b, double precision = PRECISION_DOUBLE);

bool isGreater(double a, double b, double precision = PRECISION_DOUBLE);

bool isGreaterEqual(double a, double b, double precision = PRECISION_DOUBLE);

Geom::GeometryExtent3D CalculateGeometryExtent(int argCount, Geom::Point3D ...);

}