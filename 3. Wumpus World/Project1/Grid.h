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
		std::vector<std::vector<char>> m_vcGrid;

		void Draw();
		void Fill(int a_iRow, int a_iCollumn);
	};

	enum TILE
	{
		EMPTY,
		WALL,
		WUMPUS,
		WUMPUS_Q,
		PIT,
		PIT_Q,
		GOLD,
		GOLD_Q
	};
}

#endif // _GRID_H_
