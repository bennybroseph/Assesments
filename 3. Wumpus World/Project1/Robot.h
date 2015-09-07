////////////////////////////////////////////////////////////
// File: Robot.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the AI that goes through
//        the Wumpus World. It will handle itself entirely.
//        For debugging purposes it will check for death, 
//        but this will be un-nessassary once programmed.
////////////////////////////////////////////////////////////

#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "Grid.h"

#include <limits.h>

namespace Dungeon
{
	class Robot
	{
	public:
		void Handle();

		void Move();
		void Collision();

		void GetPos(int &a_iPosX, int &a_iPosY, int &a_iFacing);

		Robot(const int a_ciPosX, const int a_ciPosY, const int a_ciFacing);
		Robot();
		~Robot();
	private:
		int m_iPosX, m_iPosY;
		int m_iFacing;

		bool m_bIsAlive;
	};

	enum DIRECTION : int
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,

		COUNT
	};
}

#endif // _ROBOT_H_