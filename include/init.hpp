#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

extern SDL_Window *window;
extern int width, height;
extern SDL_Renderer* renderer;

void init();
void exit();
