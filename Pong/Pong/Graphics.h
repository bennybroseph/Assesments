#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include "SDL.h"

#include <iostream>

namespace Graphics
{
	int Init();

	void Resize(int, int, int = 3, bool = false);

	void Flip();

	void Quit();
}

#endif // GRAPHICS_H_INCLUDED