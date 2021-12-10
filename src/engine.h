#ifndef WINDFISH_CORE_ENGINE_MAIN_H
#define WINDFISH_CORE_ENGINE_MAIN_H

#include "graphics.h"
#include "statemanager.h"

struct EngineOptions {
  char *title;
  int width;
  int height;
};

typedef struct {
  char quit;
  Graphics graphics;
  StateManager statemanager;
} Engine;

int ENGINE_init(Engine *engine, struct EngineOptions *options);
int ENGINE_free(Engine *engine);

#endif