#include "Object2D.hpp"
#include "App.hpp"
#include "constants.hpp"

#include <cmath>
#include <cstdint>

Object2D_Translate::Object2D_Translate(float x, float y, uint16_t width, uint16_t height)
{
    this->position = Point2D(x, y);
    this->width = width;
    this->height = height;
}

void Object2D_Translate::set_position(float &x, float &y)
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
    this->position.x = (App::Window::width - this->width) / 2.0;
    this->position.y = (App::Window::height - this->height) / 2.0;
}

void Object2D_Translate::bound(Object2D_Translate &o)
{
    this->bound_parent = &o;
    this->bounded = true;
}

void Object2D::set_look_angle(float look_angle)
{
    this->look_angle = look_angle;
    App::Util::angle_abs(this->look_angle);
}

void Object2D::turn_anticlockwise(float delta_t)
{
    this->look_angle += delta_t;
    App::Util::angle_abs(look_angle);
}

void Object2D::turn_clockwise(float delta_t)
{
    this->look_angle -= delta_t;
    App::Util::angle_abs(look_angle);
}

void Object2D::move(float distance, Direction d)
{
    static float new_x, new_y;

    switch (d) {
    case FORWARD:
        new_x = this->position.x + distance * std::cos(this->look_angle);
        new_y = this->position.y + distance * (-1) * std::sin(this->look_angle);
        break;

    case BACKWARD:
        new_x = this->position.x - distance * std::cos(this->look_angle);
        new_y = this->position.y - distance * (-1) * std::sin(this->look_angle);
        break;

    case RIGHT:
        new_x = this->position.x + distance * std::sin(this->look_angle);
        new_y = this->position.y + distance * (-1) * std::cos(this->look_angle);
        break;

    case LEFT:
        new_x = this->position.x - distance * std::sin(this->look_angle);
        new_y = this->position.y - distance * (-1) * std::cos(this->look_angle);
        break;
    }

    Object2D_Translate &parent = this->bound_parent[0];
    if (bounded) {
        if (new_x < parent.position.x || new_y < parent.position.y) {
            return;
        }
        if (new_x - parent.position.x > parent.width - this->width || new_y - parent.position.y > parent.height - this->height) {
            return;
        }
    } else {
        if (new_x < 0 || new_y < 0) {
            return;
        }
        if (new_x > App::Window::width - this->width || new_y > App::Window::height - this->height) {
            return;
        }
    }

    this->position.x = new_x;
    this->position.y = new_y;
}
