#ifndef _LOOPHANDLE_H_
#define _LOOPHANDLE_H_

#include "LoopHandle.h"



namespace LoopHandle
{
	void Init()
	{
		System::Init();

		MainLoop oMainLoop; // Creates an object of the 'MainLoop' class
		oMainLoop.Run();
	}
	void Quit()
	{
		System::Quit();
	}
}

#endif // _LOOPHANDLE_H_