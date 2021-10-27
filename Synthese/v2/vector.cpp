#include "vector.h"

void Vec3::normalize()
{
	float n = this->norm();
	x /= n;
	y /= n;
	z /= n;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
	os << "Vec3 {" << v.get_x() << ", " << v.get_y() << ", " << v.get_z() << "}";
	return os;
}

float scalar(const Vec3& a, const Vec3& b) { return a.get_x() * b.get_x() + a.get_y() * b.get_y() + a.get_z() * b.get_z(); }

Vec3 cross(const Vec3& a, const Vec3& b)
{ 
	float x = a.get_y() * b.get_z() - a.get_z() * b.get_y();
	float y = a.get_z() * b.get_x() - a.get_x() * b.get_z();
	float z = a.get_x() * b.get_y() - a.get_y() * b.get_x();
	return Vec3(x, y, z);
}

Vec3 get_normal(const Vec3& a, const Vec3& b)
{
	Vec3 prod = cross(a, b);
	prod.normalize();
	return prod;
}