#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include <cstdlib>
#include<ctime>

const float PI = 3.14159265359f;
const float TAU = 6.28318530717f;

void random(cv::Mat& img)
{
	for (int x = 0; x < img.rows; x++)
	{
		for (int y = 0; y < img.cols; y++)
		{
			cv::Vec3b& color = img.at<cv::Vec3b>(x, y);

			color[0] = std::rand() % 256;
			color[1] = std::rand() % 256;
			color[2] = std::rand() % 256;
		}
	}
}

void gradient(cv::Mat& img, double r, double g, double b)
{
	for (int x = 0; x < img.rows; x++)
	{
		for (int y = 0; y < img.cols; y++)
		{
			cv::Vec3b& color = img.at<cv::Vec3b>(x, y);

			color[0] = (x * y / (pow(img.cols, 2))) * 0.0;
			color[1] = (x * y / (pow(img.cols, 2))) * 255.0;
			color[2] = (x * y / (pow(img.cols, 2))) * 0.0;
		}
	}
}

void circle(cv::Mat& img)
{
	cv::Point center = cv::Point(img.rows / 2, img.cols / 2);
	for (float x = -PI; x < PI; x += 0.01)
	{
		int i = std::cos(x) * img.rows / 3 + center.x;
		int j = std::sin(x) * img.cols / 3 + center.y;
		for (int a = -5; a < 5; a++)
		{
			for (int b = -5; b < 5; b++)
			{
				cv::Vec3b& color = img.at<cv::Vec3b>(i+a, j+b);
				color[0] = 255;
				color[1] = 0;
				color[2] = 0;
			}
		}
	}
}

void damier(cv::Mat& img)
{
	int w = 8;
	int wl = img.rows / w;
	int ll = img.cols / w;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < w; j++)
		{
			for (int x = wl * i; x < wl * (i+1); x++)
			{
				for (int y = ll * j; y < ll * (j + 1); y++)
				{
					cv::Vec3b color;
					if ((i + j) % 2 == 0) { color = cv::Vec3b(0, 0, 0); }
					else if ((i + j) % 2 == 1) { color = cv::Vec3b(255, 255, 255); }
					cv::Vec3b& pixel = img.at<cv::Vec3b>(x, y);
					pixel[0] = color[0];
					pixel[1] = color[1];
					pixel[2] = color[2];
				}
			}
		}
	}
}
/*
int main()
{
	std::srand(std::time(nullptr));
	cv::Mat img(400, 600, CV_8UC3, cv::Vec3b(0, 0, 0));
	
	random(img);
	cv::imshow("random", img);
	cv::imwrite("random.png", img);

	gradient(img, 0, 0, 255);
	cv::imshow("gradient", img);
	cv::imwrite("gradient.png", img);

	circle(img);
	imshow("img", img);
	imwrite("circle.png", img);

	damier(img);
	imshow("img", img);
	imwrite("damier.png", img);

	cv::waitKey();

	return 0;
}
*/
