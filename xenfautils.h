#ifndef XENFAUTILS_H
#define XENFAUTILS_H

#include <GL/gl.h>

#include <SDL2/SDL_image.h>

#include <iostream>

#include "vars.h"

void loadTexture(texture* inputTexture, const char* pathToTexture, GLint textureFiltration);

#endif // XENFAUTILS_H
