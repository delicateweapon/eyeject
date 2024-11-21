#include "Garden.hpp"
#include "App.hpp"

#include <SDL3/SDL_rect.h>
#include <cstddef>
#include <cstdlib>
#include <cmath>

std::vector<Garden *> Garden::gardens;

void Garden::add(Garden &g)
{
    gardens.push_back(&g);
}

Garden::Garden(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t tile_size)
{
    this->position.x = x;
    this->position.y = y;
    this->width = width;
    this->height = height;
    this->tile_size = tile_size;

    this->row_count = std::ceil((float)height / tile_size);
    this->col_count = std::ceil((float)width / tile_size);
    
    this->tile_count = this->row_count * this->col_count;
    this->occupied.assign(this->tile_count, false);
}

void Garden::surround_with_walls()
{
    size_t i;

    i = 0;
    while (i < this->col_count) {
        this->occupied[i] = true;
        this->occupied[this->tile_count - this->col_count + i] = true;
        ++i;
    }

    i = 1;
    while (i < this->row_count) {
        this->occupied[this->col_count * i] = true;
        this->occupied[this->col_count * i - 1] = true;
        ++i;
    }

}

void Garden::render()
{
    SDL_FRect r;
    r.w = this->tile_size;
    r.h = this->tile_size;

    for (size_t y = 0; y < this->row_count; ++y) {
        for (size_t x = 0; x < this->col_count; ++x) {
            r.y = y * this->tile_size + this->position.y;
            r.x = x * this->tile_size + this->position.x;

            App::set_color(App::Window::default_color);

            if (Garden::occupied[y * this->col_count + x]) {
                App::set_color(0xffb8e0);
            }

            SDL_RenderFillRect(App::renderer, &r);
        }
    }
}
