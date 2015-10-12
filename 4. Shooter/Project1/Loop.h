////////////////////////////////////////////////////////////
// File: Loop.h
// Author: Ben Odom
// Date Created: 10/01/2015
// Brief: This file contains the template for all other 
//		  loops in the project
////////////////////////////////////////////////////////////

#ifndef LOOP_H_INCLUDED
#define LOOP_H_INCLUDED

#include "Graphics.h"
#include "EventHandler.h"
#include "Debug.h"
#include "FPS.h"

/////////////////////////////////////////////////////////////////////////
//Class Loop
/////////////////////////////////////////////////////////////////////////
//Loop inherits the virtual event functions from EventHandler
/////////////////////////////////////////////////////////////////////////

namespace LoopHandle
{
	class Loop : public EH
	{
	public:
		///////Constructor - Destructor//////
		Loop();

		// Must be virtual if other functions are virtual
		virtual ~Loop();

		// Contains a simple loop that runs the virtual event
		// Reason this is cool is because as each child of Loop redefines the event functions,
		// it will call the redefined ones, so every child can use the same loop
		void Run();

		virtual void Handle();

		// Redefined for each child, since they all draw different things
		virtual void Draw();

	protected:
		//////Member Variables//////
		// Keeps the loop running
		bool running;

		// Stores events that happen during the loop
		SDL_Event event;
	};
}

#endif // LOOP_H_INCLUDED
