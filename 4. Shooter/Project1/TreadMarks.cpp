#include "TreadMarks.h"


void TreadMarks::Handle()
{
	std::list<Tread>::iterator iter = m_loTreads.begin();
	while(iter != m_loTreads.end())
	{
		iter->glSurfaceTread.color[3] -= 0.01f;

		if (m_loTreads.begin()->glSurfaceTread.color[3] <= 0)
		{
			++iter;
			m_loTreads.pop_front();
		}
		else
			++iter;
	}
}

void TreadMarks::Draw()
{
	for (
		std::list<Tread>::iterator iter = m_loTreads.begin();
		iter != m_loTreads.end();
		++iter)
	{
		Graphics::DrawSurface(iter->glSurfaceTread, iter->fPosX, iter->fPosY);
	}
}

void TreadMarks::New(const float ac_fPosX, const float ac_fPosY, const float ac_fAngle)
{
	Tread oTemp;

	oTemp.fPosX = ac_fPosX;
	oTemp.fPosY = ac_fPosY;

	oTemp.glSurfaceTread.color[3] = 1.0f;

	oTemp.glSurfaceTread = m_glSurfaceTread;
	oTemp.glSurfaceTread.rotation[0] = ac_fAngle;

	m_loTreads.push_back(oTemp);
}

TreadMarks::TreadMarks()
{
	m_glSurfaceTread = Graphics::LoadSurface("Images/Tanks/tracksSingle.png");
}
TreadMarks::~TreadMarks()
{

}
