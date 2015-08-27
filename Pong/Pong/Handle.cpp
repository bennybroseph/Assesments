#include "Handle.h"

namespace Handle
{
	void Init()
	{
		srand(time(NULL));

		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cout << "SDL couldn't initialize..." << SDL_GetError() << std::endl << std::endl;
			system("pause");
			Quit(1);
		}
		if (Time::Init() != 0)
		{
			std::cout << "No clue how initializing 2 variables screws up but..." << std::endl << std::endl;
			system("pause");
			Quit(1);
		}

		if (Graphics::Init() != 0)
			Quit(1);
		if (Score::Init() != 0)
			Quit(1);
		Text::Init();

		SDL_ShowCursor(0);

		MainLoop_Class MainLoop;

		MainLoop.Run();
	}

	int Quit(int error)
	{
		Graphics::Quit();

		return error;
	}
}