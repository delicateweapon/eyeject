#include "App.hpp"
#include "Camera.hpp"
#include "Garden.hpp"
#include "constants.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <ncurses.h>
#endif

#include <thread>
#include <format>

void *console_func(void *args) {
    bool quit = false;

#ifdef _WIN32

    while (!quit) {
        App::Camera *cam0 = App::Camera::selected;

        std::string output = std::format("Camera: Cam0\n"
                                         "Position: (.x = %f, .y = %f)\n"
                                         "Look Angle: %f radians\n"
                                         "FOV: %f radians\n",
                                         cam0->position.x, cam0->position.y, cam0->look_angle, cam0->fov);
        if (GetAsyncKeyState('Q')) {
            quit = true;
        }

        Sleep(100);
    }

#else

    initscr();
    timeout(100);

    int ch;

    App::Camera *cam0;

    while (!quit) {
        clear();

        cam0 = App::Camera::selected;

        std::string output = std::format("Camera: Cam0\n"
                                         "Position: (.x = %f, .y = %f)\n"
                                         "Look Angle: %f radians\n"
                                         "FOV: %f radians\n",
                                         cam0->position.x, cam0->position.y, cam0->look_angle, cam0->fov);

        printw("%s", output.c_str());

        ch = getch();
        switch (ch) {
            case 'Q' - 'A' + 1:
                quit = true;
                break;
            default:
                break;
        }
    }

    endwin();

#endif
    return nullptr;
}

int main() {
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
    cam0.set_position(Window::width / 2.0, Window::height / 2.0);

    Camera::add(cam0);
    Camera::select(cam0);


    Garden::area_init();

    update();
    run();
    deinit();

    console_thread.join();

    return 0;
}
