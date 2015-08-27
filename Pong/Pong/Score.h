#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include "Text.h"
#include "Time.h"

namespace Score
{
	extern int p_score, e_score;
	
	int Init();

	void Handle();
	void Draw();

	void OnKeyDown(SDL_Keycode, Uint16, SDL_Scancode);
	void OnKeyUp(SDL_Keycode, Uint16, SDL_Scancode);

	void Quit();
}

#endif // PADDLE_H_INCLUDED