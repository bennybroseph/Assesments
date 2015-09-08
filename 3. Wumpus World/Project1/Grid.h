////////////////////////////////////////////////////////////
// File: Grid.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the 'Grid' struct which
//        is part of the namespace 'Dungeon'. I decided to
//        make this a struct instead of a class because
//        even though it has one function, all members of
//        it should always be public to it's parent without
//        any worry of corruption or anything since only
//        the parent has access to it, and it doesn't modify
//        it's own values after initialization. This may be
//        bad programming, but that's my reasoning...
////////////////////////////////////////////////////////////

#ifndef _GRID_H_
#define _GRID_H_

#include "System.h"

namespace Dungeon
{
	struct Grid
	{
		std::vector<std::vector<char>> m_vcGrid; // Heard you like grids...Just hold the actual grid values. See 'enum TILE' for possible tile values

		void Draw(); // Draw the grid on the top left of the screen
		void Fill(int a_iRow, int a_iCollumn); // Fills the grid with empty tiles and surrounding walls
		void Trap(int a_iRow, int a_iCollumn); // This will add traps to the cave
	};

	enum TILE // Holds all the possible tile combinations so they can be 'switch()'ed to easily
	{
		WALL,
		EMPTY,
		WUMPUS,
		WUMPUS_Q,
		PIT,
		PIT_Q,
		GOLD,
		GOLD_Q,

		T_COUNT // How many possible tiles
	};
}

#endif // _GRID_H_
