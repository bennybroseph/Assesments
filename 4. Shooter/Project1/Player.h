#pragma once

#include "Tank.h"

class Player : public Tank
{
private:
	// Empty

public:
	void Move();

	void OnKeyDown(SDL_Keycode a_eSym, Uint16 mod, SDL_Scancode scancode);

	Player();
	~Player();
};

