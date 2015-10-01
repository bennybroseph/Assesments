#ifndef _MAINLOOP_H_
#define _MAINLOOP_H_

#include "Loop.h"
#include "Player.h"
#include "TileMap.h"
#include "TimerHandle.h"

namespace LoopHandle
{
	class MainLoop : public Loop
	{
	private:
		GLSurface m_glSurfaceBack;
		
		TimerHandle m_oGameTimers;
		Time m_oGameTime;
		Player m_oPlayer;
		TileMap m_oTileMap;

		bool m_bIsPaused;

	public:
		void Handle();
		void Test();

		void Draw();

		void OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode);
		void OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode);

		void OnMouseMove(
			int a_iMouseX, int a_iMouseY, 
			int a_iVelX, int a_iVelY, 
			bool a_bLeft, bool a_bRight, bool a_bMiddle);

		MainLoop();
		~MainLoop();
	};
}
#endif // _MAINLOOP_H_

