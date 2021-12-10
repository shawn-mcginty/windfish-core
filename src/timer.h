#ifndef WINDFISH_CORE_TIMER_H
#define WINDFISH_CORE_TIMER_H

typedef struct {
  double current_time;
  double previous_time;
  double previous_fps_update;
  int fps;
  double average_delta;
  double fps_update_frequency;
  int frames;
  double dt;
} Timer;

int TIMER_init(Timer *timer); 

double TIMER_step(Timer *timer);

void TIMER_sleep(double seconds);

#endif