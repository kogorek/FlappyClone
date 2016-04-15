#ifndef CFLAPPY_H
#define CFLAPPY_H

#include <SDL2/SDL.h>

#include "csprite.h"
#include "cpipe.h"

class flappy : public sprite
{
private:
    float f_angle;
    pipe* pipeList[2];

public:
    int n_count;
    bool b_alive;
    float f_vy;
    int pipeNum;
    int n_deathCount;

    flappy(float input_x, float input_y, float f_size, texture *input_tex, pipe *inputPipe[]);
    void update(float f_deltaTime);
    void drawRect(float f_x1, float f_y1, float f_x2, float f_y2);
    void keyboard();
    void draw();
};

#endif // CFLAPPY_H
