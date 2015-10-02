#include "Player.h"


void Player::Update()
{
	if (m_iDeltaTime > 0)
		m_glSurfaceTurret.rotation = 180 - (atan2(float(m_iMouseX - m_fPosX), float(m_iMouseY - m_fPosY)) * (180.0f / PI));
}

void Player::OnKeyDown(SDL_Keycode a_eSym, Uint16 mod, SDL_Scancode scancode)
{
	switch (a_eSym)
	{
	case SDLK_w: m_bForwardFlag = true; break;
	case SDLK_a: m_bLeftFlag = true; break;
	case SDLK_s: m_bReverseFlag = true; break;
	case SDLK_d: m_bRightFlag = true; break;

	case SDLK_SPACE: m_bShoot = true; break;

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

	case SDLK_SPACE: m_bShoot = false; break;

	default: break;
	}
}

void Player::OnMouseMove(
	int a_iMouseX, int a_iMouseY,
	int a_iVelX, int a_iVelY,
	bool a_bLeft, bool a_bRight, bool a_bMiddle)
{
	m_iMouseX = a_iMouseX;
	m_iMouseY = a_iMouseY;
}

Player::Player(TimerHandle<TreadMarks::Tread> &a_oTreadTimer) : Tank(a_oTreadTimer)
{
	m_glSurfaceBase = Graphics::LoadSurface("Images/Tanks/tankGreen.png");
	m_glSurfaceTurret = Graphics::LoadSurface("Images/Tanks/barrelGreen.png");

	m_glSurfaceTurret.centerY = 45;

	m_fPosX = 200;
	m_fPosY = 300;

	m_fVelX = 150;
	m_fVelY = 150;

	m_fVelR = 100;

	m_iMouseX = NULL;
	m_iMouseY = NULL;
}
Player::Player() : Tank()
{
	
}
Player::~Player()
{
}
