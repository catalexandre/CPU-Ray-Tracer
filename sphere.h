#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "vec3.h"
#include "solid.h"

using namespace std;


class sphere : public solid
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

	const bool hit(const ray& r) const override
	{
		auto oc = r.origin() - center;
		auto a = r.direction().lengthSquared();
		auto b = dot(r.direction(), oc);
		auto c = oc.lengthSquared() - radius * radius;
		auto discriminant = b * b - a * c;

		if (discriminant < 0)
		{
			return discriminant;
		}

		else
		{
			return (-b - sqrt(discriminant)) / a;
		}
	}

private:
	vec3 center;
	double radius;
	vec3 color;
};

#endif SPHERE_H