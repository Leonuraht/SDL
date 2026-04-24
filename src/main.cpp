#include "init.hpp"
#include "rotate.hpp"
#include "texture.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3_image/SDL_image.h>
#include <cmath>
#include <cstdlib>

Point p1(100.0f, 100.0f);
Point p2(50.f, 200.f);
Point p3(150.f, 200.f);

int main() {
    init();
    std::string paths = "/home/leonuraht/Downloads/vim1.png";
    Texture texture(paths);
    SDL_Event e;
    double sint = 0, cost = 0;
    float cx = (p1.x + p2.x + p3.x) / 3, cy = (p1.y + p2.y + p3.y) / 3;
    bool quit = false;
    SDL_Vertex vertex[3];
    double ltime = SDL_GetTicks(), ntime = 0, dt = 0;
    for(int i = 0;i < 3;i++) vertex[i].color = {1,1,1,1};
    vertex[0].tex_coord = {0.5f,0.0f};
    vertex[1].tex_coord = {1.0f,1.0f};
    vertex[2].tex_coord = {0.0f,1.0f};
    while (!quit) {
        ntime = SDL_GetTicks();
        dt = (ntime - ltime) / 1000;
        ltime = ntime;
        dt *= 0.7;
        sint = sin(dt);
        cost = cos(dt);
        while (SDL_PollEvent(&e) == true) {
            if (e.type == SDL_EVENT_QUIT || e.key.key == SDLK_ESCAPE)
                quit = true;
        }
        SDL_SetRenderDrawColor(renderer, 0x34, 0x56, 0xA2, 0xFF);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        vertex[0].position = {p1.x, p1.y};
        vertex[1].position = {p2.x, p2.y};
        vertex[2].position = {p3.x, p3.y};
        SDL_RenderGeometry(renderer, texture.textdata, vertex, 3, nullptr, 0);
        SDL_RenderPresent(renderer);
        p1.rotate(cx, cy, sint, cost);
        p2.rotate(cx, cy, sint, cost);
        p3.rotate(cx, cy, sint, cost);
    }
    exit();
    return 0;
}
