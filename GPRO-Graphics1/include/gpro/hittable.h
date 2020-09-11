/*
	hittable.h
	Create hit record and hittable class

	Modified by: Hannah Colquhoun
	Modified because: Inlcuding code from Peter Shirley's Ray Tracing in One Weekend: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*/

//The following lines (10 to 35) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

//hit record struct
struct hit_record {
	point3 p;
	vec3 normal;
	double t;
	bool front_face;
	//determines what side the ray hit the sphere
	inline void set_face_normal(const ray& r, const vec3& outward_normal) 
	{
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

//hittable class
class hittable {
public:
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif