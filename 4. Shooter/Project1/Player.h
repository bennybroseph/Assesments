#pragma once

#include "Tank.h"

class Player : public Tank
{
private:
	// Empty

public:
	void OnKeyDown(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode a_eScancode);
	void OnKeyUp(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode a_eScancode);

	Player();
	~Player();
};

