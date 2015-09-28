#ifndef _MAINLOOP_H_
#define _MAINLOOP_H_

#include "Loop.h"
#include "Player.h"

namespace LoopHandle
{
	class MainLoop : public Loop
	{
	private:
		GLSurface m_glSurfaceBack;
		Player m_oPlayer;

	public:
		void Handle();

		void Draw();

		void OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode);
		void OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode);

		MainLoop();
		~MainLoop();
	};
}
#endif // _MAINLOOP_H_

