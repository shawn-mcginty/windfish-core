#include "timer.h"
#include <sys/time.h>
#include <SDL_timer.h>

static double get_current_time() {
  // Check for POSIX timers and monotonic clocks. If not supported, use the gettimeofday fallback.
#if _POSIX_TIMERS > 0 && defined(_POSIX_MONOTONIC_CLOCK) \
&& (defined(CLOCK_MONOTONIC_RAW) || defined(CLOCK_MONOTONIC))

#ifdef CLOCK_MONOTONIC_RAW
  clockid_t clock_id = CLOCK_MONOTONIC_RAW;
#else
  clockid_t clock_id = CLOCK_MONOTONIC;
#endif

  timespec t;
  if(clock_gettime(clock_id, &t) == 0)
    return (double) t.tv_sec + (double) t.nsec / 1.0e9;
#endif

  struct timeval t_val;
  gettimeofday(&t_val, NULL);

  return (double) t_val.tv_sec + (double)(t_val.tv_usec * 1000) / 1.0e9;
}


int TIMER_init(Timer *timer) {
  timer->current_time = get_current_time();
  timer->previous_time = 0.0f;
  timer->previous_fps_update = get_current_time();
  timer->fps = 0;
  timer->average_delta = 0.0f;
  timer->fps_update_frequency = 1.0f;
  timer->frames = 0;
  timer->dt = 0.0f;

  return 0;
}

double TIMER_step(Timer *timer) {
  timer->frames++;
  timer->previous_time = timer->current_time;
  timer->current_time = get_current_time();
  timer->dt = timer->current_time - timer->previous_time;
  double time_since_last = timer->current_time - timer->previous_fps_update;

  if (time_since_last > timer->fps_update_frequency) {
    timer->fps = (int)((timer->frames / time_since_last) + 0.5);
    timer->average_delta = time_since_last / timer->frames;
    timer->frames = 0;
    timer->previous_fps_update = timer->current_time;
  }
}

void TIMER_sleep(double seconds) {
  SDL_Delay((unsigned int)(seconds * 1000));
}