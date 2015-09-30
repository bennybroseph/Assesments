#include "Tank.h"



void Tank::Handle()
{
	m_oTime.Handle();

	Update();

	Move();
	Collision();
	if (iDistanceTraveled > 8)
	{
		//at some point we will meet a condition where we need
		//to spawn a treadmark
		//after we spawn a treadmark
		//that new object that is created
		//will be linked to the tank because it was created by it
		//but the object would "turn itself off" given a condition it would
		//meet internally
		//ie: tank is moving and gains a total distance of 100 units
		//the tank then spawns a treadmark
		//the tank keeps moving and will continue to spawn a treadmark every 100 units
		//the treadmark itself on creation would begin it's own internal "counter/timer/distancetraveled"
		//then undraw itself once it meets that condition
		//usage example:
		//tank.move();
		//if(tank.distance > 100)
		//for i 10 x
		//{	
			//tank.spawntreadmark(initial + offset);
		//}
		 //do other stuff
		//tank.spawntreadmark()
		//{ if(this->timer > 0)
		//draw(treadmarkTexture)
		//}
		m_oTreadMarks.New(
			m_fPosX + ((m_glSurfaceBase.w - 35) * cos((m_glSurfaceBase.rotation + 45) * (PI / 180.0f))),
			m_fPosY + ((m_glSurfaceBase.h - 33) * sin((m_glSurfaceBase.rotation + 45) * (PI / 180.0f))),
			m_glSurfaceBase.rotation);

		m_oTreadMarks.New(
			m_fPosX + ((m_glSurfaceBase.w - 35) * cos((m_glSurfaceBase.rotation - 225) * (PI / 180.0f))),
			m_fPosY + ((m_glSurfaceBase.h - 33) * sin((m_glSurfaceBase.rotation - 225) * (PI / 180.0f))),
			m_glSurfaceBase.rotation);
		
		iDistanceTraveled = 0;
	}
	m_oTreadMarks.Handle();
}

void Tank::Update()
{
	// Virtual, Do Nothing...
}

void Tank::Move()
{
	if (m_bForwardFlag || m_bReverseFlag)
		++iDistanceTraveled;

	if (m_bForwardFlag)
	{
		m_fPosX += (m_fVelX * ((float)m_oTime.GetTime() / 1000)) * cos((m_glSurfaceBase.rotation - 90) * (PI / 180.0f));
		
		m_fPosY += (m_fVelX * ((float)m_oTime.GetTime() / 1000)) * sin((m_glSurfaceBase.rotation - 90) * (PI / 180.0f));
		
	}
	if (m_bReverseFlag)
	{
		m_fPosX -= (m_fVelX * ((float)m_oTime.GetTime() / 1000)) * cos((m_glSurfaceBase.rotation - 90) * (PI / 180.0f));
		m_fPosY -= (m_fVelX * ((float)m_oTime.GetTime() / 1000)) * sin((m_glSurfaceBase.rotation - 90) * (PI / 180.0f));
	}

	if (m_bRightFlag)
	{
		m_glSurfaceBase.rotation += m_fVelR * ((float)m_oTime.GetTime() / 1000);

		if (m_glSurfaceBase.rotation > 360)
			m_glSurfaceBase.rotation = 0;
	}
	if (m_bLeftFlag)
	{
		m_glSurfaceBase.rotation -= m_fVelR * ((float)m_oTime.GetTime() / 1000);

		if (m_glSurfaceBase.rotation < 0)
			m_glSurfaceBase.rotation = 360;
	}
}
void Tank::Collision()
{

}

void Tank::Draw()
{
	m_oTreadMarks.Draw();

	Graphics::DrawSurface(m_glSurfaceBase, m_fPosX, m_fPosY);
	Graphics::DrawSurface(m_glSurfaceTurret, m_fPosX, m_fPosY);
}

Tank::Tank()
{
	m_bForwardFlag = false;
	m_bReverseFlag = false;

	m_bLeftFlag = false;
	m_bRightFlag = false;

	iDistanceTraveled = 0;
}
Tank::~Tank()
{

}
