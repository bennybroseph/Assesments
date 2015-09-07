#include "MainLoop.h"


namespace LoopHandle
{
	void MainLoop::Handle()
	{
		Dungeon::Handle();
	}
	void MainLoop::Draw()
	{

	}

	void MainLoop::OnKeyPress(int a_iKey)
	{
		switch (a_iKey)
		{
		case VK_LEFT: break;
		case VK_RIGHT: break;
		case VK_UP: break;
		case VK_DOWN: break;

		case VK_ESCAPE: m_bIsRunning = false; break;
		default: break;
		}
	}
	void MainLoop::OnKeyRepeat(int a_iKey)
	{
		switch (a_iKey)
		{
		case VK_LEFT: break;
		case VK_RIGHT: break;
		case VK_UP: break;
		case VK_DOWN: break;

		default:break;
		}
	}
	void MainLoop::OnKeyRelease(int a_iKey)
	{
		switch (a_iKey)
		{
		case VK_LEFT: break;
		case VK_RIGHT: break;
		case VK_UP: break;
		case VK_DOWN: break;

		default: break;
		}
	}

	MainLoop::MainLoop()
	{
		m_bIsRunning = true;
		Dungeon::Init();

	}

	MainLoop::~MainLoop()
	{
		Dungeon::Quit();
	}
}
