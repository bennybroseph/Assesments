#include "Enemy.h"



void Enemy::Update()
{
	m_fPlayerAngle = 180 - (atan2(float(m_fPlayerX - m_fPosX), float(m_fPlayerY - m_fPosY)) * (180.0f / PI));
	m_bAggro = sqrt(pow(m_fPosX - m_fPlayerX, 2) + pow(m_fPosY - m_fPlayerY, 2)) <= 400;

	if (m_iDeltaTime > 0 && m_bAggro)
		m_glSurfaceTurret.rotation = m_fPlayerAngle;

	AI();
}

void Enemy::AI()
{
	switch (m_iCurrState)
	{
	case State::INIT: ChangeState(State::IDLE); break;
	case State::IDLE: m_oAITimer.NewTimer(1000, *this, &Enemy::EndIdle); break;
	case State::PATROL:
	{
		if (m_bAggro)
			ChangeState(State::AGGRO);
		else
			Patrol();
		break;
	}
	case State::AGGRO:
		if (!m_bAggro)
			ChangeState(State::PATROL);
		else if (m_iHealth <= 1)
			ChangeState(State::RETREAT);
		else
			Aggressive();
		break;
	case State::RETREAT:
	{
		if (!m_bAggro)
			ChangeState(State::IDLE);
		break;
	}
	}
}

void Enemy::Patrol()
{
	if (!m_bForwardFlag && !m_bLeftFlag && !m_bRightFlag)
	{
		m_bForwardFlag = true;
		m_oAITimer.NewTimer(2500, *this, &Enemy::Rotate);
	}
	else if (m_bLeftFlag || m_bRightFlag)
	{
		if (m_bLeftFlag && m_glSurfaceBase.rotation > 175 && m_glSurfaceBase.rotation < 185)
		{
			Stop();
			m_glSurfaceBase.rotation = 180;
		}
		if (m_bRightFlag && (m_glSurfaceBase.rotation > 355 || m_glSurfaceBase.rotation < 5))
		{
			Stop();
			m_glSurfaceBase.rotation = 0;
		}
	}
}
void Enemy::Aggressive()
{
	
}

void Enemy::ChangeState(const enum State ac_iNewState)
{
	Stop();

	switch (m_iCurrState)
	{
	case State::PATROL: 
	{
		Stop();
		switch (ac_iNewState)
		{
		case State::AGGRO:
		{
			m_iCurrState = ac_iNewState;
			m_bShoot = true;
			break;
		}

		default: m_iCurrState = ac_iNewState; break;
		}
		break;
	}
	case State::AGGRO:
	{
		switch (ac_iNewState)
		{
		case State::PATROL:
		{
			m_iCurrState = ac_iNewState;
			Rotate();
			break;
		}

		default: m_iCurrState = ac_iNewState; break;
		}
		break;
	}
	default: m_iCurrState = ac_iNewState; break;
	}
	
}
void Enemy::EndIdle()
{
	if (m_iHealth > 1)
		ChangeState(State::PATROL);
	else
		ChangeState(State::IDLE);
}

void Enemy::Rotate()
{
	if (m_iCurrState == State::PATROL)
	{
		Stop();
		if (m_glSurfaceBase.rotation > 90 && m_glSurfaceBase.rotation < 270)
			m_bRightFlag = true;
		else
			m_bLeftFlag = true;
	}
}
void Enemy::Stop()
{
	m_bForwardFlag = false;
	m_bReverseFlag = false;

	m_bLeftFlag = false;
	m_bRightFlag = false;

	m_bShoot = false;
}

Enemy::Enemy(
	TimerHandle<TreadMarks::Tread> &a_oTreadTimer, TimerHandle<Enemy> &a_oAITimer,
	const int &ac_iDeltaTime,
	const float &ac_fPlayerX, const float &ac_fPlayerY) :
	Tank(a_oTreadTimer, ac_iDeltaTime),
	m_fPlayerX(ac_fPlayerX), m_fPlayerY(ac_fPlayerY), m_oAITimer(a_oAITimer)
{
	m_glSurfaceBase = Graphics::LoadSurface("Images/Tanks/tankBlack.png");
	m_glSurfaceTurret = Graphics::LoadSurface("Images/Tanks/barrelBlack.png");

	m_glSurfaceTurret.centerY = 45;

	m_fPosX = 800;
	m_fPosY = 500;

	m_fVelX = 100;
	m_fVelY = 100;

	m_fVelR = 100;

	m_iHealth = 3;

	m_fPlayerAngle = 0;

	m_iCurrState = State::INIT;

	m_oBulletHandle = new BulletHandle(ac_iDeltaTime, "Images/Bullets/bulletBeige.png");
}
Enemy::~Enemy()
{

}
