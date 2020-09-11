/*
	hittable_list.h
	Create a class for a list of hittable objects

	Modified by: Hannah Colquhoun
	Modified because: Inlcuding code from Peter Shirley's Ray Tracing in One Weekend: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*/

//The following lines (10 to 57) are courtesy of Peter Shirley from his book Ray Tracing in One Weekend https://raytracing.github.io/books/RayTracingInOneWeekend.html
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

//class for hittable objects list
class hittable_list : public hittable {
public:
	//constructors
	hittable_list() {}
	hittable_list(shared_ptr<hittable> object) { add(object); }

	//functions to add to or clear the list
	void clear() { objects.clear(); }
	void add(shared_ptr<hittable> object) { objects.push_back(object); }

	virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override;

public:
	std::vector<shared_ptr<hittable>> objects;
};

//records if something is hit and adds it the the list of hittable objects and which is closest
bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{
	hit_record temp_rec;
	bool hit_anything = false;
	double closest_so_far = t_max;

	for (const hittable_list& object : objects)
	{
		if (object.hit(r, t_min, closest_so_far, temp_rec))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hit_anything;
}

#endif