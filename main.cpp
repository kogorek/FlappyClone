#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_mixer.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
#include <cstdlib> //rand
#include <vector>
#include <ctime> //for time(0) and randomness

#include "cbackground.h"
#include "xenfautils.h"
#include "ccounter.h"
#include "cflappy.h"
#include "cpipe.h"

#define UNUSED(x) (void)(x)

void initGLandSDL();
void endSDL(background *backGround[], flappy *bird, texture *tex_textures[], pipe *greenPipe[]);

SDL_Window *win = NULL;

int n_FPScap = 30;
//int n_screenWidth = 640;
//int n_screenHeight = 480;
int n_screenWidth = 480;
int n_screenHeight = 640;
bool b_FPScap = true;

int main(int argc, char *argv[])
{
    srand(time(0));
    bool b_running = true;
    float f_deltaTime = 0;
    SDL_Event event;
    Uint32 currentTime = SDL_GetTicks();
    Uint32 lastTime = 0;
    Uint32 time = 0; // Используется для ограничения FPS

    UNUSED(argc);
    UNUSED(argv);
    UNUSED(f_deltaTime);

    initGLandSDL();

    texture *tex_textures = new texture[7]; // 3
    loadTexture(&tex_textures[0], "./res/sprites/NightBackground.png", GL_NEAREST);
    loadTexture(&tex_textures[1], "./res/sprites/Flappy1.png", GL_NEAREST);
    loadTexture(&tex_textures[2], "./res/sprites/UpGreenPipe.png", GL_NEAREST);
    loadTexture(&tex_textures[3], "./res/sprites/bushes.png", GL_NEAREST);
    loadTexture(&tex_textures[4], "./res/sprites/fog.png", GL_NEAREST);
    loadTexture(&tex_textures[5], "./res/sprites/homes.png", GL_NEAREST);
    loadTexture(&tex_textures[6], "./res/sprites/sky.png", GL_NEAREST);
    //sprite backGround(0.0f, 0.0f, texBackGround);
    background *backGround[8];
    backGround[0] = new background(0.0f, 0.0f, 1.7f, &tex_textures[3]);
    backGround[1] = new background(1.1f*tex_textures[3].h*1.7f, 0.0f, 1.7f, &tex_textures[3]);

    backGround[2] = new background(0.0f, 0.0f, 1.7f, &tex_textures[4]);
    backGround[3] = new background(1.1f*tex_textures[4].h*1.7f, 0.0f, 1.7f, &tex_textures[4]);

    backGround[4] = new background(0.0f, 0.0f, 1.7f, &tex_textures[5]);
    backGround[5] = new background(1.1f*tex_textures[5].h*1.7f, 0.0f, 1.7f, &tex_textures[5]);

    backGround[6] = new background(0.0f, 0.0f, 1.7f, &tex_textures[6]);
    backGround[7] = new background(1.1f*tex_textures[6].h*1.7f, 0.0f, 1.7f, &tex_textures[6]);

    flappy* bird = new flappy (-200.0f, 0.0f, 1.0f, &tex_textures[1]);

    pipe *greenPipe[3];
    greenPipe[0] = new pipe(200.0f, -500 + rand()%300, 1.7f, &tex_textures[2]);
    greenPipe[1] = new pipe(500.0f, -500 + rand()%300, 1.7f, &tex_textures[2]);
    greenPipe[2] = new pipe(700.0f, -500 + rand()%300, 1.7f, &tex_textures[2]);

    counter fontCounter(0.0f, 270.0f, 1.0f);

    while(b_running)
    {
        if (currentTime > lastTime)
            lastTime = currentTime;
        currentTime = SDL_GetTicks();
        f_deltaTime = (double)((currentTime - lastTime)/1000.0f);
        time = SDL_GetTicks();
        while ( SDL_PollEvent(&event) )
        {
            switch(event.type)
            {
            case SDL_QUIT:
                b_running = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    b_running = false;
                    break;
                case SDLK_f:
                    b_FPScap = !b_FPScap;
                    break;
                }
                break;
            }
        }
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT ); //| GL_DEPTH_BUFFER_BIT
        gluOrtho2D(-n_screenWidth/2, n_screenWidth/2, -n_screenHeight/2, n_screenHeight/2);

        backGround[6]->update(100.0f, f_deltaTime); // Sky
        backGround[7]->update(100.0f, f_deltaTime);

        backGround[2]->update(100.0f, f_deltaTime); // fog
        backGround[3]->update(100.0f, f_deltaTime);

        backGround[4]->update(95.0f, f_deltaTime); // homes
        backGround[5]->update(95.0f, f_deltaTime);

        backGround[0]->update(90.0f, f_deltaTime); // bushes
        backGround[1]->update(90.0f, f_deltaTime);


        for(int i = 0; i < 2; i ++)
            greenPipe[i]->update(190.0f, f_deltaTime);
        bird->update(f_deltaTime);
        fontCounter.n_count = bird->n_count;
        fontCounter.draw();

        if(b_FPScap && 1000/n_FPScap > int(SDL_GetTicks()-time))
        {
            SDL_Delay(1000/n_FPScap-(SDL_GetTicks()-time));
        }
        SDL_GL_SwapWindow(win);
    }

    endSDL(backGround, bird, &tex_textures, greenPipe);
    return 0;
}

void initGLandSDL()
{
    // Инициализация SDL

    if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 1, 4096 ) == -1 )
    {
        std::cout << "Audio init failed: " << SDL_GetError() << std::endl;
    }
    // Включаем двойной буфер, настраиваем цвета

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);


    win = SDL_CreateWindow("Flappy Clone",
                           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                           n_screenWidth, n_screenHeight,
                           SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    SDL_GLContext glcontext = SDL_GL_CreateContext(win); // создаем контекст OpenGL
    UNUSED(glcontext);

    if(win == NULL)
    {
        std::cout << "Unable to create window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Инициализация OpenGL

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // устанавливаем фоновый цвет на черный

    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLoadIdentity();
}

void endSDL(background* backGround[], flappy* bird, texture *tex_textures[], pipe *greenPipe[])
{
    for (int i = 0; i < 9; i++)
    {
        delete backGround[i];
    }
    delete bird;
    for (int i = 0; i < 3; i++)
    {
        delete tex_textures[i];
    }
    for (int i = 0; i < 2; i++)
    {
        delete greenPipe[i];
    }
    SDL_DestroyWindow(win);
    SDL_Quit();
}
