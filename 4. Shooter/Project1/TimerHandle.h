#ifndef _TIMERHANDLE_H_
#define _TIMERHANDLE_H_

#include <list>

#define CALL_MEMBER_FN(OBJ, FUNC) ((OBJ).*(FUNC))

template <typename T>
class TimerHandle
{
	typedef void(T::*CallBackFunc)(void);
	typedef void(T::*UpdateFunc)(const int);
private:

	template <typename T>
	struct Timer
	{
		typedef void(T::*CallBack)(void);
		int TimeRemaining;

		T &Obj;
		CallBackFunc FuncEnd;
		UpdateFunc FuncUpdate;
	};
	std::list<Timer<T>> m_loTimer;

	const int &m_iDeltaTime;

public:
	void Update();

	void NewTimer(const int ac_iTimer, T &a_Obj, CallBackFunc a_FuncEnd, UpdateFunc a_FuncUpdate = nullptr);

	TimerHandle(const int &ac_iDeltaTime);
	TimerHandle() = delete;
	~TimerHandle();
};

template <typename T>
void TimerHandle<T>::NewTimer(const int ac_iTimer, T &a_Obj, CallBackFunc a_FuncEnd, UpdateFunc a_FuncUpdate)
{
	m_loTimer.push_back({ ac_iTimer, a_Obj, a_FuncEnd, a_FuncUpdate });
}

template <typename T>
void TimerHandle<T>::Update()
{
	std::list<Timer<T>>::iterator iter = m_loTimer.begin(), iterDelete;
	while (iter != m_loTimer.end())
	{
		iter->TimeRemaining -= m_iDeltaTime;
		if (iter->TimeRemaining <= 0)
		{
			iterDelete = iter;
			CALL_MEMBER_FN(iter->Obj, iter->FuncEnd)();
			++iter;
			m_loTimer.erase(iterDelete);
		}
		else
		{
			if (iter->FuncUpdate != nullptr)
				CALL_MEMBER_FN(iter->Obj, iter->FuncUpdate)(m_iDeltaTime);
			++iter;
		}
	}
}

template <typename T>
TimerHandle<T>::TimerHandle(const int &ac_iDeltaTime) : m_iDeltaTime(ac_iDeltaTime)
{

}
template <typename T>
TimerHandle<T>::~TimerHandle()
{

}

#endif // _TIMERHANDLE_H_