//
// Created by dew on 6/4/25.
//

#ifndef SPHERE_H
#define SPHERE_H
#include "hittable.h"
#include "vec3.h"
class sphere : public hittable {
public:
    sphere(const point3& center, double radius) : center(center),radius(std::fmax(0,radius)){}
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_recors& rec) const override {
        vec3 oc = center - r.origin();
        auto a
    }
{

}

}

#endif //SPHERE_H