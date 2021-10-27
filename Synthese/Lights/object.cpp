#include "object.h"

std::ostream& operator<<(std::ostream& os, const Sphere& s)
{
	os << "Sphere { Rayon: " << s.position() << ", Centre: " << s.radius() << "}";
	return os;
}
std::ostream& operator<<(std::ostream& os, const Rayon& r)
{
	os << "Rayon { Origine: " << r.position() << ", Direction: " << r.direction() << "}";
	return os;
}

std::optional<float> Rayon::intersect(const Sphere& s)
{
	float A = scalar(dir, dir);
	float B = 2.0 * scalar(position() - s.position(), dir);
	float C = scalar(position() - s.position(), position() - s.position()) - s.radius() * s.radius();
	float D = B * B - 4.0 * A * C;

	if (D == 0) { return -B / (2.0 * A); }
	else if (D > 0) { return abs((-B - sqrt(D)) / (2.0 * A)); }
	else { return std::nullopt; }
}