#ifndef CFPSCOUNTER_H
#define CFPSCOUNTER_H

#include <time.h>
#include <cstdint>

class fpscounter
{
public:
    int n_secondsOld;
    int n_seconds;
    int n_FPSCounter;
    int n_FPS;

    fpscounter();
    void update();
};

#endif // CFPSCOUNTER_H
