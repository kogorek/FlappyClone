#ifndef CCOUNTER_H
#define CCOUNTER_H

#include <GL/gl.h>

#include "xenfautils.h"
#include "vars.h"

class counter
{
private:
    texture tex_tont[10];
    float f_x, f_y;
    float f_size;
public:
    int n_count;

    counter(float i_f_x, float i_f_y, float i_f_size);

    void drawRect(float f_x1, float f_y1, float f_x2, float f_y2);
    void drawScore(int n_score, float xpos, float ypos, float size, float screenMultiplicator);
    void draw();
};

#endif // CCOUNTER_H
