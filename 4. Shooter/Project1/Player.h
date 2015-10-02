#pragma once

#include "Tank.h"

class Player : public Tank
{
private:
	int m_iMouseX, m_iMouseY;

public:
	void Update();

	void OnKeyDown(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode a_eScancode);
	void OnKeyUp(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode a_eScancode);

	void OnMouseMove(
		int a_iMouseX, int a_iMouseY, 
		int a_iVelX, int a_iVelY, 
		bool a_bLeft, bool a_bRight, bool a_bMiddle);

	Player(TimerHandle<TreadMarks::Tread> &a_oTreadTimer);
	Player();
	~Player();
};

