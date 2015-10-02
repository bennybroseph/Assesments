#include "BulletHandle.h"

const unsigned int ONE_SECOND = 1000;

void BulletHandle::Handle(const int ac_iDeltaTime)
{
	m_iDeltaTime = ac_iDeltaTime;

	Move();
	Collision();
}

void BulletHandle::Move()
{
	for (
		std::list<Bullet>::iterator iter = m_loBullet.begin();
		iter != m_loBullet.end();
		++iter)
	{
		iter->fPosX += (iter->fVelX * ((float)m_iDeltaTime / ONE_SECOND)) * cos((iter->glSurfaceBullet.rotation - 90) * (PI / 180.0f));
		iter->fPosY += (iter->fVelY * ((float)m_iDeltaTime / ONE_SECOND)) * sin((iter->glSurfaceBullet.rotation - 90) * (PI / 180.0f));
	}
}
void BulletHandle::Collision()
{
	std::list<Bullet>::iterator iter = m_loBullet.begin(), iterDelete;

	while (iter != m_loBullet.end())
	{
		if (
			iter->fPosX < -(iter->glSurfaceBullet.w / 2) ||
			iter->fPosX > 1280 + iter->glSurfaceBullet.w / 2 ||
			iter->fPosY < -(iter->glSurfaceBullet.h / 2) ||
			iter->fPosY > 720 + iter->glSurfaceBullet.h / 2)
		{
			iterDelete = iter;
			++iter;
			m_loBullet.erase(iterDelete);
		}
		else
			++iter;
	}
}

void BulletHandle::Draw()
{
	for (
		std::list<Bullet>::iterator iter = m_loBullet.begin();
		iter != m_loBullet.end();
		++iter)
	{
		Graphics::DrawSurface(iter->glSurfaceBullet, iter->fPosX, iter->fPosY);
	}
}

void BulletHandle::New(const float ac_fPosX, const float ac_fPosY, const float ac_fAngle)
{
	Bullet oTemp;

	oTemp.fPosX = ac_fPosX;
	oTemp.fPosY = ac_fPosY;

	oTemp.fVelX = 1000;
	oTemp.fVelY = 1000;

	oTemp.glSurfaceBullet = m_glSurfaceBullet;
	oTemp.glSurfaceBullet.rotation = ac_fAngle;

	m_loBullet.push_back(oTemp);
}

BulletHandle::BulletHandle()
{
	m_glSurfaceBullet = Graphics::LoadSurface("Images/Bullets/bulletGreen.png");
}
BulletHandle::~BulletHandle()
{

}
