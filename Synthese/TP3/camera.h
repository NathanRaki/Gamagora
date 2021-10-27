#pragma once
#include "vector.h"
#include <vector>
#include <opencv2/opencv.hpp>
#include <limits>

const double pi = 3.14159265358979323846;

class Image
{
public:
	Image();
	void addX(float);
	void addY(float);
	void addZ(float);
	void draw();
	cv::Mat mat;

private:
	int width, length;
	Vec test;
	Sphere sphere;
};