////////////////////////////////////////////////////////////
// File: MainLoop.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the namespace 'Loop' 
//        which will act as a template for all other game
//        loops
////////////////////////////////////////////////////////////

#ifndef _LOOP_H_
#define _LOOP_H_

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

#endif // _LOOP_H_