#pragma once
#include <cmath>

namespace Math
{

static const double PRECISION_DOUBLE = 1e-9;


bool isEqual(double a, double b, double precision = PRECISION_DOUBLE) {
	return std::abs(a - b) < precision;
}

}