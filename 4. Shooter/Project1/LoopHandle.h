#ifndef LOOPS_H_INCLUDED
#define LOOPS_H_INCLUDED

#include <SDL.h>

#include <ctime>

#include "Debug.h"
#include "Text.h"
#include "Graphics.h"
#include "FPS.h"
#include "MainLoop.h"

/////////////////////////////////////////////////////////////////////////////
//Namespace Loops
/////////////////////////////////////////////////////////////////////////////
//Meant to contain all "while(running)" loops
//To use, create a member function called something appropriate, and
//      copy the shell loop into the function.
//Meant to work by calling functions of all other namespaces
//You should create a member function for each loop you would run
//  Ex: Loop for menu, then loop for single-player, loop for options, etc.
/////////////////////////////////////////////////////////////////////////////

namespace LoopHandle
{
    //Inits all other namespaces of the engine
    void Setup();

    //The main draw loop, you will probably replace this when Loops is customized
    //  for your project

    //Calls the Quit() functions of all other namespaces and frees memory before program exit
    void Quit();
}

#endif // LOOPS_H_INCLUDED
