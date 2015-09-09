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