////////////////////////////////////////////////////////////
// File: Robot.h
// Author: Ben Odom
// Date Created: 09/04/2015
// Brief: This file contains the functions required to move 
//        the player character either by text commands or
//        by regular input. 'OnKeyPress' will be the regular
//        input and 'Handle' will be text input
////////////////////////////////////////////////////////////

#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "Grid.h"

namespace Dungeon
{
	class Robot
	{
	public:
		void Handle(); // Handles text input and parses it to move the player

		void RecieveSignal(); // Handles both text and regular input signals that get sent to the console to alert the player
		bool Collision(); // Checks to make sure the player hasn't died, found gold, returned gold, or gone into a wall
		void Draw(); // Draws the player and grid onto the screen

		void FireArrow(); // Attempts to fire an arrow at the Wumpus. Can fail and waste the arrow

		void KillWumpus(int a_iPosX, int a_iPosY); // Removes the Wumpus from the grid
		void FailShot();

		void GetPos(int &a_iPosX, int &a_iPosY, int &a_iFacing); // Returns the current position of the player and where they are facing. Currently unused
		bool IsAlive(); // Returns whether or not the player is alive. When you get the gold or die the loop will exit

		void OnKeyPress(int a_iKey); // Handles regular input and moves the player accordingly. Check 'EventHandle.h' for the technicalities of how input is gathered

		void Clear(); // Clears the screen and redraws it

		Robot(); // Empty constructor
		Robot(int a_iPosX, int a_iPosY, int a_iFacing); // Overloaded constructor with parameters to set it's values
		~Robot(); // Empty deconstructor
	private:
		int m_iPosX, m_iPosY; // X and Y position in the grid
		int m_iFacing; // Direction the player is facing. Check 'enum DIRECTION' for possible values
		int m_iArrowCount; // The amount of arrows the player is able to use

		int m_iPrintLine; // What line to print text onto since the x value is set to 40 and will otherwise wrap around poorly

		Grid m_oGrid, m_oPercievedGrid; // The actual game grid, and the one that the player can customize respectivly

		bool m_bIsAlive, m_bHasGold; // If the player is alive, and if he has collected the gold
	};

	enum DIRECTION : int // Hold the possible directions the player can face
	{
		UP,
		LEFT,
		DOWN,
		RIGHT,

		D_COUNT // How many possible directions
	};
}

#endif // _ROBOT_H_