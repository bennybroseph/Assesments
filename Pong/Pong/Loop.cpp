#include "Loop.h"

namespace Handle {
	Loop::Loop()
	{
		running = true;
	}

	Loop::~Loop()
	{
	}

	void Loop::Run()
	{
		while (running)
		{
			while (SDL_PollEvent(&event))
			{
				//Calls the redefined event function for the class
				OnEvent(&event);
			}
			Time::Set();
			Update();

			//Calls the redefined Draw function for the class
			Draw(); 
			Graphics::Flip(); 
			//Draw(); Graphics::Flip();
		}
	}

	//Empty because it is virtual
	void Loop::Update()
	{
	}

	//Empty because it is virtual
	void Loop::Draw()
	{
	}
}