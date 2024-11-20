#include "Camera.hpp"
#include "App.hpp"

#include <cmath>

using namespace App;

std::vector<Camera *> Camera::cameras;
Camera *Camera::selected;

Camera::Camera(float fov, float look_angle, float far_length, Point2D position)
{
    this->fov = fov;
    this->look_angle = look_angle;
    this->far_length = far_length;
    this->position = position;
    this->is_selected = false;
}

void Camera::update_values()
{
    this->head.x = this->position.x + this->far_length * std::cos(this->look_angle);
    this->head.y = this->position.y + this->far_length * (-1) * std::sin(this->look_angle);


    this->angle1 = this->look_angle - (this->fov / 2);
    this->angle2 = this->look_angle + (this->fov / 2);
    this->side_length = this->far_length / std::cos(this->fov / 2);

    this->side1.x = this->position.x + this->side_length * std::cos(angle1);
    this->side1.y = this->position.y + this->side_length * (-1) * std::sin(angle1);

    this->side2.x = this->position.x + this->side_length * std::cos(angle2);
    this->side2.y = this->position.y + this->side_length * (-1) * std::sin(angle2);
}

void Camera::set_fov(float fov)
{
    this->fov = fov;
}

void Camera::set_position(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
}

void Camera::set_position(Point2D &p)
{
    this->position = p;
}

void Camera::set_look_angle(float look_angle)
{
    this->look_angle = look_angle;
}

void Camera::set_far_length(float far_length)
{
    this->far_length = far_length;
}

void Camera::select(Camera &cam)
{
    for (Camera *c : cameras) {
        c->is_selected = false;
    }

    cam.is_selected = true;
    selected = &cam;
}

void Camera::add(Camera &cam)
{
    Camera::cameras.push_back(&cam);
}

void Camera::render()
{
    this->update_values();

    if (this->selected) {
        set_color(0xff0000);
    } else {
        set_color(0xffffff);
    }

    draw_line(this->position, this->head);

    set_color(0xf8f2f2);

    draw_line(this->position, side1);
    draw_line(this->position, side2);
}
