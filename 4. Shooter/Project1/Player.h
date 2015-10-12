////////////////////////////////////////////////////////////
// File: Player.h
// Author: Ben Odom
// Date Created: 10/01/2015
// Brief: This file contains all necessary functionality
//		  for a player tank. It accepts user input, and 
//		  the turret follows the mouse. Inherits all 
//		  variables and functions from 'Tank.h'
////////////////////////////////////////////////////////////

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Tank.h"

class Player : public Tank
{
private:
	int m_iMouseX, m_iMouseY; // The mouse's current X and Y

public:
	// Player specific update function inherited from the virtual one in 'Tank.h'
	// Updates the turret image's rotation based on the mouse
	void Update(); 

	// Returns the player's 'm_fPosX' as a constant reference
	const float &GetPosX();
	// Returns the player's 'm_fPosY' as a constant reference
	const float &GetPosY();

	// Gets called by 'oMainLoop' whenever a key is pressed down
	void OnKeyDown(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode a_eScancode);
	// Gets called by 'oMainLoop' whenever a key is pressed released
	void OnKeyUp(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode a_eScancode);

	//Gets called by 'oMainLoop' whenever the mouse is in motion and the window is in focus
	void OnMouseMove(
		int a_iMouseX, int a_iMouseY, 
		int a_iVelX, int a_iVelY, 
		bool a_bLeft, bool a_bRight, bool a_bMiddle);

	// Constructor which requires a reference to the TreadTimer and DeltaTime
	Player(TimerHandle<TreadMarks::Tread> &a_oTreadTimer, const int &ac_iDeltaTime);
	// You cannot use this function
	Player() = delete; // Make sure a default constructor cannot be called
	// Default De-Constructor
	~Player();
};

#endif // _PLAYER_H_