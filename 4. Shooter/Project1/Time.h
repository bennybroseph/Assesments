////////////////////////////////////////////////////////////
// File: Time.h
// Author: Ben Odom
// Date Created: 10/01/2015
// Brief: This file contains functionality for creating an
//		  internal loop time. 
////////////////////////////////////////////////////////////

#ifndef _TIME_H_
#define _TIME_H_

#include <stdio.h>
#include <time.h>

class Time
{
private:
	int m_iOldTime, m_iCurrentTime; // The time last frame, and the time this frame
	int m_iOldClock; // Last value of 'clock()'
	int m_iDeltaTime; // The change in time between frames. 'm_iCurrentTime - m_iOldTime'

	int m_iWait; // The amount of time in milliseconds to wait. -1000 will be an "infinite" wait.

public:
	// Updates the current time variables
	void Handle();

	// Setter for 'm_iWait'
	void Pause(const int a_iMilliseconds);
	// Getter for 'm_iDeltaTime
	// Returns as a constant reference to the variable so that it can be stored and updates independently
	const int &GetDeltaTime();

	Time();
	~Time();
};

#endif // _TIME_H_
