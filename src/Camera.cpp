#include "Camera.hpp"
#include "App.hpp"

#include <cmath>

using namespace App;

std::vector<Camera *> Camera::cameras;
Camera *Camera::selected;

void Camera::update_values()
{
    this->head.x = this->position.x + this->far_length * std::cos(this->look_angle);
    this->head.y = this->position.y + this->far_length * (-1) * std::sin(this->look_angle);

    this->angle1 = this->look_angle - (this->fov / 2);
    this->angle2 = this->look_angle + (this->fov / 2);

    this->side_far_length = this->far_length / std::cos(this->fov / 2);

    this->far1.x = this->position.x + this->side_far_length * std::cos(angle1);
    this->far1.y = this->position.y + this->side_far_length * (-1) * std::sin(angle1);

    this->far2.x = this->position.x + this->side_far_length * std::cos(angle2);
    this->far2.y = this->position.y + this->side_far_length * (-1) * std::sin(angle2);

    this->side_near_length = this->near_length / std::cos(this->fov / 2);

    this->near1.x = this->position.x + this->side_near_length * std::cos(angle1);
    this->near1.y = this->position.y + this->side_near_length * (-1) * std::sin(angle1);

    this->near2.x = this->position.x + this->side_near_length * std::cos(angle2);
    this->near2.y = this->position.y + this->side_near_length * (-1) * std::sin(angle2);
}

void Camera::set_fov(float fov)
{
    this->fov = fov;
}

void Camera::set_far_length(float far_length)
{
    this->far_length = far_length;
}

void Camera::set_near_length(float near_length)
{
    this->near_length = near_length;
}

void Camera::set_segments(size_t segments)
{
    this->segments.reserve(segments);
}

size_t Camera::get_segments()
{
    return this->segments.size();
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

    draw_line(this->position, this->far1);
    draw_line(this->position, this->far2);

    draw_line(this->near1, this->near2);
}

void Camera::raycast(Garden& g) 
{
    if (!this->bounded) {
        return;
    }
    if (this->bound_parent != &g) {
        return;
    }

    float angle = this->angle1;
    float step_size = std::abs(angle2 - angle1) / this->segments.size();

    while (angle < this->angle2) {
        float m = std::tan(angle);
        auto x = [](float t) { return t; };
        auto y = [this, m](float t) { return m * (t - this->position.x) + this->position.y; };

        // float t = 

        angle += step_size;
    }
}
