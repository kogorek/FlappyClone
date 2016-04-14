#include "csprite.h"

void sprite::drawRect(float f_x1, float f_y1, float f_x2, float f_y2)
{
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 1);
    glVertex2f(f_x1, f_y1);
    glTexCoord2f(1, 1);
    glVertex2f(f_x2, f_y1);
    glTexCoord2f(1, 0);
    glVertex2f(f_x2, f_y2);
    glTexCoord2f(0, 0);
    glVertex2f(f_x1, f_y2);
    glEnd();
}

sprite::sprite(float x, float y, float input_f_size, texture *inputTexture)
{
    tex = inputTexture;
    f_x = x;
    f_y = y;
    f_color[0] = 1;
    f_color[1] = 1;
    f_color[2] = 1;
    f_size = input_f_size;
}
sprite::sprite(float x, float y, float R, float G, float B, float input_f_size, texture *inputTexture)
{
    tex = inputTexture;
    f_x = x;
    f_y = y;
    f_color[0] = R;
    f_color[1] = G;
    f_color[2] = B;
    f_size = input_f_size;
}

void sprite::draw ()
{
    glColor3f(f_color[0], f_color[1], f_color[2]);
    glBindTexture(GL_TEXTURE_2D, tex->tex);
    drawRect(-tex->w*f_size+f_x, -tex->h*f_size+f_y, tex->w*f_size+f_x, tex->h*f_size+f_y);
    glColor3f(1,1,1);
}
