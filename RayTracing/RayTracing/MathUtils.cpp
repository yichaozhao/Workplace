#include "MathUtils.h"
#include <cmath>
#include <stdarg.h>
#include <limits>

namespace Math
{

bool IsEqual(double a, double b, double precision)
{
	return std::abs(a - b) < precision;
}

bool IsLess(double a, double b, double precision)
{
	return a < b && !IsEqual(a, b, precision);
}

bool IsLessEqual(double a, double b, double precision)
{
	return a < b || IsEqual(a, b, precision);
}

bool IsGreater(double a, double b, double precision)
{
	return a > b && !IsEqual(a, b, precision);
}

bool IsGreaterEqual(double a, double b, double precision)
{
	return a > b || IsEqual(a, b, precision);
}

Geom::GeometryExtent3D CalculateGeometryExtent(int argCount, Geom::Point3D ...)
{
	double min_x = std::numeric_limits<double>::max(), min_y = std::numeric_limits<double>::max(), min_z = std::numeric_limits<double>::max();
	double max_x = std::numeric_limits<double>::lowest(), max_y = std::numeric_limits<double>::lowest(), max_z = std::numeric_limits<double>::lowest();

	va_list pointList;
	va_start(pointList, argCount);

	for (int index = 0; index < argCount; index++)
	{
		Geom::Point3D& p = va_arg(pointList, Geom::Point3D);

		min_x = std::fmin(min_x, p.getX());
		min_y = std::fmin(min_y, p.getY());
		min_z = std::fmin(min_z, p.getZ());

		max_x = std::fmax(max_x, p.getX());
		max_y = std::fmax(max_y, p.getY());
		max_z = std::fmax(max_z, p.getZ());
	}

	return Geom::GeometryExtent3D(Geom::Point3D(min_x, min_y, min_z), Geom::Point3D(max_x, max_y, max_z));
}

bool HasIntersection(Geom::GeometryExtent3D extent1, Geom::GeometryExtent3D extent2)
{
	return 
		(IsLessEqual(extent1.GetLower().getX(), extent2.GetUpper().getX()) && IsLessEqual(extent2.GetLower().getX(), extent1.GetUpper().getX())) &&
		(IsLessEqual(extent1.GetLower().getY(), extent2.GetUpper().getY()) && IsLessEqual(extent2.GetLower().getY(), extent1.GetUpper().getY())) &&
		(IsLessEqual(extent1.GetLower().getZ(), extent2.GetUpper().getZ()) && IsLessEqual(extent2.GetLower().getZ(), extent1.GetUpper().getZ()));
	
}

}