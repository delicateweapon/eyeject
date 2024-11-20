#include "App.hpp"
#include "Camera.hpp"
#include "constants.hpp"

int main(void)
{

    using namespace App;

    if (init() < 0) {
        return -1;
    }

    set_window_color(0x6aa1cc);

    set_color(0xf8f2f2);

    draw_line(100, 100, 100, 200);
    draw_line(100, 100, 200, 100);
    draw_line(200, 100, 100, 150);
    draw_line(100, 150, 200, 200);
    draw_line(200, 200, 100, 200);

    Camera cam0;
    cam0.set_fov(2 * Constants::PI / 3);
    cam0.set_far_length(100);
    cam0.set_look_angle(Constants::PI / 2);
    cam0.position = Point2D(Window::width / 2.0, Window::height / 2.0);

    Camera::select(cam0);
    Camera::add(cam0);

    update();

    run();

    deinit();
    return 0;
}
