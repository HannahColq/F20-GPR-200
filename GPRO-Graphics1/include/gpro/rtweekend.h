/*
	rtweekend.h
	Header containing commonly used constants and functions

	Modified by: Hannah Colquhoun
	Modified because: Inlcuding code from Peter Shirley's Ray Tracing in One Weekend: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*/

//The following lines (11 to 38) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Added comments explaining code.
#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

//using 
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

//constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//functions
inline double degrees_to_radians(double degrees)
{
	return degrees * pi / 180.0;
}

//common headers
#include "ray.h"
#include "vec3.h"

#endif