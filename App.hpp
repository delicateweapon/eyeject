#pragma once
#include <string>
#include <SDL3/SDL_render.h>

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

}
