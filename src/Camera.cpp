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

    App::Util::angle_abs(angle1);
    App::Util::angle_abs(angle2);

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
    App::Util::angle_abs(this->fov);
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
    this->segments.assign(segments, 0);
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
    draw_line(this->far1, this->far2);
}

void Camera::raycast(Garden &g)
{
    if (!this->bounded) {
        return;
    }
    if (this->bound_parent != &g) {
        return;
    }

    this->update_values();

    float step_size = (this->angle2 - this->angle1) / this->segments.size();
    float angle = this->angle1;

    float near, far, r;
    float sin_a, cos_a;
    float x, y;

    App::set_color(0xffffff);
    while (angle < angle2) {
        sin_a = sin(angle);
        cos_a = cos(angle);

        near = std::abs(this->near_length / sin_a);
        far = std::abs(this->far_length / sin_a);

        r = near;
        while (r < far) {
            x = this->position.x + r * cos_a;
            y = this->position.y + (-1) * r * sin_a;

            App::draw_line(this->position.x, this->position.y, x, y);
            SDL_RenderPresent(App::renderer);

            bool occupied = g.check_occupancy(x, y);
            if (occupied) {
                break;
            }

            r += g.tile_size / 2.0;
        }

        angle += step_size;
    }
}
