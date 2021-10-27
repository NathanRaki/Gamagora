#include "camera.h"

Image::Image()
{
	length = 1000;
	width = 1000;
	sphere = Sphere{ 300.0, Vec{ (float)length / 2, (float)width / 2, 500.0 } };
	test = Vec{ 0, 0, 1 };
}

void Image::addX(float x) { test.x += x; }
void Image::addY(float y) { test.y += y; }
void Image::addZ(float z) { test.z += z; }

void Image::draw()
{
	mat = cv::Mat(width, length, CV_8UC3, cv::Scalar(255, 0, 255));
	float min = std::numeric_limits<float>::infinity();
	float max = -std::numeric_limits<float>::infinity();
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < length; ++j)
		{

			std::optional<float> res = intersect(Rayon(Vec{ (float)i, (float)j, 0 }, test), sphere);
			if (res.has_value())
			{
				if (res.value() > max) { max = res.value(); }
				if (res.value() < min) { min = res.value(); }
			}
		}
	}
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < length; ++j)
		{

			std::optional<float> res = intersect(Rayon(Vec{ (float)i, (float)j, 0 }, test), sphere);
			if (res.has_value())
			{
				//std::cout << res.value() << std::endl;
				cv::Vec3b& color = mat.at<cv::Vec3b>(i, j);
				color[0] = 255 - (res.value() * 255) / max;
				color[1] = 255 - (res.value() * 255) / max;
				color[2] = 255 - (res.value() * 255) / max;
			}
		}
	}
}