#include "MathUtils.h"
#include <stdarg.h>
#include <limits>
#include "Object.h"
#include <assert.h>

namespace Math
{

bool IsEqual(double a, double b, double precision)
{
	return std::abs(a - b) < precision;
}

bool IsEqual(float a, float b, float precision)
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
		Geom::Point3D& point = va_arg(pointList, Geom::Point3D);

		min_x = std::fmin(min_x, point.GetX());
		min_y = std::fmin(min_y, point.GetY());
		min_z = std::fmin(min_z, point.GetZ());

		max_x = std::fmax(max_x, point.GetX());
		max_y = std::fmax(max_y, point.GetY());
		max_z = std::fmax(max_z, point.GetZ());
	}

	return Geom::GeometryExtent3D(Geom::Point3D(min_x, min_y, min_z), Geom::Point3D(max_x, max_y, max_z));
}

Geom::GeometryExtent3D CalculateGeometryExtentFromObjects(const std::vector<Geom::Object*>& objectVector)
{
	assert(objectVector.size() > 0);

	double min_x = std::numeric_limits<double>::max(), min_y = std::numeric_limits<double>::max(), min_z = std::numeric_limits<double>::max();
	double max_x = std::numeric_limits<double>::lowest(), max_y = std::numeric_limits<double>::lowest(), max_z = std::numeric_limits<double>::lowest();

	for (const auto& pObject : objectVector)
	{
		assert(pObject);
		const Geom::Point3D& lower = pObject->GetGeometryExtent().GetLower();
		const Geom::Point3D& upper = pObject->GetGeometryExtent().GetUpper();

		min_x = std::fmin(min_x, lower.GetX());
		min_y = std::fmin(min_y, lower.GetY());
		min_z = std::fmin(min_z, lower.GetZ());

		max_x = std::fmax(max_x, upper.GetX());
		max_y = std::fmax(max_y, upper.GetY());
		max_z = std::fmax(max_z, upper.GetZ());
	}

	return Geom::GeometryExtent3D(Geom::Point3D(min_x, min_y, min_z), Geom::Point3D(max_x, max_y, max_z));
}

bool IsTwoExtentsIntersecting(Geom::GeometryExtent3D extent1, Geom::GeometryExtent3D extent2)
{
	return 
		(IsLessEqual(extent1.GetLower().GetX(), extent2.GetUpper().GetX()) && IsLessEqual(extent2.GetLower().GetX(), extent1.GetUpper().GetX())) &&
		(IsLessEqual(extent1.GetLower().GetY(), extent2.GetUpper().GetY()) && IsLessEqual(extent2.GetLower().GetY(), extent1.GetUpper().GetY())) &&
		(IsLessEqual(extent1.GetLower().GetZ(), extent2.GetUpper().GetZ()) && IsLessEqual(extent2.GetLower().GetZ(), extent1.GetUpper().GetZ()));
	
}

}