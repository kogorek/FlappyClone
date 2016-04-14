#ifndef CSPRITE_H
#define CSPRITE_H

#include <GL/gl.h>

#include "vars.h"

class sprite
{
public:
    float f_x, f_y;
    float f_color[3];
    float f_size;
    texture *tex;

    sprite(float x, float y, float input_f_size, texture* inputTexture);
    sprite(float x, float y, float R, float G, float B, float input_f_size, texture* inputTexture);

    void drawRect(float f_x1, float f_y1, float f_x2, float f_y2);
    void draw ();
};

#endif // CSPRITE_H
