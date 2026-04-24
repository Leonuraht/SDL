#include "init.hpp"
#include <SDL3/SDL_events.h>
#include <cstdlib>

int main() {
  init();
  loadmedia();
  SDL_Event e;
  bool quit = false;
  while(!quit){
      while(SDL_PollEvent(&e) == true){
          if(e.type == SDL_EVENT_QUIT) quit = true;
      }
      SDL_FillSurfaceRect(screen,nullptr,SDL_MapSurfaceRGB(screen,0x35,0x78,0xa2));
      SDL_BlitSurface(surf,nullptr,screen,nullptr);
      SDL_UpdateWindowSurface(window);
  }
  exit();
  return 0;
}
