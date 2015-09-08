#include "Grid.h"

// To avoid using magic numbers, all constants are represented as such
// These are just the ASCII values of each tile set. A '_Q' is the user marked tiles; As in the user can set a tile to these values
// in order to remember that they think something might be there. So a 'WUMPUS_Q' means the user thinks a Wumpus is in that tile
const unsigned char WALL_ASCII = 219;
const unsigned char EMPTY_ASCII = 176;
const unsigned char WUMPUS_ASCII = 'W';
const unsigned char WUMPUS_Q_ASCII = 'w';
const unsigned char PIT_ASCII = ' ';
const unsigned char PIT_Q_ASCII = ' ';
const unsigned char GOLD_ASCII = 233;
const unsigned char GOLD_Q_ASCII = 233;

// The 'PIT_RATE' represents how many pits will appear. It's calculated as:
// (NumOfRowsInGrid * NumOfCollumnsInGrid) / PIT_RATE
const unsigned int PIT_RATE = 9;
// This is the direct number of Wumpus in the cave.
const unsigned int WUMPUS_RATE = 1;

namespace Dungeon
{
	void Grid::Draw() // Draws the grid in ASCII at the top left of the screen
	{
		for (int i = 0; i < m_vcGrid.size(); ++i)
		{
			for (int j = 0; j < m_vcGrid[i].size(); ++j)
			{
				System::SetCursor(i, j, 0); // Set the console cursor at (i, j) and set it's visibility to 0

				switch (m_vcGrid[i][j]) // Just switches to evaluate 'm_vcGrid[i][j]' using the enum 'TILE'
				{
				case TILE::EMPTY: std::cout << EMPTY_ASCII; break;
				case TILE::WALL: std::cout << WALL_ASCII; break;
				case TILE::WUMPUS: std::cout << WUMPUS_ASCII; break;
				case TILE::WUMPUS_Q: std::cout << WUMPUS_Q_ASCII; break;
				case TILE::PIT: std::cout << PIT_ASCII; break;
				case TILE::PIT_Q: std::cout << PIT_Q_ASCII; break;
				case TILE::GOLD: std::cout << GOLD_ASCII; break;
				case TILE::GOLD_Q: std::cout << GOLD_Q_ASCII; break;
				}
			}
		}
	}
	void Grid::Fill(int a_iRow, int a_iCollumn) // Fills the grid with empty tiles and surrounding walls
	{
		// In order to '.push_back' the 'm_vcGrid' with an entire row, I use this variable to hold 'a_iCollumn' collumns and then push it to the row
		std::vector<char> vcTemp; 

		for (int i = 0; i <= a_iRow + 1; ++i)
		{
			for (int j = 0; j <= a_iCollumn + 1; ++j)
			{
				// If it's a surrounding tile, make it a 'TILE::WALL', if it's inside make it 'TILE::EMPTY'
				if (((i == 0) || (i == a_iRow + 1)) ||
					((j == 0) || (j == a_iCollumn + 1)))
					vcTemp.push_back(TILE::WALL);
				else
					vcTemp.push_back(TILE::EMPTY);
			}
			m_vcGrid.push_back(vcTemp); // Push back the full row of 'a_iCollumn' collumns
			vcTemp.clear(); // Allow 'vcTemp' to get more values by erasing it's contents
		}
	}

	void Grid::Trap(int a_iRow, int a_iCollumn) // This will add traps to the cave
	{
		struct CanTrap
		{
			int iRow, iCollumn;
		};
		std::vector<CanTrap> voCanTrap; // This struct will hold the tile which can currently randomly be used as a trap

		for (int i = 1; i <= a_iRow; ++i)
		{
			for (int j = 1; j <= a_iCollumn; ++j)
			{
				if (((i != 1) || (j != 1)) &&
					((i != 1) || (j != 2)) &&
					((i != 2) || (j != 1)))
					voCanTrap.push_back({ i, j }); // Fill the vector with acceptable values in an attempt to make a solvable cave layout
			}
		}

		int iTemp; // Hold the randomly generated value
		for (int i = 0; i < (a_iRow*a_iCollumn) / PIT_RATE; ++i) // See 'PIT_RATE' comment
		{
			iTemp = rand() % voCanTrap.size();
			m_vcGrid[voCanTrap[iTemp].iRow][voCanTrap[iTemp].iCollumn] = TILE::PIT;
			voCanTrap.erase(voCanTrap.begin() + iTemp); // Removed the randomly generated tile position from the 'voCanTrap' vector since it now has a pit in it
		}

		for (int i = 0; i < WUMPUS_RATE; ++i)
		{
			iTemp = rand() % voCanTrap.size();
			m_vcGrid[voCanTrap[iTemp].iRow][voCanTrap[iTemp].iCollumn] = TILE::WUMPUS;
			voCanTrap.erase(voCanTrap.begin() + iTemp); // Remove the Wumpus from the randomly generated tile position from the 'voCanTrap' vector
		}

		iTemp = rand() % voCanTrap.size();
		m_vcGrid[voCanTrap[iTemp].iRow][voCanTrap[iTemp].iCollumn] = TILE::GOLD; // Throw some gold in there
	}
}
