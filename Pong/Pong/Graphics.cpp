#include "Graphics.h"

namespace Graphics
{
	SDL_Window *win;

	bool full_screen;

	int winH, winW;

	int Init()
	{
		win = SDL_CreateWindow(
			"SDL2 Window...",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			1920,
			1020,
			SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_BORDERLESS);

		if (win == NULL)
		{
			std::cout << "Window not created...\n" << std::endl;
			return -1;
		}

		return 0;
	}

	void Resize(int w, int h, int scale, bool is_full_screen)
	{
		winW = w;
		winH = h;
		full_screen = is_full_screen;

		SDL_SetWindowSize(win, full_screen*(1920) + (w*scale)*(!full_screen), full_screen*(1080) + (h*scale)*(!full_screen));
		SDL_SetWindowPosition(win, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	}

	void Flip()
	{

	}

	void Quit()
	{
		SDL_DestroyWindow(win);
		SDL_Quit();
	}	
}
