#pragma once
#include <cmath>

namespace Math
{

static const double PRECISION_DOUBLE = 1e-9;


bool isEqual(double a, double b, double precision = PRECISION_DOUBLE)
{
	return std::abs(a - b) < precision;
}

bool isLess(double a, double b, double precision = PRECISION_DOUBLE)
{
	return a < b && !isEqual(a, b, precision);
}

bool isLessEqual(double a, double b, double precision = PRECISION_DOUBLE)
{
	return a < b || isEqual(a, b, precision);
}

bool isGreater(double a, double b, double precision = PRECISION_DOUBLE)
{
	return a > b && !isEqual(a, b, precision);
}

bool isGreaterEqual(double a, double b, double precision = PRECISION_DOUBLE)
{
	return a > b || isEqual(a, b, precision);
}


}