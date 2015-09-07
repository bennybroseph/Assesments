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