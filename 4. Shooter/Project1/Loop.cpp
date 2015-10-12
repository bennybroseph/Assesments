////////////////////////////////////////////////////////////
// File: Loop.cpp
// Author: Ben Odom
// Date Created: 10/01/2015
////////////////////////////////////////////////////////////

#include "Loop.h"

namespace LoopHandle
{
	Loop::Loop()
	{
		running = true;
	}

	Loop::~Loop()
	{
	}

	void Loop::Run()
	{
		Debug::Log("Enter loop");
		char buffer[64];

		while (running)
		{
			while (SDL_PollEvent(&event))
			{
				//Calls the redefined event function for the class
				OnEvent(&event);
			}
			Handle();

			//Calls the redefined Draw function for the class
			Draw();

			FPS::Update();
			FPS::PrintFPS();

			Graphics::Flip();
		}

		Debug::Log("Exit Loop");
	}

	//Empty because it is virtual
	void Loop::Handle()
	{
	}

	//Empty because it is virtual
	void Loop::Draw()
	{
	}
}
