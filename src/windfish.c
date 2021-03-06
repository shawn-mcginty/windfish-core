#include <stdio.h>
#include "engine.h"

unsigned int initState1() {
  printf("state 1 created\n");
  return 0;
}

unsigned int updateState1(float deltatime) {
  printf("state 1 updated delta: %f\n", deltatime);
  return 0;
}

unsigned int destroyState1() {
  printf("state 1 destroyed\n");
  return 0;
}

int main() {
  struct EngineOptions options = {0};
  options.title = "Windfish Engine Test";
  options.width = 480;
  options.height = 272;

  Engine engine;
  ENGINE_init(&engine, &options);

  State state1 = {0};
  state1.init = initState1;
  state1.destroy = destroyState1;
  state1.update = updateState1;
  STATEMANAGER_push(&engine.statemanager, &state1);
  TIMER_step(&engine.timer);

  // game loop
  int quit = 0;
  SDL_Event e;
  while (!engine.quit) {
    TIMER_step(&engine.timer);

    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        engine.quit = 1;
    }

    STATEMANAGER_update(&engine.statemanager, engine.timer.dt);

    printf("fps: %d ", engine.timer.fps);
    TIMER_sleep(0.01);
  }

  ENGINE_free(&engine);

  return 0;
}