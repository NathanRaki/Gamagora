#include "mesh.h"
#include "ray.h"

#include <iostream>
#include <vector>

int main()
{
	/*Vec3 v1(2, 1, 0);
	Vec3 v2(2, 3, 0);
	Vec3 v3(3, 2, 0);
	Triangle tri(&v1, &v2, &v3);

	Ray ray;
	ray.position.set(3, 2, 3);
	ray.direction.set(0, 0, -1);

	std::optional<float> t = ray.intersect(&tri);
	if (t.has_value())
	{
		std::cout << t.value() << std::endl;
	}
	else
	{
		std::cout << "Pas d'intersection." << std::endl;
	}*/

	Mesh mesh;
	float size = 10;

	for (float i = -size / 2.0f; i <= size / 2.0f; ++i)
	{
		for (float j = -size / 2.0f; j <= size / 2.0f; ++j)
		{
			mesh.add_vertex(new Vec3(i, j, 0));
		}
	}

	for (float i = -size / 2.0f; i < size / 2.0f; ++i)
	{
		for (float j = -size / 2.0f; j < size / 2.0f; ++j)
		{
			Vec3* v1 = new Vec3(i, j, 0);
			Vec3* v2 = new Vec3(i, j+1, 0);
			Vec3* v3 = new Vec3(i+1, j, 0);
			Vec3* v4 = new Vec3(i+1, j+1, 0);
			mesh.add_triangle(new Triangle(v1, v2, v3));
			mesh.add_triangle(new Triangle(v2, v3, v4));
		}
	}

	for ()
}