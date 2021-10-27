#include "vector.h"



std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
	os << "Vec3 {" << v.get_x() << ", " << v.get_y() << ", " << v.get_z() << "}";
	return os;
}

float scalar(const Vec3& a, const Vec3& b) { return a.get_x() * b.get_x() + a.get_y() * b.get_y() + a.get_z() * b.get_z(); }