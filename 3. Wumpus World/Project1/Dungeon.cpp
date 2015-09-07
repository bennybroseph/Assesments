#include "Dungeon.h"

const unsigned int MAX_ROWS = 6;
const unsigned int MAX_COLLOMNS = 4;

namespace Dungeon
{
	Grid oGrid;
	Robot oRobot;

	void Handle()
	{
		oRobot.Handle();
		oGrid.Draw();
		System::Pause();
	}

	void Init()
	{
		oGrid.Fill(MAX_ROWS, MAX_COLLOMNS);
		oRobot = Robot(0, 0, DIRECTION::UP);
	}
	void Quit()
	{

	}
}