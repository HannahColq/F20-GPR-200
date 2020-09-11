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

#include "gpro/gpro-math/gproVector.h"

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

int main(int const argc, char const* const argv[])
{
	/*
	testVector();

#ifdef __cplusplus
	//opening and writing to a file in C++
	std::ofstream file("firstimage.ppm");	//Open file for writing
	std::string test = "hello";			//create a string
	file << test << std::endl;			//output string (and newline)
	file.close();						//done, close file
#else  // !__cplusplus
	// C file io includes
#endif // #__cplusplus
*/
	//Open file for writing
	std::ofstream file("firstimage.ppm");
	
	//The following lines (86 to 113) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
	//Altered to print directly to file instead of cout. Removed all instances of auto.
	
	//Set Image width and height
	const int image_width = 256;
	const int image_height = 256;

	//Render Image
	file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	//Sets color of each pixel from left to right, top to bottom based on location
	for (int j = image_height - 1; j >= 0; j--)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			//Sets red, green and blue values based on the location the pixel is in the image
			color pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
			write_color(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone.\n";

	//printf("\n\n");
	system("pause");
}
