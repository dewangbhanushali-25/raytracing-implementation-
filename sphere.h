//
// Created by dew on 6/4/25.
//

#ifndef SPHERE_H
#define SPHERE_H
#include "hittable.h"
//#include "vec3.h"
#include "rtweekend.h"


class sphere : public hittable {
public:
    sphere(const point3& center, double radius) : center(center),radius(std::fmax(0,radius)){}
    bool hit(const ray& r, interval ray_t,  hit_record& rec) const override {
        vec3 oc = r.origin() - center;
        auto a = r.direction().length_squared(); // FIXED: should be double!
        auto h = dot(oc, r.direction());
        auto c = oc.length_squared() - radius*radius;
        auto discriminant = h*h - a*c;
        if (discriminant < 0) return false;
        auto sqrtd = std::sqrt(discriminant);
        // find the nearest root that lies in the acceptable range;
        auto root = (-h - sqrtd)/a;
        if (!ray_t.surrounds(root)) {
            root = (-h + sqrtd)/a;
            if (!ray_t.surrounds(root))
                return false;
        }
        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center)/radius;
        rec.set_face_normal(r, outward_normal);
        return true;
    }
    private:
    point3 center;
    double radius;



    };


#endif //SPHERE_H