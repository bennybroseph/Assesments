////////////////////////////////////////////////////////////
// File: MainLoop.h
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
#include "Robot.h"

#include <vector>

namespace LoopHandle
{
	class MainLoop : public Loop
	{
	public:
		void Handle(); // Inherited from 'Loop'. Will call 'Robot's 'Handle' function as well

		void OnKeyPress(int a_iKey); // Inherited from 'EventHandle'. Will pass this information on to 'Robot's 'OnKeyPress' as well
		void OnKeyRepeat(int a_iKey); // Inherited from 'EventHandle'.
		void OnKeyRelease(int a_iKey); // Inherited from 'EventHandle'.

		MainLoop(); // Will ask the user which kind of input they want to use
		~MainLoop();
	private:
		int m_iControls; // Will be set to 0 for text input, and 1 for regular input
	};
}
#endif // _MAINLOOP_H_