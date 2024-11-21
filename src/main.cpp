#include "App.hpp"
#include "Camera.hpp"
#include "Garden.hpp"
#include "constants.hpp"
#include "Console.hpp"

#include <thread>

int main()
{
    using namespace App;

    if (init() < 0) {
        return -1;
    }

    std::thread console_thread([] { console_func(nullptr); });

    set_default_window_color(0x6aa1cc);

    set_color(0xf8f2f2);

    // draw_line(100, 100, 100, 200);
    // draw_line(100, 100, 200, 100);
    // draw_line(200, 100, 100, 150);
    // draw_line(100, 150, 200, 200);
    // draw_line(200, 200, 100, 200);

    Camera cam0;
    cam0.set_fov(Constants::PI / 2);
    cam0.set_far_length(10);
    cam0.set_look_angle(Constants::PI / 2);
    cam0.place_at_window_center();

    Camera::add(cam0);
    Camera::select(cam0);

    Garden g0(0, 0, Window::width / 3, Window::height / 3, 15);
    g0.surround_with_walls();
    g0.place_at_window_center();

    
    Garden::add(g0);

    update();
    run();
    deinit();

    console_thread.join();

    return 0;
}
