//#include "color.h"
//#include "ray.h"
//#include "vec3.h"

//#include <iostream>
#include "hittable.h"
#include "sphere.h"
#include "hittable_list.h"
#include "rtweekend.h"
#include "camera.h"


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
    world.add(make_shared<sphere>(point3(0,0,-1),0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1),100));
    camera cam;
    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 400;
    cam.render(world);


}