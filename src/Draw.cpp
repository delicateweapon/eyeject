#include "App.hpp"

/* dear compiler, please optimize this shit */

void App::draw_line(float x0, float y0, float x1, float y1)
{
    SDL_RenderLine(renderer, x0, y0, x1, y1);
}

void App::draw_line(float x0, float y0, float x1, float y1, uint32_t hex)
{  
    App::set_color(hex);
    draw_line(x0, y0, x1, y1);
}

void App::draw_line(Point2D& p1, Point2D& p2)
{
    SDL_RenderLine(renderer, p1.x, p1.y, p2.x, p2.y);  
}

void App::draw_line(Point2D& p1, Point2D& p2, uint32_t hex)
{
    App::set_color(hex);
    draw_line(p1, p2);
}
