#pragma once

#include "EventHandle.h"

namespace LoopHandle
{
	class Loop : public EventHandle
	{
	public:
		void Run(); // Holds a prototype for any loops that inherit 'Loop'

		virtual void Handle(); // A virtual function that will get called once per loop
		virtual void Draw(); // A virtual function that will get called once per loop

		Loop();
		virtual ~Loop();

		bool m_bIsRunning; // Whether or not to keep looping
	};
}

