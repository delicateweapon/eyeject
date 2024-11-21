#pragma once

#include "Point2D.hpp"

#include <cstdint>

class Object2D_Translate {
public:
    Point2D position;
    uint16_t width = 0;
    uint16_t height = 0;

    bool bounded = false;
    Object2D_Translate *bound_parent;

    Object2D_Translate() = default;
    Object2D_Translate(float x, float y, uint16_t width, uint16_t height);

    void set_position(float& x, float& y);
    void set_position(Point2D &p);

    void place_at_window_center();
    void bound(Object2D_Translate& o);
};

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
} Direction;

class Object2D : public Object2D_Translate {
public:

    float look_angle;

    Object2D() = default;

    void set_look_angle(float look_angle);
    void turn_anticlockwise(float delta_t);
    void turn_clockwise(float delta_t);

    void move(float distance, Direction d);
};

