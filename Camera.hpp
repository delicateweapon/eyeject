#pragma once

#include "Point2D.hpp"

#include <vector>

class Camera {
public:
    float fov;
    float look_angle;
    float far_length;
    Point2D position;
    bool selected;

    static std::vector<Camera *> cameras;
    static Camera *selected_camera;

    Camera() = default;
    Camera(float fov, float look_angle, float far_length, Point2D position);

    static void select(Camera &cam);
};
