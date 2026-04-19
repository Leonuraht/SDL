#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <iostream>

int width = 800, height = 600;

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow("Ray Tracer", width, height, SDL_WINDOW_RESIZABLE);
  if (window == NULL)
    std::cout << "\nWINDOW CREATION FAILED\n" << std::endl;
  SDL_Surface *surf = SDL_LoadSurface("~/Downloads/immg.png");
  return 0;
}