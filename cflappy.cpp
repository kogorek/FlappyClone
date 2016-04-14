#include "cflappy.h"
#include <iostream>

flappy::flappy(float input_x, float input_y, float f_size, texture *input_tex):sprite(input_x, input_y, f_size, input_tex)
{
    f_vy = 0;
    f_angle = 0.0f;
    n_count = 0;
}

void flappy::update(float f_deltaTime)
{
    draw();
    keyboard();
    f_y += f_vy;
    f_vy -= 10.0f*f_deltaTime;
    f_angle = f_vy*5;
}

void flappy::keyboard()
{
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if ( keyboardState[SDL_SCANCODE_SPACE] )
    {
        f_vy = 8.0f;
    }
}

void flappy::draw ()
{
    glColor3f(f_color[0], f_color[1], f_color[2]);
    glBindTexture(GL_TEXTURE_2D, tex->tex);
    drawRect(-tex->w*f_size, -tex->h*f_size, tex->w*f_size, tex->h*f_size);
    glColor3f(1,1,1);
}

void flappy::drawRect(float f_x1, float f_y1, float f_x2, float f_y2)
{
    glPushMatrix();
    glTranslatef(f_x, f_y, 0.0f);
    glRotatef(f_angle, 0.0f, 0.0f, 1.0f);
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
    glPopMatrix();
}
