////////////////////////////////////////////////////////////
// File: MainLoop.h
// Author: Ben Odom
// Date Created: 10/01/2015
////////////////////////////////////////////////////////////

#include "Tank.h"

const unsigned int ONE_SECOND = 1000;
const unsigned int TREAD_CREATION_TIME = 120;
const unsigned int BULLET_CREATION_TIME = 600;

void Tank::Handle()
{
	Update();

	CheckFlags();
	if (m_iTimeFiring > BULLET_CREATION_TIME && m_bShoot)
	{
		m_oBulletHandle->New(
			m_fPosX + (30 * cos((m_glSurfaceTurret.rotation - 90) * (PI / 180.0f))),
			m_fPosY + (30 * sin((m_glSurfaceTurret.rotation - 90) * (PI / 180.0f))),
			m_glSurfaceTurret.rotation);

		m_iTimeFiring = 0;
	}
	m_oBulletHandle->Handle();

	Collision();

	if (m_iTimeTraveled > TREAD_CREATION_TIME)
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
		m_oTreadMarks->New(
			m_fPosX + ((m_glSurfaceBase.w - 35) * cos((m_glSurfaceBase.rotation + 45) * (PI / 180.0f))),
			m_fPosY + ((m_glSurfaceBase.h - 33) * sin((m_glSurfaceBase.rotation + 45) * (PI / 180.0f))),
			m_glSurfaceBase.rotation);

		m_oTreadMarks->New(
			m_fPosX + ((m_glSurfaceBase.w - 35) * cos((m_glSurfaceBase.rotation - 225) * (PI / 180.0f))),
			m_fPosY + ((m_glSurfaceBase.h - 33) * sin((m_glSurfaceBase.rotation - 225) * (PI / 180.0f))),
			m_glSurfaceBase.rotation);

		m_iTimeTraveled = 0;
	}
}

void Tank::Update()
{
	// Virtual, Do Nothing...
}

void Tank::CheckFlags()
{
	if (m_bForwardFlag || m_bReverseFlag)
		m_iTimeTraveled += m_iDeltaTime;

	if (m_bForwardFlag)
	{
		m_fPosX += (m_fVelX * ((float)m_iDeltaTime / ONE_SECOND)) * cos((m_glSurfaceBase.rotation - 90) * (PI / 180.0f));

		m_fPosY += (m_fVelX * ((float)m_iDeltaTime / ONE_SECOND)) * sin((m_glSurfaceBase.rotation - 90) * (PI / 180.0f));

	}
	if (m_bReverseFlag)
	{
		m_fPosX -= (m_fVelX * ((float)m_iDeltaTime / ONE_SECOND)) * cos((m_glSurfaceBase.rotation - 90) * (PI / 180.0f));
		m_fPosY -= (m_fVelX * ((float)m_iDeltaTime / ONE_SECOND)) * sin((m_glSurfaceBase.rotation - 90) * (PI / 180.0f));
	}

	if (m_bRightFlag)
	{
		m_glSurfaceBase.rotation += m_fVelR * ((float)m_iDeltaTime / ONE_SECOND);

		if (m_glSurfaceBase.rotation > 360)
			m_glSurfaceBase.rotation = 360 - m_glSurfaceBase.rotation;
	}
	if (m_bLeftFlag)
	{
		m_glSurfaceBase.rotation -= m_fVelR * ((float)m_iDeltaTime / ONE_SECOND);

		if (m_glSurfaceBase.rotation < 0)
			m_glSurfaceBase.rotation = 360 + m_glSurfaceBase.rotation;
	}

	m_iTimeFiring += m_iDeltaTime;
}
void Tank::Collision()
{
	if (m_fPosX < m_glSurfaceBase.w / 2)
		m_fPosX = m_glSurfaceBase.w / 2;
	if (m_fPosX > 1280 - m_glSurfaceBase.w / 2)
		m_fPosX = 1280 - m_glSurfaceBase.w / 2;

	if (m_fPosY < m_glSurfaceBase.h / 2)
		m_fPosY = m_glSurfaceBase.h / 2;
	if (m_fPosY > 720 - m_glSurfaceBase.h / 2)
		m_fPosY = 720 - m_glSurfaceBase.h / 2;
}

void Tank::Draw()
{
	Graphics::DrawSurface(m_glSurfaceBase, m_fPosX, m_fPosY);

	m_oBulletHandle->Draw();

	Graphics::DrawSurface(m_glSurfaceTurret, m_fPosX, m_fPosY);

	
}

Tank::Tank(TimerHandle<TreadMarks::Tread> &a_oTreadTimer, const int &ac_iDeltaTime) : m_iDeltaTime(ac_iDeltaTime)
{
	printf("New Tank constructed\n");

	m_bForwardFlag = false;
	m_bReverseFlag = false;

	m_bLeftFlag = false;
	m_bRightFlag = false;

	m_bShoot = false;

	m_iTimeTraveled = NULL;
	m_iTimeFiring = BULLET_CREATION_TIME;	

	m_oTreadMarks = new TreadMarks(a_oTreadTimer);
}
Tank::~Tank()
{
	delete m_oBulletHandle;
}
