#include "Robot.h"



namespace Dungeon
{
	void Robot::Handle()
	{
		Move();
		Collision();
	}
	void Robot::Move()
	{

	}
	void Robot::Collision()
	{

	}

	void Robot::GetPos(int &a_iPosX, int &a_iPosY, int &a_iFacing)
	{
		a_iPosX = m_iPosX;
		a_iPosY = m_iPosY;

		a_iFacing = m_iFacing;
	}

	Robot::Robot(const int a_ciPosX, const int a_ciPosY, const int a_ciFacing)
	{
		m_iPosX = a_ciPosX;
		m_iPosY = a_ciPosY;

		m_iFacing = a_ciFacing;

		m_bIsAlive = true;
	}
	Robot::Robot()
	{

	}
	Robot::~Robot()
	{
		// Nothing Yet
	}
}
