#pragma once

#include "Point2D.hpp"
#include "Direction.hpp"

#include <vector>

namespace App {

class Camera {
public:
    float fov;
    float look_angle;
    float far_length;
    Point2D position;
    bool is_selected;

    Camera() = default;
    Camera(float fov, float look_angle, float far_length, Point2D position);

    void set_fov(float fov);
    void set_position(float x, float y);
    void set_position(Point2D& p);
    void set_look_angle(float look_angle);
    void set_far_length(float far_length);

    void move_x(float delta_x);
    void move_y(float delta_y);

    void move(float distance, Direction d);
    void rotate(float delta_angle);

    void render();

    static std::vector<Camera *> cameras;
    static Camera *selected;
    static void select(Camera &cam);

    static void add(Camera& cam);

private:
    Point2D head;
    float side_length;
    float angle1, angle2;
    Point2D side1, side2;

    void update_values();
};

}
