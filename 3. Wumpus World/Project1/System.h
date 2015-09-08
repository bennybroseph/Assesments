////////////////////////////////////////////////////////////
// File: Dungeon.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the 'System' namespace. This
//        namespace will have functions to make printing
//        to the console simple and with high functionality
//        rather than a simple per line print like 
//        std::cout provides alone. It will also include
//        random number and input functionality.
////////////////////////////////////////////////////////////

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

#include <windows.h>
#include <stdlib.h>
#include <time.h>

namespace System
{
	enum COLOR : int
	{
		BLACK,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN,
		LIGHT_GRAY,
		DARK_GRAY,
		LIGHT_BLUE,
		LIGHT_GREEN,
		LIGHT_CYAN,
		LIGHT_RED,
		LIGHT_MAGENTA,
		YELLOW,
		WHITE
	};

	void Print(const int ac_iPosX, const int ac_iPosY, const char *ac_pcFormat, ...);
	void Print(const std::string ac_sTextToPrint, const int ac_ciLength, const int ac_iPosX = -1, const int ac_iPosY = -1);
	
	void ToLower(char * a_pcUppercaseWord, const int ac_iSize);

	void SetCursor(short a_iPosX, short a_iPosY, bool a_bShowCursor);
	void ShowCursor();
	void HideCursor();

	void Pause();

	// Uses the math function 'floor' after adding 0.5f to ensure numbers are rounded upwards
	int Round(float a_fNum);

	// Will return a random number as either a float or an int based on which type is passed
	// Expects a starting number and an ending number such as 1, 10 which gets a number between 1 and 10
	// Make sure to put an 'f' at the end of number constants to define it as float such as '1.0f'
	int Random(int a_fMin, int a_fMax);
	float Random(float a_fMin, float a_fMax);

	void Init(const int a_ciColor = LIGHT_GRAY);
	void Quit();
}

#endif // _SYSTEM_H_
