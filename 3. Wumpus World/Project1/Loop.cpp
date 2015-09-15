////////////////////////////////////////////////////////////
// File: MainLoop.cpp
// Author: Ben Odom
// Date Created: 09/04/2015
////////////////////////////////////////////////////////////

#include "Loop.h"


namespace LoopHandle
{
	void Loop::Run()
	{
		while (m_bIsRunning)
		{
			PollInput(); // From EventHandle

			Handle();
		}
	}

	void Loop::Handle()
	{
		// Virtual, Do Nothing...
	}
	void Loop::Draw()
	{
		// Virtual, Do Nothing...
	}

	Loop::Loop()
	{

	}
	Loop::~Loop()
	{
		// Virtual, Do Nothing...
	}
}