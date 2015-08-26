#ifndef HANDLE_H_INCLUDED
#define HANDLE_H_INCLUDED

#include "Graphics.h"

#include "SDL.h"

#include <iostream>

namespace Handle
{
	class  MainLoop_Class;

	extern MainLoop_Class MainLoop;

	void Init();

	int Quit(int);
}

#endif // HANDLE_H_INCLUDED