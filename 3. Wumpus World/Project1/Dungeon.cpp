#include "Dungeon.h"



namespace Dungeon
{
	Grid oGrid;
	Robot oRobot;

	bool Handle() // This is called by the 'MainLoop' when text input is selected
	{
		if (oRobot.IsAlive())
			oRobot.Handle();

		return oRobot.IsAlive(); // Returns if the program should continue or not
	}

	bool OnKeyPress(int a_iKey) // THis is called by the 'MainLoop' when standard input is selected
	{
		if (oRobot.IsAlive())
			oRobot.OnKeyPress(a_iKey);

		return oRobot.IsAlive(); // Returns if the program should continue or not
	}

	void Init()
	{
		oRobot = Robot(1, 1, DIRECTION::DOWN); // Create a player character at (1, 1) facing downwards
	}
	void Quit()
	{

	}
}