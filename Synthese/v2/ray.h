#pragma once

#include "mesh.h"
#include <optional>

class Ray
{
public:
	Ray() {}
	Ray(Vec3& pos, Vec3& dir) : position(pos), direction(dir) {}
	~Ray() = default;

	std::optional<float> intersect(Triangle* t);

	Vec3 position = Vec3();
	Vec3 direction = Vec3();
};