#pragma once

#include "Point2D.hpp"
#include "Camera.hpp"

#include <string>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>

namespace App {
  
namespace Window {

extern SDL_Window *window;
extern std::string title;
extern uint16_t width;
extern uint16_t height;

}

extern SDL_Renderer *renderer;

extern bool running;
extern SDL_Event event;

int init();
void deinit();

void run();
void update();

namespace Input {

void keydown(SDL_KeyboardEvent& key);

}

void set_color(uint32_t hex);
void set_window_color(uint32_t hex);

/* you shall inline these, wont you sweet compiler? */
void draw_line(float x0, float y0, float x1, float y1);
void draw_line(float x0, float y0, float x1, float y1, uint32_t hex);
void draw_line(Point2D& p1, Point2D& p2);
void draw_line(Point2D& p1, Point2D& p2, uint32_t hex);

void render_camera(Camera& cam);

}

constexpr float PI = 3.141592654;
