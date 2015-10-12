////////////////////////////////////////////////////////////
// File: Player.cpp
// Author: Ben Odom
// Date Created: 10/01/2015
////////////////////////////////////////////////////////////

#include "Player.h"



void Player::Update()
{
	if (m_iDeltaTime > 0)
		m_glSurfaceTurret.rotation = 180 - (atan2(float(m_iMouseX - m_fPosX), float(m_iMouseY - m_fPosY)) * (180.0f / PI)); // Calculates the angle between the mouse and the player character
}

const float &Player::GetPosX()
{
	return m_fPosX;
}
const float &Player::GetPosY()
{
	return m_fPosY;
}

void Player::OnKeyDown(SDL_Keycode a_eSym, Uint16 mod, SDL_Scancode scancode)
{
	switch (a_eSym)
	{
	case SDLK_w: m_bForwardFlag = true; break; // Move angularly forward
	case SDLK_a: m_bLeftFlag = true; break; // Rotate anti-clockwise
	case SDLK_s: m_bReverseFlag = true; break; // Move angularly in reverse
	case SDLK_d: m_bRightFlag = true; break; // Rotate clockwise

	case SDLK_SPACE: m_bShoot = true; break; // Fire bullets

	default: break; // Otherwise do nothing
	}
}
void Player::OnKeyUp(SDL_Keycode a_eSym, Uint16 a_eMod, SDL_Scancode m_eScancode)
{
	switch (a_eSym)
	{
	case SDLK_w: m_bForwardFlag = false; break; // Stop moving forward
	case SDLK_a: m_bLeftFlag = false; break; // Stop turning anti-clockwise
	case SDLK_s: m_bReverseFlag = false; break; // Stop moving in reverse
	case SDLK_d: m_bRightFlag = false; break; // Stop turning clockwise

	case SDLK_SPACE: m_bShoot = false; break; // Stop shooting

	default: break; // Otherwise do nothing
	}
}

void Player::OnMouseMove(
	int a_iMouseX, int a_iMouseY,
	int a_iVelX, int a_iVelY,
	bool a_bLeft, bool a_bRight, bool a_bMiddle)
{
	// Update Mouse X and Y
	m_iMouseX = a_iMouseX; 
	m_iMouseY = a_iMouseY;
}

Player::Player(TimerHandle<TreadMarks::Tread> &a_oTreadTimer, const int &ac_iDeltaTime) : Tank(a_oTreadTimer, ac_iDeltaTime)
{
	m_glSurfaceBase = Graphics::LoadSurface("Images/Tanks/tankGreen.png"); // Loads the base image
	m_glSurfaceTurret = Graphics::LoadSurface("Images/Tanks/barrelGreen.png"); // Loads the turret image

	m_glSurfaceTurret.centerY = 45; // Sets the center of the turret image to be the pivot point

	m_fPosX = 200;
	m_fPosY = 300;

	m_fVelX = 150;
	m_fVelY = 150;

	m_fVelR = 100;

	m_iHealth = 10;

	m_iMouseX = NULL;
	m_iMouseY = NULL;

	m_oBulletHandle = new BulletHandle(ac_iDeltaTime, "Images/Bullets/bulletGreen.png"); // Sets the bullet image to match the tank
}
Player::~Player()
{
}
