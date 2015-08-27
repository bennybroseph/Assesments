#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>

namespace Graphics
{
	int Init();

	SDL_Surface *LoadImage(char*);
	void DrawImage(SDL_Surface*, int, int);

	void Resize(int, int, int = 3, bool = false);

	void Flip();

	void Quit();
}

#endif // GRAPHICS_H_INCLUDED