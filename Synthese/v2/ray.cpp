#include "ray.h"

std::optional<float> Ray::intersect(Triangle* tri)
{
	Vec3 e1, e2, h, s, q;
	float a, f, u, v;
	e1 = *tri->v2 - *tri->v1;
	e2 = *tri->v3 - *tri->v1;
	h = cross(direction, e2);
	direction.normalize();
	a = scalar(h, e1);

	if (a == 0) { return std::nullopt; }
	f = 1.0 / a;
	s = position - *tri->v1;
	u = f * scalar(s, h);
	if (u < 0 || u > 1) { return std::nullopt; }
	q = cross(s, e1);
	v = f * scalar(q, direction);
	if (v < 0 || u + v > 1) { return std::nullopt; }

	float t = f * scalar(q, e2);
	if (t > 0) { return t; }
	else { return std::nullopt; }
}