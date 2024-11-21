#include "Camera.hpp"
#include "Console.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <ncurses.h>
#endif

void *console_func(void *args)
{
    bool quit = false;
    App::Camera *Cam0;
    char output[256];

#ifdef _WIN32

    while (!quit) {
        Cam0 = App::Camera::selected;

        sprintf(output,
            "Camera: Cam0\n"
            "Position: (.x = %f, .y = %f)\n"
            "Look Angle: %f radians\n"
            "FOV: %f radians\n",
            Cam0->position.x, Cam0->position.y, Cam0->look_angle, Cam0->fov);

        if (GetAsyncKeyState('Q')) {
            quit = true;
        }

        Sleep(100);
    }

#else

    initscr();
    timeout(100);

    int ch;

    while (!quit) {
        clear();
        Cam0 = App::Camera::selected;

        sprintf(output,
            "Camera: Cam0\n"
            "Position: (.x = %f, .y = %f)\n"
            "Look Angle: %f radians\n"
            "FOV: %f radians\n",
            Cam0->position.x, Cam0->position.y, Cam0->look_angle, Cam0->fov);

        printw("%s", output);

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
