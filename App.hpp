#pragma once

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

namespace Input {

void keydown(SDL_KeyboardEvent& key);

}

}
