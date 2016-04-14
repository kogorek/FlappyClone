#ifndef CPIPE_H
#define CPIPE_H

#include <cstdlib> //rand

#include "csprite.h"

class pipe : public sprite
{
public:
    pipe(float input_x, float input_y, float f_size, texture *input_tex);

    void drawRect(float f_x1, float f_y1, float f_x2, float f_y2, float f_angle);
    void update(const float f_speed, float f_deltaTime);
    void draw ();

};

#endif // CPIPE_H
