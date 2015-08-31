#include "AI.h"

namespace AI
{
	int Init()
	{
		return 0;
	}

	void Handle(Paddle_Class& Paddle, Ball_Class Ball)
	{
		if (Ball.box.l <= 1500)
		{
			if (Ball.box.t <= Paddle.y)
				Paddle.y_vel = -500;
			if (Ball.box.b >= Paddle.y)
				Paddle.y_vel = 500;			
		}

		
	}

	void Quit()
	{

	}
}