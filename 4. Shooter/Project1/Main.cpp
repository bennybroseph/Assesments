#include "LoopHandle.h"

int wmain(int argc, char *argv[])
{
	LoopHandle::Setup();
	Debug::Log("Onto Quit()");
	LoopHandle::Quit();
	Debug::Log("Exited successfully");

	return 0;
} //End of Main