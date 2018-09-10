#include "ApplicationState.h"

time_t ApplicationState::getLastKnownRainTime()
{
    return lastKnownRainTime;
}

time_t ApplicationState::getLastSyncTime()
{
    return lastSyncTime;
}
