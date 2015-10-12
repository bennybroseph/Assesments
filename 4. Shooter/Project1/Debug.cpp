////////////////////////////////////////////////////////////
// File: Debug.cpp
// Author: Ben Odom
// Date Created: 10/01/2015
////////////////////////////////////////////////////////////

#include "Debug.h"

namespace Debug
{
    std::ofstream FileLog;
    std::ofstream FileError;

    void Init()
    {
        FileLog.open("Logs/D_Log.txt");
        FileError.open("Logs/D_Err.txt");
    }

    void Log(char* message)
    {
        FileLog << SDL_GetTicks() << " -- " << message << std::endl;
    }
    void Error(char* message)
    {
        FileError << SDL_GetTicks() << " -- " << message << std::endl;
    }

    void Quit()
    {
        FileLog.close();
        FileError.close();
    }
}
