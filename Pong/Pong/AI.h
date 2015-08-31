#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

#include "Paddle.h"
#include "Ball.h"

#include <vector>

namespace AI
{
	int Init();

	void Handle(Paddle_Class&, Ball_Class);

	void Quit();
}

#endif // AI_H_INCLUDED