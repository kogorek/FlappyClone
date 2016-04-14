#ifndef CFLAPPY_H
#define CFLAPPY_H

#include <SDL2/SDL.h>

#include "csprite.h"

class flappy : public sprite
{
private:
    float f_vy;
    float f_angle;

public:
    int n_count;
    flappy(float input_x, float input_y, float f_size, texture *input_tex);
    void update(float f_deltaTime);
    void drawRect(float f_x1, float f_y1, float f_x2, float f_y2);
    void keyboard();
    void draw();
};

#endif // CFLAPPY_H
