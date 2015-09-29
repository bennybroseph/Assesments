#include "Tank.h"


void Tank::Handle()
{
	Move();
	Collision();
}

void Tank::Move()
{
	// Virtual, Do Nothing...
}
void Tank::Collision()
{

}

void Tank::Draw()
{
	Graphics::DrawSurface(
		m_glSurfaceBase, 
		m_fPosX, 
		m_fPosY, 
		67, 
		191, 
		33, 
		60);

	Graphics::DrawSurface(
		m_glSurfaceTurret, 
		m_fPosX, 
		m_fPosY, 
		67, 
		126, 
		33, 
		60);
}

Tank::Tank()
{

}
Tank::~Tank()
{

}
