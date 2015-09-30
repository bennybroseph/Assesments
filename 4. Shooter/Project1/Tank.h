#ifndef _TANK_H_
#define _TANK_H_

#include "Time.h"
#include "TreadMarks.h"

class Tank
{
protected:
	float m_fPosX, m_fPosY;
	float m_fVelX, m_fVelY;
 
	float m_fVelR; // Rotation Velocity

	bool m_bForwardFlag, m_bReverseFlag, m_bLeftFlag, m_bRightFlag;
	

	Time m_oTime;
	TreadMarks m_oTreadMarks;

	GLSurface m_glSurfaceBase, m_glSurfaceTurret;

	int iDistanceTraveled;

public:
	void Handle();
	virtual void Update(); // If the tank needs to update anything specific to it's type 

	void Move();
	void Collision();

	void Draw();

	Tank();
	virtual ~Tank();
	
};

#endif // _TANK_H_
