#include "Color.hpp"
#include "App.hpp"

Color::Color(uint8_t r, uint8_t g, uint8_t b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

Color::Color(uint32_t hex) 
{
    this->r = (hex >> 16) & 0xFF;
    this->g = (hex >> 8) & 0xFF;
    this->b = (hex >> 0) & 0xFF;
}

void App::set_color(uint32_t hex)
{
    Color c(hex);

    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, 255);
}

void App::set_window_color(uint32_t hex)
{
    set_color(hex);

    SDL_RenderClear(renderer);
}

void App::set_default_window_color(uint32_t hex) 
{
    Window::default_color = hex;
}
