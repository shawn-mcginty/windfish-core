#ifndef WINDFISH_CORE_ENGINE_GRAPHICS_H
#define WINDFISH_CORE_ENGINE_GRAPHICS_H
#include <SDL2/SDL.h>

typedef struct {
  char *windowTitle;
  int width;
  int height;
  SDL_Window *window;
} Graphics;

int GRAPHICS_init(Graphics *graphics);
void GRAPHICS_free(Graphics *graphics);

#endif