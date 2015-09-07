////////////////////////////////////////////////////////////
// File: LoopHandle.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the 'LoopHandle' namespace and
//        it's small class 'Loop' which is basically a blue
//        print for the 'Main Loop' class which will
//        hold the code for Wumpus World's loop sequence
////////////////////////////////////////////////////////////

#ifndef _EVENTHANDLE_H_
#define _EVENTHANDLE_H_

#include "System.h"

#include <vector>

#include <Windows.h>
#include <ctime>

class EventHandle
{
public:
	void ParseInput();
	void OrderInput();
	void PollInput();

	// There is no 'OnKeyRelease'-like behavior, so functions must act on a press. 
	// An internal timer for 'EventHandle' will try to simulate a repeat keystrokes functionality for when a button is held for a long time
	virtual void OnKeyPress(int a_iKey);
	virtual void OnKeyRepeat(int a_iKey);
	virtual void OnKeyRelease(int a_iKey);

	EventHandle();
	virtual ~EventHandle();
private:
	// This vector hold all the keys pressed on the current frame and the last one respectively
	std::vector<int> m_vKeys, m_vPrevKeys;
	// These vectors hold the time in milliseconds when the key can be considered held long enough to request a single repeat, and then continuous repetition respectively
	std::vector<int> m_vSinceRepeat, m_vSincePressed;
};

#endif // _EVENTHANDLE_H_