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
		float m_fPosX, m_fPosY; // The tread's X and Y

		GLSurface m_glSurfaceTread; // The tread's surface

		// Gets called by a timer every time the timer updates
		// Expects DeltaTime to update itself
		void Update(const int ac_iDeltaTime);
		// Draws the tread on the screen
		void Draw();

		// Gets called by a timer when that timer ends
		void Delete();

		// Default Constructor
		Tread();
		// Default De-Constructor
		~Tread();
	};

private:
	TimerHandle<Tread> *m_oTreadTimer; // The timer for the treads

	GLSurface m_glSurfaceTread; // The default surface for treads so it doesn't need to be loaded in multiple times

public:
	// Creates a new 'Tread' and gives it an X and Y value plus an angle
	void New(const float ac_fPosX, const float ac_fPosY, const float ac_fAngle);

	// Constructor which requires a reference to the TreadTimer
	TreadMarks(TimerHandle<Tread> &ac_oTreadTimer);
	// You cannot use this function
	TreadMarks() = delete; // Make sure a default constructor cannot be called
	// Default De-Constructor
	~TreadMarks();
};

#endif // _TREADMARKS_H_

