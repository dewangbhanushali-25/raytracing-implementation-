#ifndef COLOR_H
#define COLOR_H
#include "vec3.h"
//#include <iostream>
#include "rtweekend.h"
#include "interval.h"
using color = vec3;

void write_color(std::ostream& out,const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    // TRANSLATE THE [0,1] COMPONENTS TO [0,255]
   static const interval intensity(0.000,0.999);

    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    //write out the pixel color COMPONENTS
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif
