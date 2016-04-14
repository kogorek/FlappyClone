#include "ccounter.h"

counter::counter(float i_f_x, float i_f_y, float i_f_size) : f_x(i_f_x), f_y(i_f_y), f_size(i_f_size)
{
    loadTexture(&tex_tont[0], "./res/sprites/font/0.png", GL_NEAREST);
    loadTexture(&tex_tont[1], "./res/sprites/font/1.png", GL_NEAREST);
    loadTexture(&tex_tont[2], "./res/sprites/font/2.png", GL_NEAREST);
    loadTexture(&tex_tont[3], "./res/sprites/font/3.png", GL_NEAREST);
    loadTexture(&tex_tont[4], "./res/sprites/font/4.png", GL_NEAREST);
    loadTexture(&tex_tont[5], "./res/sprites/font/5.png", GL_NEAREST);
    loadTexture(&tex_tont[6], "./res/sprites/font/6.png", GL_NEAREST);
    loadTexture(&tex_tont[7], "./res/sprites/font/7.png", GL_NEAREST);
    loadTexture(&tex_tont[8], "./res/sprites/font/8.png", GL_NEAREST);
    loadTexture(&tex_tont[9], "./res/sprites/font/9.png", GL_NEAREST);
    n_count = 0;
}

void counter::draw()
{
    glBindTexture(GL_TEXTURE_2D, tex_tont[n_count].tex);
    drawRect(-tex_tont[n_count].w*f_size+f_x, -tex_tont[n_count].h*f_size+f_y,
             tex_tont[n_count].w*f_size+f_x, tex_tont[n_count].h*f_size+f_y);
}

void counter::drawRect(float f_x1, float f_y1, float f_x2, float f_y2)
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
