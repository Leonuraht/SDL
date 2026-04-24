#include "init.hpp"
#include "texture.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <cstdlib>

int main() {
    init();
    std::string paths = "/home/leonuraht/Downloads/vim1.png";
    Texture texture(paths);
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) == true) {
            if (e.type == SDL_EVENT_QUIT)
                quit = true;
        }
        SDL_SetRenderDrawColor(renderer, 0x34, 0x56, 0xA2, 0xFF);
        SDL_RenderClear(renderer);
    
        texture.render(0.f,0.f);
        SDL_RenderPresent(renderer);
    }
    exit();
    return 0;
}
