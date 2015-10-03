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
	
	TreadMarks m_oTreadMarks;
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
	Tank();
	virtual ~Tank();
	
};

#endif // _TANK_H_
