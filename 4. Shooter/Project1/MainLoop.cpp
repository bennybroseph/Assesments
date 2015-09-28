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
	void MainLoop::OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
	{

	}

	MainLoop::MainLoop()
	{
		m_glSurfaceBack = Graphics::LoadSurface("Images/background.png");
	}
	MainLoop::~MainLoop()
	{

	}
}