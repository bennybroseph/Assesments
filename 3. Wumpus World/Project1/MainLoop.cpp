#include "MainLoop.h"

const unsigned int PRINT_WIDTH = 50;
const unsigned int PRINT_POSX = 30;

namespace LoopHandle
{
	void MainLoop::Handle()
	{
		if (m_iControls == 0)
			m_bIsRunning = Dungeon::Handle();
	}

	void MainLoop::OnKeyPress(int a_iKey)
	{
		switch (a_iKey)
		{
		case VK_ESCAPE: m_bIsRunning = false; break;

		default:
		{
			if (m_iControls == 1)
				m_bIsRunning = Dungeon::OnKeyPress(a_iKey);
			break;
		}
		}
	}
	void MainLoop::OnKeyRepeat(int a_iKey)
	{
		switch (a_iKey)
		{

		default:break;
		}
	}
	void MainLoop::OnKeyRelease(int a_iKey)
	{
		switch (a_iKey)
		{

		default: break;
		}
	}

	MainLoop::MainLoop()
	{
		m_bIsRunning = true;

		System::Print("Do you want to use text or the arrow keys to control your character?", PRINT_WIDTH, PRINT_POSX, 0);

		System::Print(">> ", PRINT_WIDTH, PRINT_POSX, 3);

		char cBuffer[256];
		System::ShowCursor();
		std::cin.getline(cBuffer, 256);
		System::ToLower(cBuffer, 256);

		if (!strcmp(cBuffer, "text"))
			m_iControls = 0;
		else
			m_iControls = 1;

		Dungeon::Init();
	}

	MainLoop::~MainLoop()
	{
		Dungeon::Quit();
	}
}
