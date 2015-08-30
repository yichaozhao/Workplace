#include "MathUtils.h"

namespace Math
{

bool isEqual(double a, double b, double precision)
{
	return std::abs(a - b) < precision;
}

bool isLess(double a, double b, double precision)
{
	return a < b && !isEqual(a, b, precision);
}

bool isLessEqual(double a, double b, double precision)
{
	return a < b || isEqual(a, b, precision);
}

bool isGreater(double a, double b, double precision)
{
	return a > b && !isEqual(a, b, precision);
}

bool isGreaterEqual(double a, double b, double precision)
{
	return a > b || isEqual(a, b, precision);
}

}