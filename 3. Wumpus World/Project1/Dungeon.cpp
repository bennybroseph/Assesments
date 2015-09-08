#include "Dungeon.h"



namespace Dungeon
{
	Grid oGrid;
	Robot oRobot;

	bool Handle()
	{
		if (oRobot.IsAlive())
			oRobot.Handle();

		return oRobot.IsAlive();
	}

	bool OnKeyPress(int a_iKey)
	{
		if (oRobot.IsAlive())
			oRobot.OnKeyPress(a_iKey);

		return oRobot.IsAlive();
	}

	void Init()
	{
		oRobot = Robot(1, 1, DIRECTION::DOWN);
	}
	void Quit()
	{

	}
}