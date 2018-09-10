#include "ApplicationState.h"

time_t ApplicationState::getLastKnownRainTime()
{
    return lastKnownRainTime;
}

time_t ApplicationState::getLastSyncTime()
{
    return lastSyncTime;
}

void ApplicationState::actionSyncDataChanged(SyncData *syncData)
{
    lastSyncTime = syncData->time;
    if (syncData->flags & FLAG_IS_RAINY)
    {
        lastKnownRainTime = syncData->time;
    }
}
