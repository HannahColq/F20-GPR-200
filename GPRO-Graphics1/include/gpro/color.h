/*
	color.h
	Create color function to print colors per pixel

	Modified by: Hannah Colquhoun
	Modified because: Inlcuding code from Peter Shirley's Ray Tracing in One Weekend: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*/

//The following lines (10 to 24) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

//formats and prints colors for each pixel
void write_color(std::ostream& out, color pixel_color) 
{
	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif