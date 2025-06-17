//
// Created by dew on 6/18/25.
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"
#include "rtweekend.h"
class material {
public:
    virtual ~material() = default;
    virtual bool scatter(
        const ray& r_in, const hit_record& rec,color& attenuation, ray& scattered
        )const {
        return false;
    }
};
class lambertian : public material {
public :
    lambertian(const color& albedo) : albedo(albedo) {}

};

#endif //MATERIAL_H
