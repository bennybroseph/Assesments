////////////////////////////////////////////////////////////
// File: MainLoop.cpp
// Author: Ben Odom
// Date Created: 10/01/2015
////////////////////////////////////////////////////////////

#include "MainLoop.h"

const unsigned int CENTER_OF_SCREEN_WIDTH = 960; // The center of the screen's X position
const unsigned int CENTER_OF_SCREEN_HEIGHT = 540; // The center of the screen's Y position

const float LARGER_SCALE = 1.35f; // When you press F2, the window grows to this scale

namespace LoopHandle
{
	void MainLoop::Handle()
	{
		m_oGameTime.Handle();

		m_oPlayer->Handle();

		m_oAITimer->Update();
		for (int i = 0; i < m_voEnemy.size(); ++i) // Loops through the vector according to '.size()'
			m_voEnemy[i]->Handle();
	}

	void MainLoop::Draw()
	{
		Graphics::DrawSurface(m_glSurfaceBack, CENTER_OF_SCREEN_WIDTH, CENTER_OF_SCREEN_HEIGHT); // Draws the background surface at the center of the screen
		m_oTileMap.Draw();

		m_oTreadTimer->Update();
		m_oPlayer->Draw();

		for (int i = 0; i < m_voEnemy.size(); ++i) // Loops through the vector according to '.size()'
			m_voEnemy[i]->Draw();
	}

	void MainLoop::OnKeyDown(SDL_Keycode a_eSym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (a_eSym)
		{
		case SDLK_ESCAPE: running = false; break; // End the game

		case SDLK_F1: Graphics::Resize(1, false); break; // Set the window scale back to 1
		case SDLK_F2: Graphics::Resize(LARGER_SCALE, false); break; // Set the window to the larger scale
		case SDLK_F11: Graphics::ToggleFullScreen(); break; // Fullscreen the window

		case SDLK_F10:
		{
			m_bIsPaused = !m_bIsPaused; // Swap the state of the pause
			m_oGameTime.Pause((m_bIsPaused) ? -1000 : 0); // If it needs to pause send -1000, if it needs to resume send 0;
		}
		break;

		default: m_oPlayer->OnKeyDown(a_eSym, mod, scancode); break; // Otherwise, send the key states to the player
		}
	}
	void MainLoop::OnKeyUp(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode m_eScancode)
	{
		switch (a_eSym)
		{
		default: m_oPlayer->OnKeyUp(a_eSym, a_eMod, m_eScancode); break; // Otherwise, send the key states to the player
		}
	}

	void MainLoop::OnMouseMove(
		int a_iMouseX, int a_iMouseY,
		int a_iVelX, int a_iVelY,
		bool a_bLeft, bool a_bRight, bool a_bMiddle)
	{
		m_oPlayer->OnMouseMove(
			a_iMouseX / Graphics::GetScale(), 
			a_iMouseY / Graphics::GetScale(), 
			a_iVelX, a_iVelY, 
			a_bLeft, a_bRight, a_bMiddle); // Pass this information on to the player object
	}

	MainLoop::MainLoop()
	{
		m_glSurfaceBack = Graphics::LoadSurface("Images/background.png"); // Load Background texture

		m_oTileMap = TileMap("TileMap/OriginalMap.txt", "Images/Environment/environment.png"); // Set the Tileset object's file and image

		m_oTreadTimer = new TimerHandle<TreadMarks::Tread>(m_oGameTime.GetDeltaTime()); // Creates a new TimerHandle on the heap and sends it a reference to DeltaTime
		m_oPlayer = new Player(*m_oTreadTimer, m_oGameTime.GetDeltaTime()); // Creates a new Player on the heap and sends it a reference to DeltaTime and the TreadTimer

		m_oAITimer = new TimerHandle<Enemy>(m_oGameTime.GetDeltaTime()); // Creates a new TimerHandle on the heap and sends it a reference to DeltaTime
		m_voEnemy.push_back(
			new Enemy(*m_oTreadTimer, *m_oAITimer, m_oGameTime.GetDeltaTime(), m_oPlayer->GetPosX(), m_oPlayer->GetPosY())); // Creates a new Enemy on the heap and pushes it into the Enemy vector

		m_bIsPaused = false; // Since the game is not paused
	}
	MainLoop::~MainLoop()
	{
		delete m_oPlayer;
	}
}