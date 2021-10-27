#pragma once

#include <cmath>
#include <iostream>
#include <optional>

class Vec3
{
public:
	// Constructors
	Vec3() {}
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	// Methods
	float norm() const { return std::sqrt(x * x + y * y + z * z); }
	float norm2() const { return x * x + y * y + z * z; }
	void normalize();
	// Setters
	void set(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
	void set_x(float x) { this->x = x; }
	void set_y(float y) { this->y = y; }
	void set_z(float z) { this->z = z; }
	// Getters
	float get_x() const { return this->x; }
	float get_y() const { return this->y; }
	float get_z() const { return this->z; }

private:
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
};

inline Vec3 operator+(const Vec3& a, const Vec3& b) { return Vec3(a.get_x() + b.get_x(), a.get_y() + b.get_y(), a.get_z() + b.get_z()); }
inline Vec3 operator-(const Vec3& a, const Vec3& b) { return Vec3(a.get_x() - b.get_x(), a.get_y() - b.get_y(), a.get_z() - b.get_z()); }
inline Vec3 operator*(const float s, const Vec3& b) { return Vec3(s * b.get_x(), s * b.get_y(), s * b.get_z()); }
inline Vec3 operator*(const Vec3& a, const float s) { return Vec3(a.get_x() * s, a.get_y() * s, a.get_z() * s); }
inline Vec3 operator/(const Vec3& a, const float s) { return Vec3(a.get_x() / s, a.get_y() / s, a.get_z() / s); }
inline bool operator==(const Vec3& a, const Vec3& b) { return a.get_x() == b.get_x() && a.get_y() == b.get_y() && a.get_z() == b.get_z(); }
float scalar(const Vec3& a, const Vec3& b);
Vec3 cross(const Vec3& a, const Vec3& b);
Vec3 get_normal(const Vec3& a, const Vec3& b);
std::ostream& operator<<(std::ostream& os, const Vec3& v);