#include "mesh.h"

void Mesh::add_vertex(Vec3* vertex) { vertices.push_back(vertex); }

void Mesh::add_triangle(Vec3* v1, Vec3* v2, Vec3* v3) { triangles.push_back(new Triangle(v1, v2, v3)); }

void Mesh::add_triangle(Triangle* t) { triangles.push_back(t); }