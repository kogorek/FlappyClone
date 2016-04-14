#include "cpipe.h"

pipe::pipe(float input_x, float input_y, float f_size, texture *input_tex):sprite(input_x, input_y, f_size, input_tex)
{
}

void pipe::update(const float f_speed, float f_deltaTime)
{
    if(f_x < -240-tex->h/2)
    {
        f_x = 240+tex->h/2;
        f_y = -500 + rand()%300;
    }
    f_x -= f_speed*f_deltaTime;
    draw();
}

void pipe::draw()
{
    glColor3f(f_color[0], f_color[1], f_color[2]);
    glBindTexture(GL_TEXTURE_2D, tex->tex);
    //drawRect(-tex->w*f_size+f_x, -tex->h*f_size+f_y, tex->w*f_size+f_x, tex->h*f_size+f_y);
    drawRect(-tex->w*f_size, -tex->h*f_size, tex->w*f_size, tex->h*f_size, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 700.0f, 0.0f);
    drawRect(-tex->w*f_size, -tex->h*f_size, tex->w*f_size, tex->h*f_size, 180.0f);
    glPopMatrix();
    glColor3f(1,1,1);
}

void pipe::drawRect(float f_x1, float f_y1, float f_x2, float f_y2, float f_angle)
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

//void pipe::drawRect(float f_x1, float f_y1, float f_x2, float f_y2)
//{
//    glBegin(GL_POLYGON);
//    glTexCoord2f(0, 1);
//    glVertex2f(f_x1, f_y1);
//    glTexCoord2f(1, 1);
//    glVertex2f(f_x2, f_y1);
//    glTexCoord2f(1, 0);
//    glVertex2f(f_x2, f_y2);
//    glTexCoord2f(0, 0);
//    glVertex2f(f_x1, f_y2);
//    glEnd();
//}
