#ifndef CBACKGROUND_H
#define CBACKGROUND_H

#include <iostream>

#include "csprite.h"

class background : public sprite
{
public:
    background(float input_x, float input_y, float f_size, texture *input_tex);

    void update(const float f_speed, const float f_deltaTime);
};

#endif // CBACKGROUND_H
