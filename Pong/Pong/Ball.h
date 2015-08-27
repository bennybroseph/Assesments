#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "Graphics.h"
#include "Paddle.h"
#include "Time.h"
#include "Score.h"

#include "SDL.h"

#include <vector>

class Ball_Class
{
private:

	SDL_Surface* image = NULL;
	SDL_Surface* effect = NULL;

	float x = 0, y = 0;
	float x_vel = 0, y_vel = 0;

	std::vector<Paddle_Class> Paddle;

	struct Box_Struct
	{
		float t, b, r, l, ox, oy;
	};

public:

	Box_Struct box;

	Ball_Class(int = -1, int = -1);

	void Handle(std::vector<Paddle_Class> Paddle);
	void Move();
	void Collision();
	void SetBox();
	void Reset();

	void Draw();

	~Ball_Class();
};

#endif // BALL_H_INCLUDED
