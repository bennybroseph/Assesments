////////////////////////////////////////////////////////////
// File: Tank.h
// Author: Ben Odom
// Date Created: 10/01/2015
// Brief: This file contains a template for all instances
//		  of a tank. Defines what it means to be a tank, 
//		  and all functionality related to it. Calls 
//		  functions in a specific order to maintain
//		  an organized logic
////////////////////////////////////////////////////////////

#ifndef _TANK_H_
#define _TANK_H_

#include "Time.h"
#include "TreadMarks.h"
#include "BulletHandle.h"

class Tank
{
protected:
	float m_fPosX, m_fPosY;
	float m_fVelX, m_fVelY;
 
	float m_fVelR; // Rotation Velocity

	bool m_bForwardFlag, m_bReverseFlag, m_bLeftFlag, m_bRightFlag;
	bool m_bShoot;

	int m_iHealth;
	
	TreadMarks *m_oTreadMarks;
	BulletHandle *m_oBulletHandle;

	GLSurface m_glSurfaceBase, m_glSurfaceTurret;

	int m_iTimeTraveled;
	int m_iTimeFiring;

	const int &m_iDeltaTime;

public:
	void Handle();
	virtual void Update(); // If the tank needs to update anything specific to it's type, do it here

	void CheckFlags();
	void Collision();

	void Draw();

	Tank(TimerHandle<TreadMarks::Tread> &a_oTreadTimer, const int &ac_iDeltaTime);
	Tank() = delete;
	virtual ~Tank();
	
};

#endif // _TANK_H_
