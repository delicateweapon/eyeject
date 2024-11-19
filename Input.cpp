#include "App.hpp"

using namespace App;

void Input::keydown(SDL_KeyboardEvent &key)
{
    switch (key.scancode) {
    case SDL_SCANCODE_ESCAPE:
        running = false;
    default:
        break;
    }
}
