#include "Handle.h"

namespace Handle
{
	void Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cout << "SDL couldn't initialize...\n" << std::endl;
			system("pause");
			Quit(1);
		}

		if (Graphics::Init() != 0)
			Quit(-1);

		MainLoop_Class MainLoop;

		MainLoop.Run();
	}

	int Quit(int error)
	{
		Graphics::Quit();

		return error;
	}
}