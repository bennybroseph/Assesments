#include "Player.h"



void Player::OnKeyDown(SDL_Keycode a_eSym, Uint16 mod, SDL_Scancode scancode)
{
	switch (a_eSym)
	{
	case SDLK_w: m_bForwardFlag = true; break;
	case SDLK_a: m_bLeftFlag = true; break;
	case SDLK_s: m_bReverseFlag = true; break;
	case SDLK_d: m_bRightFlag = true; break;

	case SDLK_e:
	{
		
		break;
	}

	default: break;
	}
}
void Player::OnKeyUp(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode m_eScancode)
{
	switch (a_eSym)
	{
	case SDLK_w: m_bForwardFlag = false; break;
	case SDLK_a: m_bLeftFlag = false; break;
	case SDLK_s: m_bReverseFlag = false; break;
	case SDLK_d: m_bRightFlag = false; break;
	}
}

Player::Player()
{
	m_glSurfaceBase = Graphics::LoadSurface("Images/Tanks/tankGreen.png");
	m_glSurfaceTurret = Graphics::LoadSurface("Images/Tanks/barrelGreen.png");

	m_fPosX = 200;
	m_fPosY = 200;

	m_fVelX = 150;
	m_fVelY = 150;

	m_fVelR = 100;
}

Player::~Player()
{
}
