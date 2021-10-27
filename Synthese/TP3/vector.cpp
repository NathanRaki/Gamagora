#include "vector.h"

Vec operator+(const Vec& a, const Vec& b) { return Vec{ a.x + b.x, a.y + b.y, a.z + b.z }; }
Vec operator-(const Vec& a, const Vec& b) { return Vec{ a.x - b.x, a.y - b.y, a.z - b.z }; }
Vec operator*(const float s, const Vec& b) { return Vec{ s * b.x, s * b.y, s * b.z }; }
Vec operator*(const Vec& a, const float s) { return Vec{ a.x * s, a.y * s, a.z * s }; }
Vec operator/(const Vec& a, const float s) { return Vec{ a.x / s, a.y / s, a.z / s }; }

std::ostream& operator<<(std::ostream& os, const Vec& v)
{
    os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    return os;
}
std::ostream& operator<<(std::ostream& os, const Sphere& s)
{
    os << "Sphere { Rayon: " << s.r << ", Centre: " << s.C << " }";
    return os;
}
std::ostream& operator<<(std::ostream& os, const Rayon& r)
{
    os << "Rayon { Origine: " << r.origin() << ", Direction: " << r.direction() << " }";
    return os;
}

float scalar(const Vec& a, const Vec& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

std::optional<double> intersect(const Rayon& r, const Sphere& s)
{
    double A = scalar(r.direction(), r.direction());
    //std::cout << "A: " << A << std::endl;
    double B = 2.0 * scalar(r.origin() - s.C, r.direction());
    //std::cout << "B: " << B << std::endl;
    double C = scalar(r.origin() - s.C, r.origin() - s.C) - s.r * s.r;
    //std::cout << "C: " << C << std::endl;
    double D = B * B - 4.0 * A * C;
    //std::cout << "D: " << D << std::endl;

    if (D == 0) { return -B / (2.0 * A); }
    else if (D > 0) { return abs((-B - sqrt(D)) / (2.0 * A)); }
}