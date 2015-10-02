#ifndef _BULLETHANDLE_H_
#define _BULLETHANDLE_H_

#include "Graphics.h"

#include <list>

class BulletHandle
{
private:
	struct Bullet
	{
		float fPosX, fPosY;
		float fVelX, fVelY;

		GLSurface glSurfaceBullet;
	};
	std::list<Bullet> m_loBullet;

	GLSurface m_glSurfaceBullet;

	int m_iDeltaTime;

public:
	void Handle(const int ac_iDeltaTime);

	void Move();
	void Collision();

	void Draw();

	void New(const float ac_fPosX, const float ac_fPosY, const float ac_fAngle);

	BulletHandle();
	~BulletHandle();
};

#endif // _BULLETHANDLE_H_
