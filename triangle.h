//
// Created by dew on 6/20/25.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "hittable.h"
class triangle : public hittable {
public:
    point3 v0,v1,v2;
    shared_ptr<material> mat;
    
};

#endif //TRIANGLE_H
