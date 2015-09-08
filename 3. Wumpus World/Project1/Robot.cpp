#include "Robot.h"

// Used to avoid magic numbers
const unsigned int MAX_ROWS = 6; // The size of the grid rows
const unsigned int MAX_COLLUMNS = 4; // The size of the grid collumns

const unsigned int PRINT_WIDTH = 50;
const unsigned int PRINT_POSX = 30;

namespace Dungeon
{
	void Robot::Handle()
	{
		Clear(); 

		System::ShowCursor(); // Shows the console cursor
		System::Print("Capitalization does *not* matter", PRINT_WIDTH, PRINT_POSX, m_iPrintLine); m_iPrintLine += 2;
		System::Print("Face:  N / North | S / South | E / East | W / West", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++); 
		System::Print("Move:  U / Up    | M / Move  | Forward  | Walk", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
		System::Print("Mark:  Wumpus    | Pit       | Gold     | Clear", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
		System::Print("Arrow: F / Fire  | A / Arrow | Shoot    | Kill", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
		System::Print("--------------------------------------------------", PRINT_WIDTH, PRINT_POSX, m_iPrintLine); m_iPrintLine += 2;

		System::Print("Position:", PRINT_WIDTH, PRINT_POSX, m_iPrintLine);
		System::SetCursor(PRINT_POSX + 10, m_iPrintLine, 0);
		printf_s("%d : %d", m_iPosX, m_iPosY); m_iPrintLine += 2;

		System::Print("What will you do?", PRINT_WIDTH, PRINT_POSX, m_iPrintLine); m_iPrintLine += 2;
		System::Print(">> ", PRINT_WIDTH, PRINT_POSX, m_iPrintLine); m_iPrintLine += 2;

		char cBuffer[256]; // Will hold user input to be parsed later
		System::ShowCursor();
		std::cin.getline(cBuffer, 256);
		System::ToLower(cBuffer, 256); // Will convert the input string to all lower case letters

		if (!strcmp(cBuffer, "n") || !strcmp(cBuffer, "north"))
			m_iFacing = DIRECTION::UP; 
		if (!strcmp(cBuffer, "w") || !strcmp(cBuffer, "west"))
			m_iFacing = DIRECTION::LEFT;
		if (!strcmp(cBuffer, "s") || !strcmp(cBuffer, "south"))
			m_iFacing = DIRECTION::DOWN;
		if (!strcmp(cBuffer, "e") || !strcmp(cBuffer, "east"))
			m_iFacing = DIRECTION::RIGHT;

		bool bMoved = false; // If the player moves, this value will be set to true and the screen will be redrawn
		if (!strcmp(cBuffer, "u") || !strcmp(cBuffer, "up") || 
			!strcmp(cBuffer, "m") || !strcmp(cBuffer, "move") ||
			!strcmp(cBuffer, "forward") ||			
			!strcmp(cBuffer, "walk"))
		{
			System::SetCursor(m_iPosX, m_iPosY, 0); std::cout << m_oGrid.m_vcGrid[m_iPosX][m_iPosY];
			switch (m_iFacing)
			{
			case DIRECTION::UP: --m_iPosY; break;
			case DIRECTION::LEFT: --m_iPosX; break;
			case DIRECTION::DOWN: ++m_iPosY; break;
			case DIRECTION::RIGHT: ++m_iPosX; break;
			}
			bMoved = true;
			Collision();
		}

		char cTemp = NULL; // Will hold the tile value the user wants to mark as questionable
		if (!strcmp(cBuffer, "wumpus"))
			cTemp = TILE::WUMPUS_Q;
		if (!strcmp(cBuffer, "pit"))
			cTemp = TILE::PIT_Q;
		if (!strcmp(cBuffer, "gold"))
			cTemp = TILE::GOLD_Q;
		if (!strcmp(cBuffer, "clear"))
			cTemp = TILE::EMPTY;

		if (!strcmp(cBuffer, "f") || !strcmp(cBuffer, "fire") || 
			!strcmp(cBuffer, "a") || !strcmp(cBuffer, "arrow") ||
			!strcmp(cBuffer, "shoot") ||
			!strcmp(cBuffer, "kill"))
			FireArrow();

		if (cTemp > 0)
		{
			switch (m_iFacing)
			{
			case DIRECTION::UP:	m_oPercievedGrid.m_vcGrid[m_iPosX][m_iPosY - 1] = cTemp; break;
			case DIRECTION::LEFT: m_oPercievedGrid.m_vcGrid[m_iPosX - 1][m_iPosY] = cTemp; break;
			case DIRECTION::DOWN: m_oPercievedGrid.m_vcGrid[m_iPosX][m_iPosY + 1] = cTemp; break;
			case DIRECTION::RIGHT:	m_oPercievedGrid.m_vcGrid[m_iPosX + 1][m_iPosY] = cTemp; break;
			}
		}

		m_oPercievedGrid.Draw();
		Draw();

		if (bMoved && !m_bHasGold)
			RecieveSignal();
	}

	void Robot::RecieveSignal()
	{
		bool bMustPause = false;

		if ((m_oGrid.m_vcGrid[m_iPosX + 1][m_iPosY] == TILE::WUMPUS) ||
			(m_oGrid.m_vcGrid[m_iPosX - 1][m_iPosY] == TILE::WUMPUS) ||
			(m_oGrid.m_vcGrid[m_iPosX][m_iPosY + 1] == TILE::WUMPUS) ||
			(m_oGrid.m_vcGrid[m_iPosX][m_iPosY - 1] == TILE::WUMPUS))
		{
			bMustPause = true;
			System::Print("The Robot smells an awful stench...", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
		}

		if ((m_oGrid.m_vcGrid[m_iPosX + 1][m_iPosY] == TILE::GOLD) ||
			(m_oGrid.m_vcGrid[m_iPosX - 1][m_iPosY] == TILE::GOLD) ||
			(m_oGrid.m_vcGrid[m_iPosX][m_iPosY + 1] == TILE::GOLD) ||
			(m_oGrid.m_vcGrid[m_iPosX][m_iPosY - 1] == TILE::GOLD))
		{
			bMustPause = true;
			System::Print("The Robot sees a glitter...", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
		}

		if ((m_oGrid.m_vcGrid[m_iPosX + 1][m_iPosY] == TILE::PIT) ||
			(m_oGrid.m_vcGrid[m_iPosX - 1][m_iPosY] == TILE::PIT) ||
			(m_oGrid.m_vcGrid[m_iPosX][m_iPosY + 1] == TILE::PIT) ||
			(m_oGrid.m_vcGrid[m_iPosX][m_iPosY - 1] == TILE::PIT))
		{
			bMustPause = true;
			System::Print("The Robot feels a breeze...", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
		}

		if (bMustPause)
		{
			System::Pause();
			Clear();
		}
	}
	bool Robot::Collision()
	{
		if (m_iPosX < 1)
			m_iPosX = 1;
		if (m_iPosY < 1)
			m_iPosY = 1;

		if (m_iPosX > MAX_ROWS)
			m_iPosX = MAX_ROWS;
		if (m_iPosY > MAX_COLLUMNS)
			m_iPosY = MAX_COLLUMNS;

		if (m_iFacing < 0)
			m_iFacing = 3;
		if (m_iFacing > 3)
			m_iFacing = 0;

		if (m_oGrid.m_vcGrid[m_iPosX][m_iPosY] == TILE::WUMPUS)
		{
			Clear();

			m_bIsAlive = false;
			System::Print("You have been gobbled up by the Wumpus!", PRINT_WIDTH, PRINT_POSX, 0);
			m_oGrid.Draw();

			System::Pause();
			return true;
		}
		else if (m_oGrid.m_vcGrid[m_iPosX][m_iPosY] == TILE::PIT)
		{
			Clear();

			m_bIsAlive = false;
			System::Print("You have fallen to your death!", PRINT_WIDTH, PRINT_POSX, 0);
			m_oGrid.Draw();

			System::Pause();
			return true;
		}
		else if (m_oGrid.m_vcGrid[m_iPosX][m_iPosY] == TILE::GOLD)
		{
			Clear();

			m_bHasGold = true;
			m_oGrid.m_vcGrid[m_iPosX][m_iPosY] = TILE::EMPTY;
			System::Print("You got the gold, now get out!", PRINT_WIDTH, PRINT_POSX, 0);

			m_oPercievedGrid.Draw();
			Draw();

			System::Pause();
			system("cls");
			return true;
		}

		if ((m_iPosX == 1 && m_iPosY == 1) && (m_bHasGold))
		{
			Clear();

			m_bIsAlive = false;
			System::Print("You escaped with the gold!", PRINT_WIDTH, PRINT_POSX, 0);

			m_oGrid.Draw();
			Draw();

			System::Pause();
			return true;
		}

		return false;
	}
	void Robot::Draw()
	{
		System::SetCursor(m_iPosX, m_iPosY, 0);
		switch (m_iFacing)
		{
		case DIRECTION::UP: std::cout << "^"; break;
		case DIRECTION::LEFT: std::cout << "<"; break;
		case DIRECTION::DOWN: std::cout << "v"; break;
		case DIRECTION::RIGHT: std::cout << ">"; break;
		}
	}

	void Robot::FireArrow()
	{
		if (m_iArrowCount)
		{
			switch (m_iFacing)
			{
			case DIRECTION::UP:
			{
				if (m_oGrid.m_vcGrid[m_iPosX][m_iPosY - 1] == TILE::WUMPUS)
				{
					m_oGrid.m_vcGrid[m_iPosX][m_iPosY - 1] = TILE::EMPTY;
					--m_iArrowCount;
					System::Print("The Wumpus was slain!", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

					System::Pause();
					Clear();
				}
				else
				{
					System::Print("Nothing happened.", 0, 40, m_iPrintLine++);
					System::Print("You are out of arrows...", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

					System::Pause();
					Clear();
				}
				break;
			}
			case DIRECTION::LEFT:
			{
				if (m_oGrid.m_vcGrid[m_iPosX - 1][m_iPosY] == TILE::WUMPUS)
				{
					m_oGrid.m_vcGrid[m_iPosX - 1][m_iPosY] = TILE::EMPTY;
					--m_iArrowCount;
					System::Print("The Wumpus was slain!", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

					System::Pause();
					Clear();
				}
				else
				{
					System::Print("Nothing happened.", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
					System::Print("You are out of arrows...", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

					System::Pause();
					Clear();
				}
				break;
			}
			case DIRECTION::DOWN:
			{
				if (m_oGrid.m_vcGrid[m_iPosX][m_iPosY + 1] == TILE::WUMPUS)
				{
					m_oGrid.m_vcGrid[m_iPosX][m_iPosY + 1] = TILE::EMPTY;
					--m_iArrowCount;
					System::Print("The Wumpus was slain!", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

					System::Pause();
					Clear();
				}
				else
				{
					System::Print("Nothing happened.", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
					System::Print("You are out of arrows...", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

					System::Pause();
					Clear();
				}
				break;
			}
			case DIRECTION::RIGHT:
			{
				if (m_oGrid.m_vcGrid[m_iPosX + 1][m_iPosY] == TILE::WUMPUS)
				{
					m_oGrid.m_vcGrid[m_iPosX + 1][m_iPosY] = TILE::EMPTY;
					--m_iArrowCount;
					System::Print("The Wumpus was slain!", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

					System::Pause();
					Clear();
				}
				else
				{
					System::Print("Nothing happened.", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);
					System::Print("You are out of arrows...", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

					System::Pause();
					Clear();
				}
				break;
			}
			}
		}
		else
		{
			System::Print("Your Robot has no arrows to fire...", PRINT_WIDTH, PRINT_POSX, m_iPrintLine++);

			System::Pause();
			Clear();
		}
	}

	void Robot::GetPos(int &a_iPosX, int &a_iPosY, int &a_iFacing)
	{
		a_iPosX = m_iPosX;
		a_iPosY = m_iPosY;

		a_iFacing = m_iFacing;
	}
	bool Robot::IsAlive()
	{
		return m_bIsAlive;
	}

	void Robot::OnKeyPress(int a_iKey)
	{
		bool bMoved = false;
		char cTemp = NULL;

		switch (a_iKey)
		{
		case VK_LEFT: ++m_iFacing; break;
		case VK_RIGHT: --m_iFacing; break;
		case VK_UP:
		{
			if (m_iFacing == DIRECTION::UP)
				--m_iPosY;
			if (m_iFacing == DIRECTION::LEFT)
				--m_iPosX;
			if (m_iFacing == DIRECTION::DOWN)
				++m_iPosY;
			if (m_iFacing == DIRECTION::RIGHT)
				++m_iPosX;

			bMoved = true;

			break;
		}

		case 0x57: cTemp = TILE::WUMPUS_Q; break; // W Key
		case 0x50: cTemp = TILE::PIT_Q; break; // P Key
		case 0x47: cTemp = TILE::GOLD_Q; break; // G Key
		case 0x58: cTemp = TILE::EMPTY; break; // X Key

		case 0x46: FireArrow(); break;

		default: break;
		}

		if (cTemp > 0)
		{
			switch (m_iFacing)
			{
			case DIRECTION::UP:	m_oPercievedGrid.m_vcGrid[m_iPosX][m_iPosY - 1] = cTemp; break;
			case DIRECTION::LEFT: m_oPercievedGrid.m_vcGrid[m_iPosX - 1][m_iPosY] = cTemp; break;
			case DIRECTION::DOWN: m_oPercievedGrid.m_vcGrid[m_iPosX][m_iPosY + 1] = cTemp; break;
			case DIRECTION::RIGHT:	m_oPercievedGrid.m_vcGrid[m_iPosX + 1][m_iPosY] = cTemp; break;
			}
		}

		if (!Collision())
		{

			m_oPercievedGrid.Draw();
			Draw();

			if (bMoved && !m_bHasGold)
				RecieveSignal();
		}
	}

	void Robot::Clear()
	{
		system("cls");

		m_iPrintLine = 0;

		m_oPercievedGrid.Draw();
		Draw();
	}

	Robot::Robot()
	{

	}
	Robot::Robot(const int a_icPosX, const int a_icPosY, const int a_icFacing)
	{
		m_iPosX = a_icPosX;
		m_iPosY = a_icPosY;

		m_iFacing = a_icFacing;

		m_iArrowCount = 1;

		m_bIsAlive = true;
		m_bHasGold = false;

		Clear();

		m_oGrid.Fill(MAX_ROWS, MAX_COLLUMNS);
		m_oPercievedGrid.Fill(MAX_ROWS, MAX_COLLUMNS);

		m_oGrid.Trap(MAX_ROWS, MAX_COLLUMNS);

		m_oPercievedGrid.Draw();
		Draw();
	}
	Robot::~Robot()
	{
		// Nothing Yet
	}
}
