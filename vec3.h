#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3
{
public:
	double component[3];
	
	vec3() : component{ 0, 0, 0 } {}

	vec3(double component0, double component1, double component2) : component{ component0, component1, component2 } {}

	double x() const { return component[0]; }
	double y() const { return component[1]; }
	double z() const { return component[2]; }

	double operator[](int i) const
	{
		return component[i];
	}

	double& operator[](int i)
	{
		return component[i];
	}

	vec3 operator-() const
	{
		return vec3(-component[0], -component[1], -component[2]);
	}

	vec3& operator+=(const vec3& v) {
		component[0] += v.component[0];
		component[1] += v.component[1];
		component[2] += v.component[2];
		return *this;
	}

	vec3& operator*=(double x) {
		component[0] *= x;
		component[1] *= x;
		component[2] *= x;
		return *this;
	}

	vec3& operator/=(double x)
	{
		return *this *= 1 / x;
	}

	double length() const
	{
		return std::sqrt(lengthSquared());
	}

	double lengthSquared() const
	{
		return component[0] * component[0] + component[1] * component[1] + component[2] * component[2];
	}


	
};

inline std::ostream& operator<<(std::ostream& out, const vec3& v)
{
	return out << v.component[0] << ' ' << v.component[1] << ' ' << v.component[2];
}

inline vec3 operator+(const vec3& u, const vec3& v)
{
	return vec3(u.component[0] + v.component[0], u.component[1] + v.component[1], u.component[2] + v.component[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v)
{
	return vec3(u.component[0] - v.component[0], u.component[1] - v.component[1], u.component[2] - v.component[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v)
{
	return vec3(u.component[0] * v.component[0], u.component[1] * v.component[1], u.component[2] * v.component[2]);
}

inline vec3 operator*(double x, const vec3& v)
{
	return vec3(x * v.component[0], x * v.component[1], x * v.component[2]);
}

inline vec3 operator*(const vec3& v, double x)
{
	return x * v;
}

inline vec3 operator/(const vec3& v, double x)
{
	return (1 / x) * v;
}

inline double dot(const vec3& u, const vec3& v) {
	return u.component[0] * v.component[0]
		+ u.component[1] * v.component[1]
		+ u.component[2] * v.component[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.component[1] * v.component[2] - u.component[2] * v.component[1],
		u.component[2] * v.component[0] - u.component[0] * v.component[2],
		u.component[0] * v.component[1] - u.component[1] * v.component[0]);
}

inline vec3 unitVector(const vec3& v)
{
	return v / v.length();
}

#endif VEC3_H
