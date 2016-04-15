#include "cflappy.h"
#include <iostream>

flappy::flappy(float input_x, float input_y, float f_size, texture *input_tex, pipe *inputPipe[]):sprite(input_x, input_y, f_size, input_tex)
{
    b_alive = true;
    f_vy = 0;
    f_angle = 0.0f;
    n_count = 0;
    pipeList[0] = inputPipe[0];
    pipeList[1] = inputPipe[1];
    pipeNum = 0;
    n_deathCount = 0;
}

void flappy::update(float f_deltaTime)
{
    draw();
    keyboard();

    f_y += f_vy*f_deltaTime;
    f_vy -= 400.0f*f_deltaTime;
    f_angle = f_vy*0.2;
    if(pipeList[pipeNum]->f_x <= f_x && b_alive)
    {
        n_count += 1;
        pipeNum += 1;
    }
    if(pipeNum > 1)
        pipeNum = 0;

    for(int i = 0; i < 2; i++)
    {
        if (pipeList[i]->f_x - pipeList[pipeNum]->tex->w*1.7 < f_x
                && pipeList[i]->f_x + pipeList[pipeNum]->tex->w*1.7 > f_x
                && (pipeList[i]->f_y + pipeList[i]->tex->h*1.7 > f_y
                    || pipeList[i]->f_y + pipeList[i]->tex->h*1.7 + 155 < f_y))
        {
            b_alive = false;
        }
    }
}

void flappy::keyboard()
{
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
//    SDL_Event event; // события SDL

//    while ( SDL_PollEvent(&event) )
//    { // начинаем обработку событий
//        switch(event.type)
//        { // смотрим:
//        case SDL_MOUSEBUTTONDOWN: // если произошло событие закрытия окна, то завершаем работу программы

//            break;
//        }
//    }

//        case SDL_KEYDOWN: // если нажата клавиша
//            switch(event.key.keysym.sym)
//            { // смотрим какая
//            case SDLK_ESCAPE: // клавиша ESC
//                running = false; // завершаем работу программы
//            case SDLK_f:
//                b_FPScap = !b_FPScap;
//                break;
//            }
//            break;
//        }
    //const Uint8 *mouseState = SDL_MouseButtonEvent(NULL);
    if ( keyboardState[SDL_SCANCODE_SPACE] && b_alive)
    {
        f_vy = 250.0f;
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
