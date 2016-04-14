#include "xenfautils.h"

void loadTexture(texture* inputTexture, const char* pathToTexture, GLint textureFiltration)
{
    SDL_Surface* surface = IMG_Load(pathToTexture);
    if (surface==NULL)
    {
        std::cout << "Error: " << SDL_GetError() << std::endl; return;
    }
    //SDL_MapRGB(surface->format, 0xFF, 0, 0xFF);
    //SDL_MapRGBA(surface->format, 0, 0, 0, 0xFF);
    //Map the color
    Uint32 colorkey = SDL_MapRGB( surface->format, 255, 0, 255);

    //Set all pixels  of color R 255, G 255, B 0, A 0 to be transparent
    SDL_SetColorKey( surface, SDL_TRUE | SDL_RLEACCEL, colorkey);

    glGenTextures(1,&inputTexture->tex);
    glBindTexture(GL_TEXTURE_2D, inputTexture->tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w,surface->h, 0, GL_RGBA,GL_UNSIGNED_BYTE,surface->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, textureFiltration);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, textureFiltration);
    inputTexture->w = surface->w;
    inputTexture->h = surface->h;
    SDL_FreeSurface(surface);
}
