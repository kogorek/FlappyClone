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

void counter::drawScore(int n_score, float xpos, float ypos, float size, float screenMultiplicator)
{
    char digs[7];
    int digits = 1;
    if (n_score == 0)
    {
        digits = 1;
    }
    else
    {
        digits = int(log10(n_score)+1);
    }
    sprintf(digs,"%d",n_score);
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(xpos, ypos, 0);

    for (int i = 0; i != 7-digits; i++)
    {
        glTranslatef(size+screenMultiplicator, 0, 0);
        //zero
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.6f*size, 0.7f*size);
        glVertex2f(-0.4f*size, 1.0f*size);
        glVertex2f(0.4f*size, 1.0f*size);
        glVertex2f(0.6f*size, 0.7f*size);
        glVertex2f(0.6f*size, -0.7f*size);
        glVertex2f(0.4f*size, -1.0f*size);
        glVertex2f(-0.4f*size, -1.0f*size);
        glVertex2f(-0.6f*size, -0.7f*size);
        glVertex2f(-0.6f*size, 0.7f*size);
        glEnd();
//                glTranslatef(-size*i-2, 0, 0);
//                glTranslatef(-xpos, -ypos, 0);
    }
    for ( int i = 0; i != digits; i++ )
    {

        glTranslatef(size+screenMultiplicator, 0, 0);
        //zero
        if (digs[i] == '0')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[0].tex);
            drawRect(-tex_tont[0].w*f_size+f_x, -tex_tont[0].h*f_size+f_y,
                     tex_tont[0].w*f_size+f_x, tex_tont[0].h*f_size+f_y);
        }
        //one
        if (digs[i] == '1')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[1].tex);
            drawRect(-tex_tont[1].w*f_size+f_x, -tex_tont[1].h*f_size+f_y,
                     tex_tont[1].w*f_size+f_x, tex_tont[1].h*f_size+f_y);
        }
        //two
        if (digs[i] == '2')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[2].tex);
            drawRect(-tex_tont[2].w*f_size+f_x, -tex_tont[2].h*f_size+f_y,
                     tex_tont[2].w*f_size+f_x, tex_tont[2].h*f_size+f_y);
        }
        if (digs[i] == '3')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[3].tex);
            drawRect(-tex_tont[3].w*f_size+f_x, -tex_tont[3].h*f_size+f_y,
                     tex_tont[3].w*f_size+f_x, tex_tont[3].h*f_size+f_y);
        }
        if (digs[i] == '4')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[4].tex);
            drawRect(-tex_tont[4].w*f_size+f_x, -tex_tont[4].h*f_size+f_y,
                     tex_tont[4].w*f_size+f_x, tex_tont[4].h*f_size+f_y);
        }
        if (digs[i] == '5')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[5].tex);
            drawRect(-tex_tont[5].w*f_size+f_x, -tex_tont[5].h*f_size+f_y,
                     tex_tont[5].w*f_size+f_x, tex_tont[5].h*f_size+f_y);
        }
        if (digs[i] == '6')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[6].tex);
            drawRect(-tex_tont[6].w*f_size+f_x, -tex_tont[6].h*f_size+f_y,
                     tex_tont[6].w*f_size+f_x, tex_tont[6].h*f_size+f_y);
        }
        if (digs[i] == '7')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[7].tex);
            drawRect(-tex_tont[7].w*f_size+f_x, -tex_tont[7].h*f_size+f_y,
                     tex_tont[7].w*f_size+f_x, tex_tont[7].h*f_size+f_y);
        }
        if (digs[i] == '8')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[8].tex);
            drawRect(-tex_tont[8].w*f_size+f_x, -tex_tont[8].h*f_size+f_y,
                     tex_tont[8].w*f_size+f_x, tex_tont[8].h*f_size+f_y);
        }
        if (digs[i] == '9')
        {
            glBindTexture(GL_TEXTURE_2D, tex_tont[9].tex);
            drawRect(-tex_tont[9].w*f_size+f_x, -tex_tont[9].h*f_size+f_y,
                     tex_tont[9].w*f_size+f_x, tex_tont[9].h*f_size+f_y);
        }
    }
    // Goint back to 0.0
    for (int i = 0; i != 7; i++)
    {
        glTranslatef(-size-screenMultiplicator, 0, 0);
    }
    glTranslatef(-xpos, -ypos, 0);
}
