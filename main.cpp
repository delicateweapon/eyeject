#include "App.hpp"

#include <SDL3/SDL_render.h>

int main(void)
{
    if (App::init() < 0) {
        return -1;
    }

    SDL_SetRenderDrawColor(App::renderer, 220, 110, 200, 255);
    SDL_RenderClear(App::renderer);
    SDL_RenderPresent(App::renderer);
    
    App::run();

    App::deinit();
    return 0;
}
