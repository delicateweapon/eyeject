#include "App.hpp"

#include <SDL3/SDL_render.h>

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

    App::update();

    App::run();

    App::deinit();
    return 0;
}
