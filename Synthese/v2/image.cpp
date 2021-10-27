#include "image.h"

Image::Image(int height, int width)
{
	set_height(height);
	set_width(width);
	create_image();
}

Image::~Image() { delete_image(); }


void Image::save(std::string file_name)
{
	std::ofstream output(file_name, std::ios::binary);

	if (output.is_open())
	{
		output << version << std::endl;
		output << width << std::endl;
		output << height << std::endl;
		output << 255 << std::endl;

		if (version == "P3")
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
				{
					output << (int)image[i][j].r << ' ';
					output << (int)image[i][j].g << ' ';
					output << (int)image[i][j].b << ' ';
				}
		}
		else
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
					output.write((char*)&image[i][j], sizeof(RGB));

		output.close();
	}
}

void Image::read(std::string file_name)
{
	std::ifstream input(file_name, std::ios::binary);

	if (input.is_open())
	{
		int color;
		char ver[3];

		input.read(ver, 2);
		version = ver;
		input >> width;
		input >> height;
		input >> color;
		input.read(ver, 1);

		create_image();

		int box;
		if (version == "P3")
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
				{
					input >> box;
					image[i][j].r = box;

					input >> box;
					image[i][j].g = box;

					input >> box;
					image[i][j].b = box;
				}
		}
		else
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
					input.read((char*)&image[i][j], sizeof(RGB));
		}

		input.close();
	}
}

void Image::create_image()
{
	if (image != nullptr)
		delete_image();

	image = new RGB * [height];

	for (int i = 0; i < height; i++)
	{
		image[i] = new RGB[width];
		for (int j = 0; j < width; j++)
		{
			image[i][j].r = 200;
			image[i][j].g = 0;
			image[i][j].b = 255;
		}
	}
}

void Image::delete_image()
{
	if (image != nullptr)
	{
		for (int i = 0; i < height; i++)
			delete image[i];

		delete image;
	}
}

void Image::resize(int height, int width)
{
	RGB** image_resized = new RGB * [height];
	for (int i = 0; i < height; i++)
	{
		image_resized[i] = new RGB[width];

		for (int j = 0; j < height; j++)
		{
			image_resized[i][j].r = 200;
			image_resized[i][j].g = 0;
			image_resized[i][j].b = 255;
		}
	}

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			image_resized[i][j] = image[i * this->height / height][j * this->width / width];

	delete_image();
	image = image_resized;

	this->height = height;
	this->width = width;
}