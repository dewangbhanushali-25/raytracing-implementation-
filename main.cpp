//#include "color.h"
//#include "ray.h"
//#include "vec3.h"

//#include <iostream>
#include "hittable.h"
#include "sphere.h"
#include "hittable_list.h"
#include "rtweekend.h"
#include "camera.h"
#include "material.h"

double hit_sphere(const point3& center , double radius , const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = h*h - a*c;
    if (discriminant < 0)
    {
    return -1.0;
    }else
        {
        return (-h  - std::sqrt(discriminant))/(a);
    }

}



int main() {
    hittable_list world;

    // Ground
    auto mat_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100, mat_ground));

    // Center - diffuse
    auto mat_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    world.add(make_shared<sphere>(point3(0, 0, -1.2), 0.5, mat_center));

    // Left - shiny metal
    auto mat_left = make_shared<metal>(color(0.8, 0.8, 0.8), 0.0);
    world.add(make_shared<sphere>(point3(-1.0, 0, -1.2), 0.5, mat_left));

    // Right - gold metal
    auto mat_right = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);
    world.add(make_shared<sphere>(point3(1.0, 0, -1.2), 0.5, mat_right));

    // Extra - brushed silver behind
    auto mat_back_left = make_shared<metal>(color(0.9, 0.9, 0.9), 0.05);
    world.add(make_shared<sphere>(point3(-0.5, 0.3, -2.0), 0.4, mat_back_left));

    // Extra - copper with fuzz
    auto mat_back_right = make_shared<metal>(color(0.7, 0.3, 0.1), 0.1);
    world.add(make_shared<sphere>(point3(0.5, 0.3, -2.0), 0.4, mat_back_right));

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 800;
    cam.samples_per_pixel = 200;
    cam.max_depth = 50;
    cam.render(world);
}


