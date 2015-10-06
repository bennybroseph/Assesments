#include "MainLoop.h"

const unsigned int CENTER_OF_SCREEN_WIDTH = 960;
const unsigned int CENTER_OF_SCREEN_HEIGHT = 540;

const float LARGER_SCALE = 1.35f;

namespace LoopHandle
{
	void MainLoop::Handle()
	{
		m_oGameTime.Handle();
		
		m_oPlayer->Handle();

		m_oAITimer->Update();
		for (int i = 0; i < m_voEnemy.size(); ++i)
			m_voEnemy[i]->Handle();
	}
	
	void MainLoop::Draw()
	{
		Graphics::DrawSurface(m_glSurfaceBack, CENTER_OF_SCREEN_WIDTH, CENTER_OF_SCREEN_HEIGHT);
		m_oTileMap.Draw();

		m_oTreadTimer->Update();
		m_oPlayer->Draw();

		for (int i = 0; i < m_voEnemy.size(); ++i)
			m_voEnemy[i]->Draw();
	}

	void MainLoop::OnKeyDown(SDL_Keycode a_eSym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (a_eSym)
		{
		case SDLK_ESCAPE: running = false; break;

		case SDLK_F1: Graphics::Resize(1, false); break;
		case SDLK_F2: Graphics::Resize(LARGER_SCALE, false); break;
		case SDLK_F11: Graphics::ToggleFullScreen(); break;

		case SDLK_F10: 
		{
			m_bIsPaused = !m_bIsPaused; 
			m_oGameTime.Pause((m_bIsPaused) ? 0 : -1000);
		}
		break;

		default: m_oPlayer->OnKeyDown(a_eSym, mod, scancode); break;
		}
	}
	void MainLoop::OnKeyUp(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode m_eScancode)
	{
		switch (a_eSym)
		{
		default: m_oPlayer->OnKeyUp(a_eSym, a_eMod, m_eScancode); break;
		}
	}

	void MainLoop::OnMouseMove(
		int a_iMouseX, int a_iMouseY,
		int a_iVelX, int a_iVelY,
		bool a_bLeft, bool a_bRight, bool a_bMiddle)
	{
		m_oPlayer->OnMouseMove(a_iMouseX/Graphics::GetScale(), a_iMouseY/Graphics::GetScale(), a_iVelX, a_iVelY, a_bLeft, a_bRight, a_bMiddle);
	}

	MainLoop::MainLoop()
	{
		m_glSurfaceBack = Graphics::LoadSurface("Images/background.png");

		m_oTileMap = TileMap("TileMap/OriginalMap.txt", "Images/Environment/environment.png");

		m_oTreadTimer = new TimerHandle<TreadMarks::Tread>(m_oGameTime.GetDeltaTime());
		m_oPlayer = new Player(*m_oTreadTimer, m_oGameTime.GetDeltaTime());

		m_oAITimer = new TimerHandle<Enemy>(m_oGameTime.GetDeltaTime());
		m_voEnemy.push_back(new Enemy(*m_oTreadTimer, *m_oAITimer, m_oGameTime.GetDeltaTime(), m_oPlayer->GetPosX(), m_oPlayer->GetPosY()));
	}
	MainLoop::~MainLoop()
	{
		delete m_oPlayer;
	}
}