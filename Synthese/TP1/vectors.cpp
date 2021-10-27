#include <iostream>

class Vector
{
public:
	Vector(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }
	Vector add(Vector v) { return Vector(this->x + v.x, this->y + v.y, this->z + v.z); }
	Vector sub(Vector v) { return Vector(this->x - v.x, this->y - v.y, this->z - v.z); }
	Vector mult(int scal) { return Vector(this->x * scal, this->y * scal, this->z * scal); }
	int prodscal(Vector v) { return (this->x * v.x) + (this->y * v.y) + (this->z * v.z); }
	double norme() { return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)); }

	int x, y, z;
};

class Point
{
public:
	Point(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }
	Vector direction(Point p) { return Vector(p.x - this->x, p.y - this->y, p.z - this->z); }

	int x, y, z;
};

int main()
{
	Vector a = Vector(1, 0, -1);
	Vector b = Vector(1, 1, 0);
	std::cout << "Vector a : [x: " << a.x << ", y: " << a.y << ", z: " << a.z << "]" << std::endl;
	std::cout << "Vector b : [x: " << b.x << ", y: " << b.y << ", z: " << b.z << "]" << std::endl;
	Vector c = a.add(b);
	std::cout << "Vector a+b : [x: " << c.x << ", y: " << c.y << ", z: " << c.z << "]" << std::endl;
	c = a.sub(b);
	std::cout << "Vector a-b : [x: " << c.x << ", y: " << c.y << ", z: " << c.z << "]" << std::endl;
	c = a.mult(2);
	std::cout << "Vector 2*a : [x: " << c.x << ", y: " << c.y << ", z: " << c.z << "]" << std::endl;
	std::cout << "Result of a.b : " << a.prodscal(b) << std::endl;
	std::cout << "Size of a : " << a.norme() << std::endl;
}