#ifndef _TREADMARKS_H_
#define _TREADMARKS_H_

#include "Graphics.h"
#include "TimerHandle.h"

#include <list>

class TreadMarks
{
public:
	class Tread
	{
	public:
		float m_fPosX, m_fPosY;

		GLSurface m_glSurfaceTread;

		void Update(const int ac_iDeltaTime);
		void Draw();

		void Delete();

		Tread();
		~Tread();
	};

private:
	TimerHandle<Tread> *m_oTreadTimer;

	GLSurface m_glSurfaceTread;

public:
	void New(const float ac_fPosX, const float ac_fPosY, const float ac_fAngle);

	TreadMarks(TimerHandle<Tread> &ac_oTreadTimer);
	TreadMarks();
	~TreadMarks();
};

#endif // _TREADMARKS_H_

