#include "App.hpp"
#include "Camera.hpp"
#include "Garden.hpp"

#include <SDL3/SDL_init.h>

namespace App {

namespace Window {
    SDL_Window *window;
    std::string title;
    uint16_t width = 800;
    uint16_t height = 500;
    uint32_t default_color;
}

SDL_Renderer *renderer;

SDL_Event event;
bool running = false;

}

int App::init()
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::fprintf(stderr, "failed to initialize SDL\n");
        return -1;
    }

    Window::window = SDL_CreateWindow(Window::title.c_str(), Window::width, Window::height, SDL_WINDOW_BORDERLESS);
    if (Window::window == nullptr) {
        std::fprintf(stderr, "failed to create SDL window\n");
        SDL_Quit();
        return -1;
    }

    renderer = SDL_CreateRenderer(Window::window, nullptr);
    if (renderer == nullptr) {
        std::fprintf(stderr, "failed to create SDL renderer\n");
        SDL_DestroyWindow(Window::window);
        SDL_Quit();
        return -1;
    }

    return 0;
}

void App::deinit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(Window::window);
    SDL_Quit();
}

void App::run()
{
    running = true;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                Input::keydown(event.key);
                break;
            default:
                break;
            }
        }
        update();
    }
}

void App::update() 
{
    set_window_color(Window::default_color);
    Garden::area_render();
    for (Camera *cam: Camera::cameras) {
        cam->render();
    }
    SDL_RenderPresent(renderer);    
}
