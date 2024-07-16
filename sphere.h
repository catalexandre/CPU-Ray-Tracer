#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "vec3.h"

using namespace std;


class sphere
{
public:
	sphere(const vec3& c, double r, const vec3& col) : center(c), radius(r), color(col) {}

	const vec3& getCenter() const
	{
		return center;
	}

	const double getRadius() const
	{
		return radius;
	}

	const vec3& getColor() const
	{
		return color;
	}

	double hit(const ray& r) const
	{
		auto oc = r.origin() - center;
		auto a = dot(r.direction(), r.direction());
		auto b = 2 * dot(r.direction(), oc);
		auto c = dot(oc, oc) - radius * radius;
		auto discriminant = b * b - 4 * a * c;

		if (discriminant < 0)
		{
			return discriminant;
		}

		else
		{
			return (b - sqrt(discriminant)) / (2.0 * a);
		}
	}

private:
	vec3 center;
	double radius;
	vec3 color;
};

#endif SPHERE_H