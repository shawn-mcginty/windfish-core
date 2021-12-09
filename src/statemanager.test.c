#include <stdio.h>
#include "statemanager.h"

unsigned int initState1() {
  printf("state 1 created\n");
  return 0;
}

unsigned int destroyState1() {
  printf("state 1 destroyed\n");
  return 0;
}

unsigned int initState2() {
  printf("state 2 created\n");
  return 0;
}

unsigned int updateState2(float deltatime) {
  printf("state 2 updated delta:%f\n", deltatime);
  return 0;
}

unsigned int destroyState2() {
  printf("state 2 destroyed\n");
  return 0;
}

unsigned int initState3() {
  printf("state 3 created\n");
  return 0;
}

unsigned int updateState3(float deltatime) {
  printf("state 3 updated delta:%f\n", deltatime);
  return 0;
}

unsigned int destroyState3() {
  printf("state 3 destroyed\n");
  return 0;
}

int main() {
  StateManager statemanager;
  STATEMANAGER_init(&statemanager);

  State state1 = {0};
  state1.init = initState1;
  state1.destroy = destroyState1;

  State state2 = {0};
  state2.init = initState2;
  state2.update = updateState2;
  state2.destroy = destroyState2;

  State state3 = {0};
  state3.init = initState3;
  state3.update = updateState3;
  state3.destroy = destroyState3;

  STATEMANAGER_push(&statemanager, &state1);
  STATEMANAGER_update(&statemanager, 10.0f);

  STATEMANAGER_push(&statemanager, &state2);
  STATEMANAGER_update(&statemanager, 10.0f);

  STATEMANAGER_push(&statemanager, &state3);
  STATEMANAGER_update(&statemanager, 10.0f);

  STATEMANAGER_pop(&statemanager);
  STATEMANAGER_update(&statemanager, 10.0f);

  STATEMANAGER_free(&statemanager);

  return 0;
}