#ifndef SPHERE_H
#define SPHERE_H

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

	bool hit(const ray& r) const
	{
		auto oc = r.origin() - center;
		auto a = dot(r.direction(), r.direction());
		auto b = 2 * dot(r.direction(), oc);
		auto c = dot(oc, oc) - radius * radius;
		auto discriminant = b * b - 4 * a * c;

		return (discriminant >= 0);
	}

private:
	vec3 center;
	double radius;
	vec3 color;
};

#endif SPHERE_H