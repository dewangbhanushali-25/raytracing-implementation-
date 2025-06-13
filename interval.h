//
// Created by dew on 6/8/25.
//

#ifndef INTERVAL_H
#define INTERVAL_H
#include "rtweekend.h"

class interval {
    public:
    double min;
    double max;
    interval() : min(+std::numeric_limits<double>::infinity()),
                 max(-std::numeric_limits<double>::infinity()) {}
    interval(double min, double max) : min(min), max(max) {}

    double size() const {
        return max - min;

    }
    bool contains(double x) const {
        return min<= x && x <= max;
    }
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
    static const interval empty , universe;


};
const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);
#endif //INTERVAL_H
