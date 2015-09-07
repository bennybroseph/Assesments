#pragma once

#include "EventHandle.h"

namespace LoopHandle
{
	class Loop : public EventHandle
	{
	public:
		void Run();

		virtual void Handle();
		virtual void Draw();

		Loop();
		virtual ~Loop();

		bool m_bIsRunning;
	};
}

