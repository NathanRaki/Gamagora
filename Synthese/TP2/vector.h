#include <cmath>
#include <iostream>

struct Vec
{
    float x, y, z;

    float norm2() const { return x * x + y * y + z * z; }
    float norm() const { return std::sqrt(x * x + y * y + z * z); }
};

Vec operator+(const Vec& a, const Vec& b);
Vec operator-(const Vec& a, const Vec& b);
Vec operator*(const float s, const Vec& b);
Vec operator*(const Vec& a, const float s);
Vec operator/(const Vec& a, const float s);
std::ostream& operator<<(std::ostream& os, const Vec& v);