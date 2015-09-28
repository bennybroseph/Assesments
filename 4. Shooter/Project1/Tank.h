#ifndef _TANK_H_
#define _TANK_H_

#include "Graphics.h"

class Tank
{
protected:
	float m_fPosX, m_fPosY;

	float m_fRotation;

	GLSurface m_glSurfaceBase, m_glSurfaceTurret;

public:
	void Handle();

	virtual void Move();
	void Collision();

	void Draw();

	Tank();
	virtual ~Tank();
};

#endif // _TANK_H_
