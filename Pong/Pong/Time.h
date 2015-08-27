#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include "SDL.h"

#include <time.h>
#include <iostream>

namespace Time
{
	extern int pause;

	int Init();

	void Set();
	int Get();
	int GetIgnore();

	void Quit();
}

#endif // TIME_H_INCLUDED
