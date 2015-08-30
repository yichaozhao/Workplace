#pragma once
#include <cmath>

namespace Math
{

static const double PRECISION_DOUBLE = 1e-9;


bool isEqual(double a, double b, double precision = PRECISION_DOUBLE);

bool isLess(double a, double b, double precision = PRECISION_DOUBLE);

bool isLessEqual(double a, double b, double precision = PRECISION_DOUBLE);

bool isGreater(double a, double b, double precision = PRECISION_DOUBLE);

bool isGreaterEqual(double a, double b, double precision = PRECISION_DOUBLE);


}