#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
public:
	ray() {}

	ray(const vec3 p, const vec3 d) : point(p), dir(d) {}

	const vec3& origin() const
	{
		return point;
	}

	const vec3& direction() const
	{
		return dir;
	}

	vec3 pointAlong(double x) const
	{
		return point + x * dir;
	}

private:
	vec3 point;
	vec3 dir;
};

#endif RAY_H