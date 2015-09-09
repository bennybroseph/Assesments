#include "MainLoop.h"

const unsigned int PRINT_WIDTH = 50;
const unsigned int PRINT_POSX = 30;

namespace LoopHandle
{
	void MainLoop::Handle() // Inherited from 'Loop'. Will call 'Robot's 'Handle' function as well
	{
		if (m_iControls == 0)
			m_bIsRunning = Dungeon::Handle();
	}

	void MainLoop::OnKeyPress(int a_iKey) // Inherited from 'EventHandle'. Will pass this information on to 'Robot's 'OnKeyPress' as well
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
	void MainLoop::OnKeyRepeat(int a_iKey) // Inherited from 'EventHandle'.
	{
		switch (a_iKey)
		{

		default:break;
		}
	}
	void MainLoop::OnKeyRelease(int a_iKey) // Inherited from 'EventHandle'.
	{
		switch (a_iKey)
		{

		default: break;
		}
	}

	MainLoop::MainLoop() // Will ask the user which kind of input they want to use
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
