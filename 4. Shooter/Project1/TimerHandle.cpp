#include "TimerHandle.h"



void TimerHandle::Update(const int ac_iDeltaTime)
{
	std::list<Timer>::iterator iter = m_loTimer.begin(), iterDelete;
	while (iter != m_loTimer.end())
	{
		iter->TimeRemaining -= ac_iDeltaTime;
		if (iter->TimeRemaining <= 0)
		{
			iterDelete = iter;
			iter->Func();
			++iter;
			m_loTimer.erase(iterDelete);
		}
		else
			++iter;
	}
}

//typedef void (*callback)(void);
typedef char** strang;

void TimerHandle::NewTimer(const int ac_iTimer, CallBack a_Func)
{
	m_loTimer.push_back({ ac_iTimer, a_Func });	
}

TimerHandle::TimerHandle()
{

}
TimerHandle::~TimerHandle()
{

}
