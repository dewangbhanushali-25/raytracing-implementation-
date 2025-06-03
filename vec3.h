#ifndef VEC3_H

#define VEC3_H
//preprocessor directives that prevent multiple inclusions of the same header file
// This file defines a 3D vector class with basic operations
// and includes necessary libraries for mathematical operations.
#include <cmath>
#include <iostream>
//iosstream for input /output operations
//cmath for mathematical functions



class vec3 { //class vec3 defines a 3D vector with three components (x, y, z)
   public:
   double e[3];//arrray with three eleemnts to store double values of x, y,z
   vec3(): e{0, 0, 0} {}//default constructor to initilaise the vector to all zeros i.e. x=0, y=0, z=0
   vec3(double e0, double e1,double e2):e{e0, e1, e2} {}//constructor to initialise the vector with given values
   double x() const {return e[0];}//tell the compiler to return the value of x
   double y() const {return e[1];}//tell the compiler to return the value of y
   double z() const {return e[2];}//tell the compiler to return the value of z

   vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);}
   double operator[](int i) const {return e[i];}
   double& operator[](int i) {return e[i];}
    vec3& operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }
    vec3& operator/=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
    }

    vec3& operator*=(double t) {
        return *this *=1/t;

    }
    double length() const {
        return std::sqrt(length_squared());


    }
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};
//point 3 is just an alias for vec3, but useful for geometric clarity code.
using point3 = vec3;

// vector utility function

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2];

}

inline vec3 operator+(const vec3& u, const vec3& v){
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}
inline vec3 operator-(const vec3& u,const vec3& v){
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);

}

inline vec3 operator*(const vec3& u, const vec3& v){
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);

}

inline vec3 operator*(double t,const vec3&  v){
    return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);

}
inline vec3 operator*(const vec3& v,double t){
    return t*v;

}
inline vec3 operator/(const vec3& v, double t){
    return(1/t)*v;

}

inline vec3 cross(const vec3& u, const vec3& v){
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}
inline vec3 unit_vector(const vec3& v){
    return v / v.length();

}
#endif
