/*
	ray.h
	Create ray class

	Modified by: Hannah Colquhoun
	Modified because: Inlcuding code from Peter Shirley's Ray Tracing in One Weekend: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*/

//The following lines (10 to 40) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include <iostream>

//Ray class
class ray {
public:
	//construcots
	ray() {}
	ray(const point3& origin, const vec3& direction)
		: orig(origin), dir(direction)
	{}

	//get origin or direction
	point3 origin() const { return orig; }
	vec3 direction() const { return dir; }

	//point location?
	point3 at(double t) const 
	{
		return orig + t * dir;
	}

public:
	point3 orig;
	vec3 dir;
};

#endif