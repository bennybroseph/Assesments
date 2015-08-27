#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED

#include "Graphics.h"
#include "Time.h"

#include "SDL.h"

class Paddle_Class
{
private:

	SDL_Surface* image = NULL;
	SDL_Surface* effect = NULL;

	bool up_flag = false, down_flag = false;
	bool reset;

	struct Box_Struct
	{
		float t, b, r, l, ox, oy;
	};

public:

	Box_Struct box;

	float x_vel = 0, y_vel = 0;
	float x = 0, y = 0;

	Paddle_Class(int = 20, int = 540);

	void Handle();
	void Move();
	void SetBox();

	void OnKeyDown(SDL_Keycode, Uint16, SDL_Scancode);
	void OnKeyUp(SDL_Keycode, Uint16, SDL_Scancode);

	void Draw();
	void Reset();

	~Paddle_Class();
};

#endif // PADDLE_H_INCLUDED

