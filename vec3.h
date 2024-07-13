#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3
{
public:
	double component[3];
	
	vec3() : component{ 0, 0, 0 } {}

	vec3(double component0, double component1, double component2) : component{ component0, component1, component1 } {}

	double x() const { return component[0]; }
	double y() const { return component[1]; }
	double z() const { return component[2]; }

	

};

#endif VEC3_H
