#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>

extern SDL_Window *window;
extern SDL_Surface *surf;
extern SDL_Surface *screen;
extern int width, height;

void init();
void loadmedia();
void exit();
