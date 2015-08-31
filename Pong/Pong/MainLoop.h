#ifndef MAINLOOP_H_INCLUDED
#define MAINLOOP_H_INCLUDED

#include "Graphics.h"
#include "Handle.h"
#include "Loop.h"
#include "AI.h"
#include "Ball.h"
#include "Paddle.h"

#include <vector>

namespace Handle {
	class MainLoop_Class : public Loop
	{
	private:

		std::vector<Ball_Class> Ball;
		std::vector<Paddle_Class> Paddle;

	public:

		MainLoop_Class();
		~MainLoop_Class();

		void OnKeyDown(SDL_Keycode, Uint16, SDL_Scancode);
		void OnKeyUp(SDL_Keycode, Uint16, SDL_Scancode);

		void OnMouseMove(int, int, int, int, bool, bool, bool);
		void OnLButtonDown(int, int);
		void OnRButtonDown(int, int);
		void OnResize(int, int);

		void Update();
		void Draw();
		void ReLoad_Textures();
	};
}

#endif // MAINLOOP_H_INCLUDED