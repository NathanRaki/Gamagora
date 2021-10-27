#include "vector.h"

Vec operator+(const Vec& a, const Vec& b) { return Vec{ a.x + b.x, a.y + b.y, a.z + b.z }; }
Vec operator-(const Vec& a, const Vec& b) { return Vec{ a.x - b.x, a.y - b.y, a.z - b.z }; }
Vec operator*(const float s, const Vec& b) { return Vec{ s * b.x, s * b.y, s * b.z }; }
Vec operator*(const Vec& a, const float s) { return Vec{ a.x * s, a.y * s, a.z * s }; }
Vec operator/(const Vec& a, const float s) { return Vec{ a.x / s, a.y / s, a.z / s }; }
std::ostream& operator<<(std::ostream& os, const Vec& v)
{
    os << "Vec {" << v.x << ", " << v.y << ", " << v.z << "}";
    return os;
}