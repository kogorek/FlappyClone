#include "cfpscounter.h"

fpscounter::fpscounter()
{
    n_secondsOld = 0;
    n_seconds = time(NULL);
    n_FPS = 0;
    n_FPSCounter = 0;
}

void fpscounter::update()
{
    n_seconds = time(NULL);
    n_FPSCounter++;
    if (n_secondsOld < n_seconds)
    {
        n_secondsOld = n_seconds;
        n_FPS = n_FPSCounter;
        n_FPSCounter = 0;
    }
}
