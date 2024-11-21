#include "App.hpp"
#include "Camera.hpp"
#include "Garden.hpp"
#include "constants.hpp"

#include <ncurses.h>
#include <pthread.h>

void *ncurses_func(void *args)
{
    initscr();
    timeout(100);

    bool quit;
    int ch;

    App::Camera *cam0;

    while (!quit) {
        clear();

        cam0 = App::Camera::selected;

        printw("Camera: Cam0\n");
        printw("Position: (.x = %f, .y = %f)\n", cam0->position.x, cam0->position.y);
        printw("Look Angle: %f radians\n", cam0->look_angle);
        printw("FOV: %f radians\n", cam0->fov);

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
    return NULL;
}

int main(void)
{

    using namespace App;

    if (init() < 0) {
        return -1;
    }

    pthread_t ncurses_thread;
    pthread_create(&ncurses_thread, NULL, ncurses_func, NULL);

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

    pthread_join(ncurses_thread, NULL);

    return 0;
}
