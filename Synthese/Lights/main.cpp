#include <limits>
#include <vector>
#include "ppm.h"
#include "object.h"

# define M_PI           3.14159265358979323846

int main()
{
	int h = 700, w = 700;
	PPM ppm(h, w);

	std::vector<Object*> objects;

	Camera camera(Vec3((float)h / 2, (float)w / 2, -250.f), Vec3(0.f, 0.f, 1.f));
	Sphere sphere1(Vec3((float)h / 2.f, (float)w / 4.f, 0.f), 100.f);
	Sphere sphere2(Vec3((float)h / 2.f, (float)w / 4.f * 3.f, 0.f), 100.f);
	Light light(Vec3((float)h / 4.f, (float)w / 2.f, -150.f), Vec3(1.f, 1.f, 0.f));

	objects.push_back(&camera);
	objects.push_back(&sphere1);
	objects.push_back(&sphere2);
	objects.push_back(&light);

	float max = -std::numeric_limits<float>::infinity();

	for (int n = 0; n < objects.size(); ++n)
	{
		Sphere* sphere = dynamic_cast<Sphere*>(objects[n]);
		if (sphere)
		{
			std::cout << "yes" << std::endl;
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					Vec3 pos = Vec3((float)i, (float)j, 0.f);
					Rayon beam = Rayon(camera.position(), pos - camera.position());
					std::optional<float> res = beam.intersect(*sphere);
					if (res.has_value())
					{
						Vec3 p = res.value() * beam.direction() + beam.position();
						beam = Rayon(p, light.position() - p);
						res = beam.intersect(*sphere);

						Vec3 N = (p - sphere->position());
						Vec3 L = beam.direction();
						float NL = scalar(N, L);
						if (NL > 0)
						{
							Vec3 Le = Vec3(10000, 0, 0);
							float d2 = beam.direction().norm2();
							Vec3 lighting = (NL * Le) / (2.0 * M_PI * d2);
							ppm.image[i][j].r = fmin(lighting.get_x(), 255);
							ppm.image[i][j].g = fmin(lighting.get_y(), 255);
							ppm.image[i][j].b = fmin(lighting.get_z(), 255);
						}
						else
						{
							ppm.image[i][j].r = 0;
							ppm.image[i][j].g = 0;
							ppm.image[i][j].b = 0;
						}
					}
				}
			}
		}
	}

	ppm.set_version("P3");
	ppm.save("result.ppm");
}