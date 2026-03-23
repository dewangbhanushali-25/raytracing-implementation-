//
// Created by dew on 6/10/25.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "hittable.h"
#include "material.h"
class camera {
public:
    double aspect_ratio=1.0;//ratio of image width over height

    int  image_width = 100;// randered image width of in pixel count
    int samples_per_pixel = 10;//count of random samples for each pixel
    int max_depth = 10;//maximum recursion depth for ray tracing
    double vfov = 90; //vertical view angle (field of view)
    point3 lookfrom = point3(0,0,0); //point camera is looking from
    point3 lookat = point3(0,0,-1);//point camera is looking at
    vec3    vup = vec3(0,1,0);//camera-relative "up" ray_direction                               






    //public camera parameters here
    void render(const hittable& world) {
        initialize();
        std::cout <<"P3\n" << image_width <<" " <<image_height << "\n255\n";
        for (int j =0; j<image_height; j++) {
            std::clog <<"\rScanlines remaining: " << (image_height - j) << ' ' <<std::flush;
            for (int i =0; i<image_width; i++) {
                color pixel_color(0,0,0);
                for (int s =0; s<samples_per_pixel; s++) {
                    ray r = get_ray(i,j);
                    pixel_color += ray_color(r,max_depth,world);

                }
                write_color(std::cout , pixel_samples_scale * pixel_color);

            }

        }
        std::clog <<"\rDone                     \n";



    }


private:
    int image_height; // rendered image height
    double  pixel_samples_scale;

    point3 center;//camera center

    point3 pixel00_loc;//location of pixel 0,0
    vec3 pixel_delta_u;//offset to pixel to the right
    vec3 pixel_delta_v;//offset to pixel below
    vec3 u,v,w; //camera frame basis vectors






    //private camera variables
    void initialize() {
        image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;
        center = point3(0,0,0);
        pixel_samples_scale = 1.0 / samples_per_pixel;


        center = lookfrom;
        

        //Determine viewport dimensions
        auto focal_length = (lookfrom-lookat).length();
        auto theta = degrees_to_radians(vfov);
        auto h = std :: tan(theta/2);
        auto viewport_height = 2*h*focal_length;
        auto viewport_width = viewport_height * (double(image_width)/image_height);
        
        //calculate the u,v,w unit basis vectors for the camera coordinate frame
        w = unit_vector(lookfrom - lookat);
        u = unit_vector(cross(vup,w));
        v = cross(w,u);



        //calculate the vectors across the horizontal and down the vertical viewport edges.
        vec3 viewport_u = viewport_width * u;//vector across viewport horizontal edgess

        vec3 viewport_v = viewport_height* -v;//vector down viewport vertical edges

        




        //calculate the horizontal and vertical delta vectors from pixel to pixel
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;
        // calculate the location of the upper left pixel.
        auto viewport_upper_left = center - (focal_length * w) - viewport_u/2 - viewport_v/2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    }

    ray get_ray(int i, int j) const {
        //construct a camera ray originationg from the origiin and directed at the randomlly sampled
        //point around the pixel location i ,j
         auto offset = sample_square();
         auto pixel_sample = pixel00_loc
                            + pixel_delta_u * (i + offset.x())
                            + pixel_delta_v * (j + offset.y());
        auto  ray_origin = center;
        auto ray_direction = pixel_sample - ray_origin;
        return ray(ray_origin,ray_direction);
    }
    static vec3 sample_square() {
        //returns the vector to a random point in the [-}
        return vec3(random_double() -0.5, random_double()-0.5 , 0);

    }






    color ray_color(const ray& r,int depth, const hittable& world) const {
        //IF weve exceded the ray bounce limit, no more light is gathered.
        hit_record rec;
        if (depth <= 0) {
            return color(0,0,0);

        }
        if (world.hit(r, interval(0.001, infinity), rec)) {
            ray scattered;
            color attenuation;
            if (rec.mat ->scatter(r,rec,attenuation,scattered))
                return attenuation * ray_color(scattered,depth-1,world);
            return color(0,0,0);
            


        }
        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);

    }
};

#endif //CAMERA_H
