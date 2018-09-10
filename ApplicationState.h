#ifndef APPLICATION_STATE_H
#define APPLICATION_STATE_H
#include <Time.h>


class ApplicationState
{
  protected:
    time_t lastSyncTime = 0;
    time_t lastKnownRainTime = 0;

  public:
    time_t getLastKnownRainTime();
    time_t getLastSyncTime();
};

#endif