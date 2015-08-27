#include "Text.h"

namespace Text
{
	Font_Type Pokemon_Normal;
	Font_Type Neon, Neon_Small;

	void Init()
	{
		TTF_Init();

		Pokemon_Normal.color = { 255, 255, 255, 0 };

		Pokemon_Normal.font = TTF_OpenFont("Fonts/PokemonRed.ttf", 200);
		if (Pokemon_Normal.font == NULL)
			printf("failure to load");

		int i;
		for (i = 0; i < 256; i++)
		{
			if (TTF_GlyphMetrics(Pokemon_Normal.font, i,
				&Pokemon_Normal.Char[i].minx, &Pokemon_Normal.Char[i].maxx, &Pokemon_Normal.Char[i].miny, &Pokemon_Normal.Char[i].maxy,
				&Pokemon_Normal.Char[i].advance) == -1)
				printf("%s\n", TTF_GetError());
		}

		Neon.color = { 255, 255, 255, 0 };

		Neon.font = TTF_OpenFont("Fonts/display_gothic_c.ttf", 200);
		if (Neon.font == NULL)
			printf("failure to load");

		for (i = 0; i < 256; i++)
		{
			if (TTF_GlyphMetrics(Neon.font, i,
				&Neon.Char[i].minx, &Neon.Char[i].maxx, &Neon.Char[i].miny, &Neon.Char[i].maxy,
				&Neon.Char[i].advance) == -1)
				printf("%s\n", TTF_GetError());
		}

		Neon_Small.color = { 255, 255, 255, 0 };

		Neon_Small.font = TTF_OpenFont("Fonts/display_gothic.ttf", 70);
		if (Neon_Small.font == NULL)
			printf("failure to load");

		for (i = 0; i < 256; i++)
		{
			if (TTF_GlyphMetrics(Neon_Small.font, i,
				&Neon_Small.Char[i].minx, &Neon_Small.Char[i].maxx, &Neon_Small.Char[i].miny, &Neon_Small.Char[i].maxy,
				&Neon_Small.Char[i].advance) == -1)
				printf("%s\n", TTF_GetError());
		}
	}

	void Print(Font_Type Font, int x, int y, bool align, const char* text)
	{
		std::vector<std::string> lines;

		char hold[256];
		strcpy_s(hold, "");

		const char* i;
		if ((i = strchr(text, 10)) != NULL)
		{
			strncat_s(hold, text, int(i - text));
			lines.push_back(hold);
			strcpy_s(hold, i + 1);
			lines.push_back(hold);
		}
		else
		{
			lines.push_back(text);
		}

		// Write text to surface
		int j;
		for (j = 0; j < lines.size(); j++)
		{
			Font.Surface = TTF_RenderText_Blended(Font.font, lines[j].c_str(), Font.color);

			Graphics::DrawImage(Font.Surface, x - (align)*(Font.Surface->w/2), (y + (j * 120)) - (Font.Surface->h/2));
		}
		SDL_FreeSurface(Font.Surface);
	}

	void Print(Font_Type Font, int x, int y, bool align, int text)
	{
		char buffer[256];

		sprintf_s(buffer, "%d", text);
		Print(Font, x, y, align, buffer);
	}

	void Quit()
	{
		//SDL_FreeSurface(image);Debug::Log("Free Complete");
		TTF_CloseFont(Pokemon_Normal.font); 
		TTF_CloseFont(Neon.font);
		TTF_CloseFont(Neon_Small.font);
	}
}
