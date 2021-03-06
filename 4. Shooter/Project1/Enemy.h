////////////////////////////////////////////////////////////
// File: Enemy.h
// Author: Ben Odom
// Date Created: 10/01/2015
// Brief: This file contains the code for instances of an
//		  enemy tank, which inherits all functions and 
//		  variables from 'Tank.h'. It handles all AI
//		  responsible for instances of an enemy tank
////////////////////////////////////////////////////////////

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Tank.h"

class Enemy : public Tank
{
private:
	enum State
	{
		INIT,
		IDLE,
		PATROL,
		AGGRO,
		RETREAT,

		COUNT
	};

	float m_fPlayerAngle;
	const float &m_fPlayerX, &m_fPlayerY;

	TimerHandle<Enemy> &m_oAITimer;

	int m_iCurrState;

	bool m_bAggro;

public:
	void Update();

	void AI();
	
	void Patrol();
	void Aggressive();

	void ChangeState(const enum State ac_iNewState);
	void EndIdle();

	void Rotate();
	void Stop();

	Enemy(TimerHandle<TreadMarks::Tread> &a_oTreadTimer, TimerHandle<Enemy> &a_oAITimer,
		const int &ac_iDeltaTime,
		const float &ac_fPlayerX, const float &ac_fPlayerY);
	Enemy() = delete;
	~Enemy();
};

#endif // _ENEMY_H_