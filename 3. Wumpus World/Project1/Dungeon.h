////////////////////////////////////////////////////////////
// File: Dungeon.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the 'Dungeon' namespace which
//        will act as the Wumpus World handler so to speak.
//        It has an member object of the Player 'Robot' and
//        will make sure to send output to the user as to
//        what's happening in the Wumpus World.
////////////////////////////////////////////////////////////

#ifndef _DUNGEON_H_
#define _DUNGEON_H_

#include "Robot.h"

namespace Dungeon
{
	bool Handle(); // This is called by the 'MainLoop' when text input is selected

	bool OnKeyPress(int a_iKey); // THis is called by the 'MainLoop' when standard input is selected

	void Init();
	void Quit();
}

#endif // _DUNGEON _H_