#ifndef _TREADMARKS_H_
#define _TREADMARKS_H_

#include "Graphics.h"

#include <list>

class TreadMarks
{
private:

	struct Tread
	{
		float fPosX, fPosY;

		GLSurface glSurfaceTread;
	};	

	std::list<Tread> m_loTreads;
	GLSurface m_glSurfaceTread;

public:
	void Handle();

	void Draw();

	void New(const float ac_fPosX, const float ac_fPosY, const float ac_fAngle);

	TreadMarks();
	~TreadMarks();
};

#endif // _TREADMARKS_H_

