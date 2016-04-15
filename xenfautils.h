#ifndef XENFAUTILS_H
#define XENFAUTILS_H

#include <GL/gl.h>

#include <SDL2/SDL_image.h>

#include <iostream>

#include "vars.h"

void loadTexture(texture* inputTexture, const char* pathToTexture, GLint textureFiltration);
void xeDDrawCross(float f_x, float f_y, float f_size);

#endif // XENFAUTILS_H
