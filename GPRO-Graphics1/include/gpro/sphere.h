/*
	sphere.h
	Create sphere class

	Modified by: Hannah Colquhoun
	Modified because: Inlcuding code from Peter Shirley's Ray Tracing in One Weekend: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*/

//The following lines (11 to 66) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Added comments explaining code.
#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

//Sphere class
class sphere : public hittable {
public:
	sphere() {}
	sphere(point3 cen, double r) : center(cen), radius(r) {};

	virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override;
	
public:
	point3 center;
	double radius;
};

//calculates if ray hits sphere
bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{
	vec3 oc = r.origin() - center;
	double a = r.direction().length_squared();
	double half_b = dot(oc, r.direction());
	double c = oc.length_squared() - radius * radius;
	double discriminant = half_b * half_b - a * c;

	if (discriminant > 0)
	{
		double root = sqrt(discriminant);

		double temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.at(rec.t);
			vec3 outward_normal = (rec.p - center) / radius;
			rec.set_face_normal(r, outward_normal);
			return true;
		}

		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.at(rec.t);
			vec3 outward_normal = (rec.p - center) / radius;
			rec.set_face_normal(r, outward_normal);
			return true;
		}
	}
	return false;
}

#endif