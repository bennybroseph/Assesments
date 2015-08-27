#include "Time.h"

namespace Time
{
	int current, previous;
	int pause;

	int Init()
	{
		current = SDL_GetTicks();
		previous = 0;

		pause = 500;

		return 0;
	}

	void Set()
	{
		previous = current;
		
		if ((pause > 0) && (pause > -1000))
			pause -= SDL_GetTicks() - current;

		current = SDL_GetTicks();

		if ((pause < 0) && (pause > -1000))
			pause = 0;
	}

	int Get()
	{
		if (pause)
			return 0;
		
		return current - previous;
	}

	int GetIgnore()
	{
		if (pause == -1000)
			return 0;
		return current - previous;
	}

	void Quit()
	{

	}
}