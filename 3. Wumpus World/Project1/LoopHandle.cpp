#ifndef _LOOPHANDLE_H_
#define _LOOPHANDLE_H_

#include "LoopHandle.h"



namespace LoopHandle
{
	void Init()
	{
		System::Init();

		MainLoop oMainLoop;
		oMainLoop.Run();
	}
	void Quit()
	{
		System::Quit();
	}
}

#endif // _LOOPHANDLE_H_