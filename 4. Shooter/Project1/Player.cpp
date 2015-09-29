#include "Player.h"


void Player::Move()
{

}

void Player::OnKeyDown(SDL_Keycode a_eSym, Uint16 mod, SDL_Scancode scancode)
{
	switch (a_eSym)
	{
	case SDLK_RIGHT: m_glSurfaceTurret.rotation[0] += 2.0f; break;
	case SDLK_LEFT: m_glSurfaceTurret.rotation[0] -= 2.0f; break;
	default: break;
	}
}

Player::Player()
{
	m_glSurfaceBase = Graphics::LoadSurface("Images/tanks.png");
	m_glSurfaceTurret = Graphics::LoadSurface("Images/tanks.png");

	m_fPosX = 200;
	m_fPosY = 200;
}

Player::~Player()
{
}
