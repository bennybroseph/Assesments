////////////////////////////////////////////////////////////
// File: Time.cpp
// Author: Ben Odom
// Date Created: 10/01/2015
////////////////////////////////////////////////////////////

#include "Time.h"


void Time::Handle()
{
	if (!m_iWait && m_iWait != -1000) // If the current loop time should not be paused
	{
		m_iOldTime = m_iCurrentTime;
		m_iCurrentTime = clock();
	}
	else if (m_iWait) // If the current loop time should be paused
	{
		m_iCurrentTime = clock();
		m_iOldTime = clock();
		if (m_iWait < 0 && m_iWait != -1000) // If the amount of time to wait has expired
			m_iWait = 0;
		else if (m_iWait != -1000) // As long as the amount of time to wait is not "infinite"
			m_iWait -= clock() - m_iOldClock;
	}

	m_iOldClock = clock();

	m_iDeltaTime = m_iCurrentTime - m_iOldTime;
}

void Time::Pause(const int ac_iMilliseconds)
{
	m_iWait = ac_iMilliseconds;
}
const int &Time::GetDeltaTime()
{
	return m_iDeltaTime;
}

Time::Time()
{
	m_iOldTime = NULL;
	m_iOldClock = clock();
	m_iCurrentTime = clock();

	m_iWait = NULL;
}


Time::~Time()
{
}
