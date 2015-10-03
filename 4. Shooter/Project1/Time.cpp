#include "Time.h"


void Time::Handle()
{
	if (!m_iWait && m_iWait != -1000)
	{
		m_iOldTime = m_iCurrentTime;
		m_iCurrentTime = clock();
	}
	else if (m_iWait)
	{
		m_iCurrentTime = clock();
		m_iOldTime = clock();
		if (m_iWait < 0 && m_iWait != -1000)
			m_iWait = 0;
		else if (m_iWait != -1000)
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
