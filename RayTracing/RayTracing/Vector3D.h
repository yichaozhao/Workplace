#pragma once

namespace Geom
{


class Vector3D
{

private:
	double m_x;
	double m_y;
	double m_z;

public:
	Vector3D(double x, double y, double z) :
		m_x(x),
		m_y(y),
		m_z(z)
	{}

	~Vector3D() {}

	double GetX() const { return m_x; }
	double GetY() const { return m_y; }
	double GetZ() const { return m_z; }

	bool operator== (const Vector3D& vector) const;
	bool operator!= (const Vector3D& vector) const { return !operator==(vector); }
	Vector3D operator- () const;
	Vector3D operator+ (const Vector3D& vector) const;
	Vector3D operator- (const Vector3D& vector) const;
	Vector3D operator* (double coeff) const;
	Vector3D operator/ (double coeff) const;

	double Dot(Vector3D vector) const;
	Vector3D Cross(Vector3D vector) const;
};


}
