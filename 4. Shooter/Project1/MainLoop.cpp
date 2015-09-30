#include "MainLoop.h"

const unsigned int CENTER_OF_SCREEN_WIDTH = 960;
const unsigned int CENTER_OF_SCREEN_HEIGHT = 540;

namespace LoopHandle
{
	void MainLoop::Handle()
	{
		m_oPlayer.Handle();
	}

	void MainLoop::Draw()
	{
		Graphics::DrawSurface(m_glSurfaceBack, CENTER_OF_SCREEN_WIDTH, CENTER_OF_SCREEN_HEIGHT);

		m_oPlayer.Draw();
	}

	void MainLoop::OnKeyDown(SDL_Keycode a_eSym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (a_eSym)
		{
		case SDLK_ESCAPE: running = false; break;
		default: m_oPlayer.OnKeyDown(a_eSym, mod, scancode); break;
		}
	}
	void MainLoop::OnKeyUp(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode m_eScancode)
	{
		switch (a_eSym)
		{
		default: m_oPlayer.OnKeyUp(a_eSym, a_eMod, m_eScancode); break;
		}
	}

	void MainLoop::OnMouseMove(
		int a_iMouseX, int a_iMouseY, 
		int a_iVelX, int a_iVelY, 
		bool a_bLeft, bool a_bRight, bool a_bMiddle)
	{
		m_oPlayer.OnMouseMove(a_iMouseX, a_iMouseY, a_iVelX, a_iVelY, a_bLeft, a_bRight, a_bMiddle);
	}

	MainLoop::MainLoop()
	{
		m_glSurfaceBack = Graphics::LoadSurface("Images/background.png");
	}
	MainLoop::~MainLoop()
	{

	}
}