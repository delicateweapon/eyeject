#include "Object2D.hpp"
#include "App.hpp"

#include <cstdint>
#include <cmath>

Object2D_Translate::Object2D_Translate(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
    this->position = Point2D(x, y);
    this->width = width;
    this->height = height;
}

void Object2D_Translate::set_position(uint16_t &x, uint16_t &y)
{
    this->position.x = x;
    this->position.y = y;
}

void Object2D_Translate::set_position(Point2D &p)
{
    this->position.x = p.x;
    this->position.y = p.y;
}

void Object2D_Translate::place_at_window_center()
{
    this->position.x = (App::Window::width / 2.0) - this->width;
    this->position.y = (App::Window::height / 2.0) - this->height;
    this->position.x = 100;
    this->position.y = 10;
}

void Object2D_Translate::move_x(uint16_t delta_x)
{
    int16_t new_x = this->position.x + delta_x;
    if (new_x < 0) {
        return;
    }
    if (new_x > App::Window::width - this->width) {
        return;
    }
    this->position.x = new_x;
}

void Object2D_Translate::move_y(uint16_t delta_y)
{
    int16_t new_y = this->position.y + delta_y;
    if (new_y < 0) {
        return;
    }
    if (new_y > App::Window::height - this->height) {
        return;
    }
    this->position.y = new_y;
}

void Object2D::set_look_angle(float look_angle) {
    this->look_angle = look_angle;    
}

void Object2D::turn_anticlockwise(float delta_t)
{
    this->look_angle += delta_t;
    /* TODO */
}

void Object2D::turn_clockwise(float delta_t)
{
    this->look_angle -= delta_t;
    /* TODO */
}

void Object2D::move(float distance, Direction d)
{
    switch (d) {
    case FORWARD:
        this->position.x += distance * std::cos(this->look_angle);
        this->position.y += distance * (-1) * std::sin(this->look_angle);
        break;

    case BACKWARD:
        this->position.x -= distance * std::cos(this->look_angle);
        this->position.y -= distance * (-1) * std::sin(this->look_angle);
        break;

    case RIGHT:
        this->position.x += distance * std::sin(this->look_angle);
        this->position.y += distance * (-1) * std::cos(this->look_angle);
        break;

    case LEFT:
        this->position.x -= distance * std::sin(this->look_angle);
        this->position.y -= distance * (-1) * std::cos(this->look_angle);
        break;
    }
}
