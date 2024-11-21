#pragma once

#include "Point2D.hpp"
#include "Object2D.hpp"
#include "Garden.hpp"

#include <vector>

namespace App {

class Camera : public Object2D {
public:
    float fov;
    float far_length;
    float near_length;
    bool is_selected;

    Camera() = default;
    
    void set_fov(float fov);
    void set_far_length(float far_length);
    void set_near_length(float near_length);
    void set_segments(size_t segments);
    size_t get_segments();

    void render();

    static std::vector<Camera *> cameras;
    static Camera *selected;
    static void select(Camera &cam);

    static void add(Camera &cam);

    void raycast(Garden& g);

private:
    std::vector<float> segments;
    
    Point2D head, near1, near2;
    float side_far_length, side_near_length;
    float angle1, angle2;
    Point2D far1, far2;


    void update_values();
};

}
