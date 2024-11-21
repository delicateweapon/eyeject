#include "Garden.hpp"
#include "App.hpp"

#include <SDL3/SDL_rect.h>
#include <cstddef>
#include <cstdlib>

bool Garden::Area::occupied[width][height];

void Garden::area_init()
{
    for (size_t i = 0; i < Area::width; ++i) {
        for (size_t j = 0; j < Area::height; ++j) {
            Garden::Area::occupied[i][j] = (rand() % 2 == 0) & (rand() % 2 == 0);
        }
    }
}

void Garden::area_render()
{
    SDL_FRect r;
    r.w = Area::tile_size;
    r.h = Area::tile_size;

    for (size_t i = 0; i < Area::width; ++i) {
        for (size_t j = 0; j < Area::height; ++j) {
            r.x = i * Area::tile_size;
            r.y = j * Area::tile_size;

            App::set_color(App::Window::default_color);

            if (Garden::Area::occupied[i][j]) {
                App::set_color(0xffb8e0);
            }

            SDL_RenderFillRect(App::renderer, &r);
        }
    }
}
