////////////////////////////////////////////////////////////
// File: TimerHandle.h
// Author: Ben Odom
// Date Created: 10/01/2015
// Brief: This file contains functionality for creating 
//		  timers which automatically call functions upon
//		  completion and an optional update function to
//		  call every frame.
////////////////////////////////////////////////////////////

#ifndef _TIMERHANDLE_H_
#define _TIMERHANDLE_H_

#include <list>

#define CALL_MEMBER_FN(OBJ, FUNC) ((OBJ).*(FUNC)) // Makes calling function pointers using an object much less clunky

template <typename T>
class TimerHandle
{
	typedef void(T::*CallBackFunc)(void);		// Allows for easier typing of a function pointer acting as a callback 
	typedef void(T::*UpdateFunc)(const int);	// Allows for easier typing of a function pointer acting as an update call
private:

	template <typename T>
	struct Timer
	{
		int TimeRemaining; // Time remaining in 'this' timer

		T &Obj; // The object to reference when calling function pointers
		CallBackFunc FuncEnd;	// Gets called when the timer ends
		UpdateFunc FuncUpdate;  // Gets called every frame when the timer is in countdown
	};
	std::list<Timer<T>> m_loTimer; // List for the timers

	const int &m_iDeltaTime; // A constant reference to 'DeltaTime' in the current loop

public:
	// Updates the timer values and calls function pointers as needed
	void Update();

	// Creates a new timer 
	// Expects an amount of timer, a Callback when the timer ends, and an optional Update function
	void NewTimer(const int ac_iTimer, T &a_Obj, CallBackFunc a_FuncEnd, UpdateFunc a_FuncUpdate = nullptr);

	// The only constructor
	// Must pass a reference to 'DeltaTime' or the timer will not work properly
	TimerHandle(const int &ac_iDeltaTime);
	// You cannot use the default constructor
	TimerHandle() = delete; // Make sure the default constructor cannot be called
	~TimerHandle();
};

template <typename T>
void TimerHandle<T>::NewTimer(const int ac_iTimer, T &a_Obj, CallBackFunc a_FuncEnd, UpdateFunc a_FuncUpdate)
{
	m_loTimer.push_back({ ac_iTimer, a_Obj, a_FuncEnd, a_FuncUpdate }); // Create a new instance of the Timer
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