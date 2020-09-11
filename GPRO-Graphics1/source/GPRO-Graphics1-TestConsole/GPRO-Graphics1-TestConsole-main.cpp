/*
   Copyright 2020 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/*
	GPRO-Graphics1-TestConsole-main.c/.cpp
	Main entry point source file for a Windows console application.

	Modified by: Hannah Colquhoun
	Modified because: Inlcuding code from Peter Shirley's Ray Tracing in One Weekend: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "gpro/color.h"
#include "gpro/vec3.h"
#include "gpro/ray.h"

//#include "gpro/gpro-math/gproVector.h"
/*
//Courtesy of Daniel Buckstein
void testVector()
{
	// test array vector initializers and functions
	float3 av, bv, cv, dv;
	vec3default(av);								// -> a = (0, 0, 0)
	vec3init(bv, 1.0f, 2.0f, 3.0f);					// -> b = (1, 2, 3)
	vec3copy(dv, vec3init(cv, 4.0f, 5.0f, 6.0f));	// -> d = c = (4, 5, 6)
	vec3copy(av, dv);								// a = d			-> a = (4, 5, 6)
	vec3add(dv, bv);								// d += b			-> d = (4 + 1, 5 + 2, 6 + 3) = (5, 7, 9)
	vec3sum(dv, bv, bv);							// d = b + b		-> d = (1 + 1, 2 + 2, 3 + 3) = (2, 4, 6)
	vec3add(vec3sum(dv, cv, bv), av);				// d = c + b + a	-> d = (4 + 1 + 4, 5 + 2 + 5, 6 + 3 + 6) = (9, 12, 15)

#ifdef __cplusplus
	// test all constructors and operators
	vec3 a, b(1.0f, 2.0f, 3.0f), c(cv), d(c);		// default; init; copy array; copy
	a = d;											// assign						-> a = (4, 5, 6)
	d += b;											// add assign					-> d = (5, 7, 9)
	d = b + b;										// sum, init, assign			-> d = (2, 4, 6)
	d = c + b + a;									// sum, init, sum, init, assign	-> d = (9, 12, 15)
#endif	// __cplusplus
}

//Courtesy of Daniel Buckstein
#ifdef __cplusplus
//C++ file io includes
#include <fstream>
#include <string>
#else  // !__cplusplus
// C file io includes
#endif // #__cplusplus
*/

//The following lines (71 to 77) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Removed all instances of auto.
color ray_color(const ray& r)
{
	vec3 unit_direction = unit_vector(r.direction());
	double t = 0.5 * (unit_direction.y() + 1.0);
	//return color based on ray location?
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(1.0, 0.7, 0.5);
}

int main(int const argc, char const* const argv[])
{	
	//The following lines (84 to 116) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
	//Removed all instances of auto.
	
	//Set Image width and height using aspect ratio
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	//Set up camera view
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;
	point3 origin = point3(0, 0, 0);
	vec3 horizontal = vec3(viewport_width, 0, 0);
	vec3 vertical = vec3(0, viewport_height, 0);
	vec3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

	//Render Image
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	//Sets color of each pixel from left to right, top to bottom based on location
	for (int j = image_height - 1; j >= 0; j--)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			//Sets red, green and blue values based on the location the pixel is in the image and direction of the ray
			double u = double(i) / (image_width - 1);
			double v = double(j) / (image_height - 1);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone.\n";

	//printf("\n\n");
	system("pause");
}
