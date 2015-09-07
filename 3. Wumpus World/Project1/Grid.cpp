#include "Grid.h"

const unsigned char WALL_ASCII = 219;
const unsigned char EMPTY_ASCII = 176;
const unsigned char WUMPUS_ASCII = 'W';
const unsigned char PIT_ASCII = ' ';
const unsigned char GOLD_ASCII = 233;

const unsigned int PIT_RATE = 9;
const unsigned int WUMPUS_RATE = 1;

namespace Dungeon
{
	void Grid::Draw()
	{
		for (int i = 0; i < m_vcGrid.size(); ++i)
		{
			for (int j = 0; j < m_vcGrid[i].size(); ++j)
			{
				System::SetCursor(i, j, 1);

				switch (m_vcGrid[i][j])
				{
				case TILE::EMPTY: std::cout << EMPTY_ASCII; break;
				case TILE::WALL: std::cout << WALL_ASCII; break;
				case TILE::WUMPUS: std::cout << WUMPUS_ASCII; break;
				case TILE::PIT: std::cout << PIT_ASCII; break;
				case TILE::GOLD: std::cout << GOLD_ASCII; break;
				}
			}
		}
	}
	void Grid::Fill(int a_iRow, int a_iCollumn)
	{
		std::vector<char> vcTemp;

		for (int i = 0; i <= a_iRow + 1; ++i)
		{
			for (int j = 0; j <= a_iCollumn + 1; ++j)
			{
				if (((i == 0) || (i == a_iRow + 1)) ||
					((j == 0) || (j == a_iCollumn + 1)))
					vcTemp.push_back(TILE::WALL);
				else
					vcTemp.push_back(TILE::EMPTY);
			}
			m_vcGrid.push_back(vcTemp);
			vcTemp.clear();
		}

		struct CanTrap
		{
			int iRow, iCollumn;
		};
		std::vector<CanTrap> voCanTrap;

		for (int i = 1; i <= a_iRow; ++i)
		{
			for (int j = 1; j <= a_iCollumn; ++j)
			{
				if (((i != 1) || (j != 1)) &&
					((i != 1) || (j != 2)) &&
					((i != 2) || (j != 1)))
					voCanTrap.push_back({ i, j });
			}
		}

		int iTemp;
		for (int i = 0; i < (a_iRow*a_iCollumn) / PIT_RATE; ++i)
		{
			iTemp = rand() % voCanTrap.size();
			m_vcGrid[voCanTrap[iTemp].iRow][voCanTrap[iTemp].iCollumn] = TILE::PIT;
			voCanTrap.erase(voCanTrap.begin() + iTemp);
		}

		for (int i = 0; i < WUMPUS_RATE; ++i)
		{
			iTemp = rand() % voCanTrap.size();
			m_vcGrid[voCanTrap[iTemp].iRow][voCanTrap[iTemp].iCollumn] = TILE::WUMPUS;
			voCanTrap.erase(voCanTrap.begin() + iTemp);
		}

		iTemp = rand() % voCanTrap.size();
		m_vcGrid[voCanTrap[iTemp].iRow][voCanTrap[iTemp].iCollumn] = TILE::GOLD;
	}
}
