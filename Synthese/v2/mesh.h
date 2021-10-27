#pragma once

#include "vector.h"
#include <vector>

class Triangle
{
public:
	Triangle() {}
	Triangle(Vec3* v1, Vec3* v2, Vec3* v3) : v1(v1), v2(v2), v3(v3) {}
	Triangle(Vec3* v1, Vec3* v2, Vec3* v3, Vec3* color) : v1(v1), v2(v2), v3(v3), color(color) {}

	Vec3* v1 = new Vec3();
	Vec3* v2 = new Vec3();
	Vec3* v3 = new Vec3();
	Vec3* color = new Vec3();
};

class Mesh
{
public:
	Mesh() {}

	void add_vertex(Vec3* vertex);
	void add_triangle(Vec3* v1, Vec3* v2, Vec3* v3);
	void add_triangle(Triangle* t);

private:
	std::vector<Vec3*> vertices{};
	std::vector<Triangle*> triangles{};
};