#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "Graphics.h"

#include <SDL_ttf.h>

#include <vector>

namespace Text
{
	struct Font_Type
	{
		TTF_Font* font;
		SDL_Color color;

		SDL_Surface* Surface;

		struct Glyph
		{
			int minx, maxx, miny, maxy, advance;
		};

		Glyph Char[256];
	};

	void Init();
	void Quit();

	void Print(Font_Type, int, int, bool, int);
	void Print(Font_Type, int, int, bool, const char*);

	extern Font_Type Pokemon_Normal;
	extern Font_Type Neon, Neon_Small;
}

#endif  //TEXT_H_INCLUDED