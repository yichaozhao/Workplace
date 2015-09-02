#include "Vector3D.h"
#include "MathUtils.h"
#include <assert.h>

namespace Geom
{

bool Vector3D::operator== (const Vector3D& vector) const
{
	return
		Math::IsEqual(m_x, vector.GetX()) &&
		Math::IsEqual(m_y, vector.GetY()) &&
		Math::IsEqual(m_z, vector.GetZ());
}

Vector3D Vector3D::operator- () const
{
	return Vector3D(-m_x, -m_y, -m_z);
}

Vector3D Vector3D::operator+ (const Vector3D& vector) const
{
	return Vector3D(m_x + vector.GetX(), m_y + vector.GetY(), m_z + vector.GetZ());
}

Vector3D Vector3D::operator- (const Vector3D& vector) const
{
	return Vector3D(m_x - vector.GetX(), m_y - vector.GetY(), m_z - vector.GetZ());
}

Vector3D Vector3D::operator* (double coeff) const
{
	return Vector3D(m_x * coeff, m_y * coeff, m_z * coeff);
}

Vector3D Vector3D::operator/ (double coeff) const
{
	assert(!Math::IsEqual(coeff, 0));
	return Vector3D(m_x / coeff, m_y / coeff, m_z / coeff);
}

double Vector3D::Dot(Vector3D vector) const
{
	return m_x * vector.GetX() + m_y * vector.GetY() + m_z * vector.GetZ();
}

Vector3D Vector3D::Cross(Vector3D vector) const
{
	return Vector3D(
		m_y * vector.GetZ() - m_z * vector.GetY(),
		m_z * vector.GetX() - m_x * vector.GetZ(),
		m_x * vector.GetY() - m_y * vector.GetX()
		);
}

static const int SQUARE_EXP = 2;

double Vector3D::CalculateLength() const
{
	return std::sqrt(std::pow(m_x, SQUARE_EXP) + std::pow(m_y, SQUARE_EXP) + std::pow(m_z, SQUARE_EXP));
}

Vector3D& Vector3D::Normalize()
{
	double length = CalculateLength();
	m_x /= length;
	m_y /= length;
	m_z /= length;

	return *this;
}

}