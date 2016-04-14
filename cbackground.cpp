#include "cbackground.h"
#include "vars.h"

background::background(float input_x, float input_y, float f_size, texture *input_tex):sprite(input_x, input_y, f_size, input_tex)
{

}

void background::update(const float f_speed, const float f_deltaTime)
{
    draw();
    f_x -= f_speed*f_deltaTime;
    if(f_x < -1.1*1.7*tex->h)
    {
        f_x += 2*1.1*1.7*tex->h;
    }
}

