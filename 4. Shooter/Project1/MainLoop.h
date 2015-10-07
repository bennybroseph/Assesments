#ifndef _MAINLOOP_H_
#define _MAINLOOP_H_

#include "Loop.h"
#include "Player.h"
#include "Enemy.h"
#include "TileMap.h"

namespace LoopHandle
{
	class MainLoop : public Loop
	{
	private:
		GLSurface m_glSurfaceBack; // Background Surface struct
		
		TimerHandle<TreadMarks::Tread> *m_oTreadTimer; // Timer object for treads on every tank object
		TimerHandle<Enemy> *m_oAITimer; // Timer for some enemy AI states
		Time m_oGameTime; // The overall game timer

		Player *m_oPlayer; // The player character tank
		std::vector<Enemy*> m_voEnemy; // A vector of the Enemy tanks

		TileMap m_oTileMap; // The tile map object

		bool m_bIsPaused; // Whether or not the GameTimer is currently paused

	public:
		// Calls 'Update' and 'Handle' functions for all of it's objects
		void Handle();

		// Calls 'Draw' functions for all of it's objects
		void Draw();

		// Inherits from the 'EventHandle' class
		void OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode);
		// Inherits from the 'EventHandle' class
		void OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode);

		// Inherits from the 'EventHandle' class
		void OnMouseMove(
			int a_iMouseX, int a_iMouseY, 
			int a_iVelX, int a_iVelY, 
			bool a_bLeft, bool a_bRight, bool a_bMiddle);

		// Default Constructor
		MainLoop();
		// Default De-Constructor
		~MainLoop();
	};
}
#endif // _MAINLOOP_H_

