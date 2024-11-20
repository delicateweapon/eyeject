#include "Camera.hpp"
#include "App.hpp"

#include <cmath>

std::vector<Camera *> Camera::cameras;
Camera *Camera::selected_camera;

Camera::Camera(float fov, float look_angle, float far_length, Point2D position)
{
    this->fov = fov;
    this->look_angle = look_angle;
    this->far_length = far_length;
    this->position = position;
    this->selected = false;
}

void Camera::select(Camera &cam)
{
    for (Camera *c : cameras) {
        c->selected = false;
    }

    cam.selected = true;
    selected_camera = &cam;
}

void App::camera_add(Camera& cam)
{
    Camera::cameras.push_back(&cam);
}

void App::camera_render(Camera &cam)
{
    if (cam.selected) {
        set_color(0xff0000);
    } else {
        set_color(0xffffff);
    }

    Point2D head(cam.position.x, cam.position.y);
    head.x += cam.far_length * std::cos(cam.look_angle);
    head.y += cam.far_length * std::sin(cam.look_angle);

    draw_line(cam.position, head);

    set_color(0xf8f2f2);

    float angle1 = cam.look_angle - (cam.fov / 2);
    float angle2 = cam.look_angle + (cam.fov / 2);

    float side_length = cam.far_length / std::cos(cam.fov / 2);

    Point2D side1(cam.position.x, cam.position.y);
    side1.x += side_length * std::cos(angle1);
    side1.y += side_length * std::sin(angle1);

    Point2D side2(cam.position.x, cam.position.y);
    side2.x += side_length * std::cos(angle2);
    side2.y += side_length * std::sin(angle2);

    draw_line(cam.position, side1);
    draw_line(cam.position, side2);
}
