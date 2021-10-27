#include <iostream>
#include "vector.h"
#include "camera.h"
#include <opencv2/opencv.hpp>

#define DEBUGMODE 1

void skydive()
{
	cv::Mat res(2005, 2005, CV_8UC3, cv::Vec3b(0, 0, 0));

	const float g = 9.8;
	const float mass = 100;
	const float dt = 0.1;
	const Vec z{ 0, 0, 1 };
	const float terminalVelocity = 50;
	const float cDrag = g * mass / (terminalVelocity * terminalVelocity);

	Vec p{ 0, 0, 2000 };
	Vec v{ 25, 0, 0 };

	float t = 0;

	while (t < 60)
	{
		std::cout << "T: " << t << "\nP: " << p << "\nV: " << v << std::endl;
		Vec acceleration = -g * z - (cDrag * v.norm() * v / mass);
		v = v + dt * acceleration;
		p = p + v;
		t += dt;

		if (p.x < 0 || p.z < 0) { break; }
		for (int a = -5; a < 5; a++)
		{
			for (int b = -5; b < 5; b++)
			{
				cv::Vec3b& color = res.at<cv::Vec3b>(p.x + a, p.z + b);
				color[0] = 0;
				color[1] = 0;
				color[2] = 255;
			}
		}

		imwrite("res.png", res);
	}
}

int main()
{
	// Skydive simulation
	// skydive();

	// Ray-Sphere Intersection
	Sphere s{ 2.0, Vec{50.0, 50.0, 0.0} };
	Rayon r(Vec{ 0.0, 0.0, 0.0 }, Vec{ 0.0, 1.0, 0.0 });
	std::cout << s << std::endl;
	std::cout << r << std::endl;
	std::optional<float> t = intersect(r, s);
	if (t.has_value()) { std::cout << "Valeur de t: " << t.value() << std::endl; }
	else { std::cout << "Pas d'intersection." << std::endl; }

	Image img;
	img.draw();

	cv::imshow("img", img.mat);
	cv::setWindowProperty("img", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);
	cv::setWindowProperty("img", cv::WND_PROP_FULLSCREEN, cv::WINDOW_NORMAL);

	int k;
	while (true)
	{
		cv::imshow("img", img.mat);
		k = cv::waitKey(100);
		
		switch (k)
		{
		case 97:
			img.addX(0.1);
			img.draw();
		case 122:
			img.addY(0.1);
			img.draw();
		case 101:
			img.addZ(0.1);
			img.draw();
		case 27:
			cv::destroyAllWindows();
			break;
		}
		k = -1;
	}
}