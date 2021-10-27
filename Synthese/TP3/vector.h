#pragma once

#include <cmath>
#include <iostream>
#include <optional>

struct Vec
{
    float x, y, z;

    float norm2() const { return x * x + y * y + z * z; }
    float norm() const { return std::sqrt(x * x + y * y + z * z); }
};
struct Sphere
{
    float r;
    Vec C;
};
Vec operator+(const Vec& a, const Vec& b);
Vec operator-(const Vec& a, const Vec& b);
Vec operator*(const float s, const Vec& b);
Vec operator*(const Vec& a, const float s);
Vec operator/(const Vec& a, const float s);
float scalar(const Vec& a, const Vec& b);

class Rayon
{
public:
    Rayon() { X = Vec{ 0, 0, 0 }; D = Vec{ 0, 0, 0 }; }
    Rayon(const Vec& a, const Vec& b) { X = a; D = b; }
    Vec origin() const { return X; }
    Vec direction() const { return D; }
    Vec point(float t) const { return X + t * D; }

private:
    Vec X;
    Vec D;
};

std::optional<double> intersect(const Rayon& r, const Sphere& s);

std::ostream& operator<<(std::ostream& os, const Vec& v);
std::ostream& operator<<(std::ostream& os, const Sphere& s);
std::ostream& operator<<(std::ostream& os, const Rayon& r);