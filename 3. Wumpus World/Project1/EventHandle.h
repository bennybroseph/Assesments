////////////////////////////////////////////////////////////
// File: EventHandle.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the 'EventHandle' class which
//        contains all the virtual functions needed for 
//        input. All of the 'OnKey' functions get called
//        automatically in the loop, and simply need to be 
//        redefined by the inheriting class to be used.
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
	void ParseInput(); // Decides which keys have been pressed/released and which need to be repeated
	void OrderInput(); // If input has moved around in the vector, re-orders it to match 
	void PollInput(); // Grabs input from 'GetAsyncKeyState()'

	// There is no built-in functionality for key presses and releases, so calling these functions when inputs change will simulate it
	virtual void OnKeyPress(int a_iKey); // Gets called when a key is pressed down initially
	virtual void OnKeyRepeat(int a_iKey); // Gets called when the delay time has been reached, and everytime the repeat time has been reached
	virtual void OnKeyRelease(int a_iKey); // Gets called whne the key is no longer recognized as being pressed down

	EventHandle();
	virtual ~EventHandle();
private:
	// This vector hold all the keys pressed on the current frame and the last one respectively
	std::vector<int> m_vKeys, m_vPrevKeys;
	// These vectors hold the time in milliseconds when the key can be considered held long enough to request a single repeat, and then continuous repetition respectively
	std::vector<int> m_vUntilRepeat, m_vUntilPressed;
};

#endif // _EVENTHANDLE_H_