#include "TreadMarks.h"



void TreadMarks::New(const float ac_fPosX, const float ac_fPosY, const float ac_fAngle)
{
	Tread *newTread = new Tread; // Create a new 'Tread' on the heap

	// Set the new tread's values
	newTread->m_fPosX = ac_fPosX; 
	newTread->m_fPosY = ac_fPosY;

	newTread->m_glSurfaceTread.alpha = 1.0f;

	newTread->m_glSurfaceTread = m_glSurfaceTread;
	newTread->m_glSurfaceTread.rotation = ac_fAngle;

	m_oTreadTimer->NewTimer(1500, *newTread, &Tread::Delete, &Tread::Update); // Create a new timer and give it the 'Delete' and 'Update' function for it to call as a function pointer
}

TreadMarks::TreadMarks(TimerHandle<Tread> &ac_oTreadTimer)
{
	m_glSurfaceTread = Graphics::LoadSurface("Images/Tanks/tracksSingle.png");

	m_oTreadTimer = &ac_oTreadTimer;
}
TreadMarks::~TreadMarks()
{

}

void TreadMarks::Tread::Update(const int ac_iDeltaTime)
{
	m_glSurfaceTread.alpha -= 255.0f/(1500.0f/ac_iDeltaTime);
	Draw();
}
void TreadMarks::Tread::Draw()
{
	Graphics::DrawSurface(m_glSurfaceTread, m_fPosX, m_fPosY);
}

void TreadMarks::Tread::Delete()
{	
	delete this;
}

TreadMarks::Tread::Tread()
{

}
TreadMarks::Tread::~Tread()
{
	
}