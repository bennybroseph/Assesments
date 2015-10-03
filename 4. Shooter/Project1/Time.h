#ifndef _TIME_H_
#define _TIME_H_

#include <stdio.h>
#include <time.h>

class Time
{
private:
	int m_iOldTime, m_iCurrentTime;
	int m_iOldClock; // Last value of 'clock()'
	int m_iDeltaTime;

	int m_iWait;

public:
	void Handle();

	void Pause(const int a_iMilliseconds);
	const int &GetDeltaTime();

	Time();
	~Time();
};

#endif // _TIME_H_
