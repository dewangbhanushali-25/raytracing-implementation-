#ifndef COLOR_H
#define COLOR_H
#include "vec3.h"
#include <iostream>

using color = vec3;

void write_color(std::ostream& out,const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    // TRANSLATE THE [0,1] COMPONENTS TO [0,255]
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);
    //write out the pixel color COMPONENTS
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif
