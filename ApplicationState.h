#ifndef APPLICATION_STATE_H
#define APPLICATION_STATE_H
#include <Time.h>
#include "SyncData.h"

#define FLAG_IS_RAINY 0x01

class ApplicationState
{
  protected:
    time_t lastSyncTime = 0;
    time_t lastKnownRainTime = 0;

  public:
    time_t getLastKnownRainTime();
    time_t getLastSyncTime();

    void actionSyncDataChanged(SyncData *syncData);
};

#endif