#pragma once

#include "vector.h"

class Object
{
public:
	// Constructors
	Object() {}
	Object(Vec3 pos) : pos(pos) {}
	virtual ~Object() = default;
	// Getters
	Vec3 position() const { return pos; }

private:
	Vec3 pos = Vec3();
};

class Sphere : public Object
{
public:
	// Constructors
	Sphere() {}
	Sphere(Vec3 pos, float r) : Object(pos), r(r) {}
	// Getters
	float radius() const { return r; }

private:
	float r = 0.f;
};

class Rayon : public Object
{
public:
	// Constructors
	Rayon() {}
	Rayon(Vec3 pos, Vec3 dir) : Object(pos), dir(dir) {}
	// Methods
	std::optional<float> intersect(const Sphere& s);
	Vec3 hit(float t) const { return position() + t * dir; }
	// Getters
	Vec3 direction() const { return dir; }

private:
	Vec3 dir = Vec3();
};

class Light : public Object
{
public:
	// Constructors
	Light() {}
	Light(Vec3 pos, Vec3 dir) : Object(pos), dir(dir) {}
	// Getters
	Vec3 direction() const { return dir; }
	Rayon ray() const { return Rayon(position(), dir); }

private:
	Vec3 dir = Vec3();
};

class Camera : public Object
{
public:
	// Constructors
	Camera() {}
	Camera(Vec3 pos, Vec3 dir) : Object(pos), dir(dir) {}
	// Getters
	Vec3 direction() const { return dir; }
	Rayon ray() const { return Rayon(position(), dir); }

private:
	Vec3 dir = Vec3();
};

std::ostream& operator<<(std::ostream& os, const Sphere& s);
std::ostream& operator<<(std::ostream& os, const Rayon& r);