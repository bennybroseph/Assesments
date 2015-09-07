////////////////////////////////////////////////////////////
// File: LoopHandle.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the class 'MainLoop' which
//        inherits from the 'Loop' class. This class will
//        handle the main loop of the Wumpus World and call
//        all necessary functions related to that part of
//        the program
////////////////////////////////////////////////////////////

#ifndef _MAINLOOP_H_
#define _MAINLOOP_H_

#include "Loop.h"
#include "Dungeon.h"

#include <vector>

namespace LoopHandle
{
	class MainLoop : public Loop
	{
	public:

		void Handle();
		void Draw();

		void OnKeyPress(int a_iKey);
		void OnKeyRepeat(int a_iKey);
		void OnKeyRelease(int a_iKey);

		MainLoop();
		~MainLoop();
	};
}
#endif // _MAINLOOP_H_