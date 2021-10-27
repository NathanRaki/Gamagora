#pragma once

#include <fstream>
#include <iostream>
#include <cmath>

class Image
{
public:
	Image() {}
	Image(int height, int width);
	~Image();

	struct RGB
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
	};

	void set_width(int width) { this->width = width; }
	void set_height(int height) { this->height = height; }
	void set_version(std::string version) { this->version = version; }

	void save(std::string file_name);
	void read(std::string file_name);

	void resize(int height, int width);

	void delete_image();

	RGB** image = nullptr;

private:
	int width = 0;
	int height = 0;
	std::string version = "P6";

	void create_image();
};