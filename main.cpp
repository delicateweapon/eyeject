#include "App.hpp"

int main(void)
{
    if (App::init() < 0) {
        return -1;
    }

    App::set_window_color(0x6aa1cc);

    App::set_color(0xf8f2f2);

    App::draw_line(100, 100, 100, 200);
    App::draw_line(100, 100, 200, 100);
    App::draw_line(200, 100, 100, 150);
    App::draw_line(100, 150, 200, 200);
    App::draw_line(200, 200, 100, 200);

    Camera cam0;
    cam0.fov = 2 * PI / 3;
    cam0.far_length = 100;
    cam0.look_angle = - PI / 2;
    cam0.position = Point2D(App::Window::width / 2.0, App::Window::height / 2.0);

    App::camera_add(cam0);
    Camera::select(cam0);

    App::update();

    App::run();

    App::deinit();
    return 0;
}
