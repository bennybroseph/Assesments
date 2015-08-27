#include "Graphics.h"

namespace Graphics
{
	SDL_Window *win;
	SDL_Renderer* renderer;
	SDL_DisplayMode monitor;

	bool full_screen;

	int winH, winW;
	
	SDL_Surface *LoadImage(char* path)
	{
		return IMG_Load(path);
	}
	void DrawImage(SDL_Surface* image, int x, int y)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

		SDL_Rect src = { 0, 0, image->w,image->h };
		SDL_Rect dest = { x, y, image->w,image->h };
		SDL_RenderCopy(renderer, texture, &src, &dest);

		//Make sure to free up memory created...otherwise it leaks for some reason
		SDL_DestroyTexture(texture);
	}

	int Init()
	{
		if (SDL_GetDesktopDisplayMode(0, &monitor) != 0)
		{
			std::cout << "Couldn't parse your monitor info..." << SDL_GetError() << std::endl << std::endl;
			return -1;
		}

		win = SDL_CreateWindow(
			"SDL2 Window...",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			monitor.w,
			monitor.h,
			SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_BORDERLESS);

		if (win == NULL)
		{
			std::cout << "Window not created..." << SDL_GetError() << std::endl << std::endl;
			return -1;
		}

		full_screen = true;
		// We must call SDL_CreateRenderer in order for draw calls to affect this window.
		renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

		// Select the color for drawing. It is set to red here.
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
		SDL_RenderSetLogicalSize(renderer, 1920, 1080);
		return 0;
	}

	void Resize(int w, int h, int scale, bool is_full_screen)
	{
		winW = w;
		winH = h;
		full_screen = is_full_screen;

		SDL_SetWindowSize(win, full_screen*(monitor.w) + (w*scale)*(!full_screen), full_screen*(monitor.h) + (h*scale)*(!full_screen));
		SDL_SetWindowPosition(win, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	}

	void Flip()
	{

		// Up until now everything was drawn behind the scenes.
		// This will show the new, red contents of the window.
		SDL_RenderPresent(renderer);

		// Clear the entire screen to our selected color.
		SDL_RenderClear(renderer);
	}

	void Quit()
	{
		SDL_DestroyWindow(win);
		SDL_Quit();
	}	
}
