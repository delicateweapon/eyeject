#include "App.hpp"
#include "Camera.hpp"

using namespace App;

Camera *cam;

void Input::keydown(SDL_KeyboardEvent &key)
{
    cam = Camera::selected;

    switch (key.scancode) {
    case SDL_SCANCODE_ESCAPE:
        running = false;
        break;

    case SDL_SCANCODE_W:
        cam->move(5, FORWARD);
        break;

    case SDL_SCANCODE_S:
        cam->move(5, BACKWARD);
        break;

    case SDL_SCANCODE_D:
        cam->move(5, RIGHT);
        break;

    case SDL_SCANCODE_A:
        cam->move(5, LEFT);
        break;

    case SDL_SCANCODE_Q:
        cam->rotate(0.1);
        break;

    case SDL_SCANCODE_E:
        cam->rotate(-0.1);
        break;

    case SDL_SCANCODE_X:
        cam->fov += 0.1;
        break;

    case SDL_SCANCODE_Z:
        cam->fov -= 0.1;
        break;

    default:
        break;
    }
}
