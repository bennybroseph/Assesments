////////////////////////////////////////////////////////////
// File: LoopHandle.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the namespace 'LoopHandle' 
//        which will act as a handle for the games main loop
//        but not be part of it. It could technically handle
//        multiple game loops within it or completely 
//        separate games entirely
////////////////////////////////////////////////////////////

#ifndef _LOOPHANDLE_H_
#define _LOOPHANDLE_H_

#include "MainLoop.h"
#include "EventHandle.h"
#include "Dungeon.h"

namespace LoopHandle
{
	void Init();
	void Quit();
}

#endif // _LOOPHANDLE_H_