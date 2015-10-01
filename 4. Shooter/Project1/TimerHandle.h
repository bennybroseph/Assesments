#ifndef _TIMERHANDLE_H_
#define _TIMERHANDLE_H_

#include <list>

class TimerHandle
{
private:
	typedef void(*CallBack)(void);

	struct Timer
	{
		int TimeRemaining;

		void(*Func)();
	};
	std::list<Timer> m_loTimer;

public:
	void Update(const int ac_iDeltaTime);

	void NewTimer(const int ac_iTimer, CallBack a_Func);

	TimerHandle();
	~TimerHandle();
};

#endif // _TIMERHANDLE_H_

