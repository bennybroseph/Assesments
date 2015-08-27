#include "Score.h"

namespace Score
{
	int p_score, e_score;

	int Init()
	{
		p_score = 0;
		e_score = 0;

		return 0;
	}
	
	void Handle()
	{
		if ((p_score > 8) || (e_score > 8))
			Time::pause = -1000;
	}

	void Draw()
	{
		char buffer[256];

		sprintf_s(buffer, "%d", p_score);
		Text::Print(Text::Neon, 480, 100, true, buffer);

		sprintf_s(buffer, "%d", e_score);
		Text::Print(Text::Neon, 1440, 100, true, buffer);

		if (p_score > 8)
		{
			Text::Print(Text::Neon, 980, 540, true, "You  Win");
			Text::Print(Text::Neon_Small, 980, 700, true, "Press  Space  to  Restart");
		}
		if (e_score > 8)
		{
			Text::Print(Text::Neon, 980, 540, true, "You Lose");
			Text::Print(Text::Neon_Small, 980, 700, true, "Press  Space  to  Restart");
		}
	}

	void OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (sym)
		{
		case SDLK_SPACE: 
			if (Time::pause == -1000)
			{
				p_score = 0; e_score = 0;
				Time::pause = 0;
			}
			break;

		default:
			break;
		}
	}
	void OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (sym)
		{
		default:
			break;
		}
	}
	void Quit()
	{

	}
}
