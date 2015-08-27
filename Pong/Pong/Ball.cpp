#include "Ball.h"

Ball_Class::Ball_Class(int x, int y)
{
	this->image = Graphics::LoadImage("Images/Ball_Clean.png");
	this->effect = Graphics::LoadImage("Images/Ball.png");

	if (x != -1)
		this->x = x;
	else
		this->x = 960;

	if (y != -1)
		this->y = y;
	else
		this->y = rand() % 800 + 200;

	x_vel = 1200 * (((rand() % 2) ? 1 : -1));
	y_vel = 600 * (((rand() % 2) ? 1 : -1));

	this->SetBox();
}

void Ball_Class::Handle(std::vector<Paddle_Class> Paddle)
{
	this->Paddle = Paddle;

	this->Collision();
	this->Move();
	this->SetBox();
}

void Ball_Class::Collision()
{
	//Collision with the screen
	if ((this->box.l <= 0) || (this->box.r >= 1920))
	{
		/*this->x_vel *= -1;

		if (this->box.l <= 0)
			this->x = 0 + (this->image->w / 2);

		if (this->box.r >= 1920)
			this->x = 1920 - (this->image->w / 2);*/

		if (this->box.l <= 0)
			Score::e_score++;
		if (this->box.r >= 1920)
			Score::p_score++;

		this->Reset();
		Time::pause = 750;
	}
	if ((this->box.t <= 0) || (this->box.b >= 1080))
	{
		this->y_vel *= -1;

		if (this->box.t <= 0)
			this->y = 0 + (this->image->h / 2);

		if (this->box.b >= 1080)
			this->y = 1080 - (this->image->h / 2);
	}

	//Collision with the Paddles
	int i;
	for (i = 0; i<Paddle.size(); i++)
	{
		if (((this->box.l > this->Paddle[i].box.l) && (this->box.l <= this->Paddle[i].box.r)) &&
			((this->box.t <= this->Paddle[i].box.b) && (this->box.b >= this->Paddle[i].box.t)))
		{
			while (((this->box.l < this->Paddle[i].box.r)&&(this->box.b >= this->Paddle[i].box.t))&&(this->box.t <= this->Paddle[i].box.b))
			{
				if (this->x_vel <= this->y_vel)
				{
					this->x += abs(this->y_vel / this->x_vel)*((x_vel < 0) ? 1 : -1);
					this->y += (this->y_vel < 0) ? 1 : -1;
				}					
				else
				{
					this->x += (this->x_vel < 0) ? 1 : -1;
					this->y += abs(this->x_vel / this->y_vel)*((this->y_vel < 0) ? 1 : -1);
				}
				this->SetBox();
			}
			if ((this->box.b <= this->Paddle[i].box.t) || (this->box.t >= this->Paddle[i].box.b))
				this->y_vel *= -1;

			this->x_vel *= -1;

			if (this->Paddle[i].y_vel != 0)
			{
				this->y_vel = ((this->y < this->Paddle[i].y) ? -abs(this->y_vel) : abs(this->y_vel));
				this->y_vel = ((abs(this->Paddle[i].y - this->y) / (this->Paddle[i].y - this->Paddle[i].box.t))*
					(abs(this->Paddle[i].y_vel * 5)))*((this->y_vel < 0) ? -1 : 1);
			}
		}

		if (((this->box.r > this->Paddle[i].box.l) && (this->box.r <= this->Paddle[i].box.r)) &&
			((this->box.t <= this->Paddle[i].box.b) && (this->box.b >= this->Paddle[i].box.t)))
		{
			while (((this->box.r > this->Paddle[i].box.l) && (this->box.b >= this->Paddle[i].box.t)) && (this->box.t <= this->Paddle[i].box.b))
			{
				if (this->x_vel <= this->y_vel)
				{
					this->x += abs(this->y_vel / this->x_vel)*((x_vel < 0) ? 1 : -1);
					this->y += (this->y_vel < 0) ? 1 : -1;
				}
				else
				{
					this->x += (this->x_vel < 0) ? 1 : -1;
					this->y += abs(this->x_vel / this->y_vel)*((this->y_vel < 0) ? 1 : -1);
				}
				this->SetBox();
			}
			if ((this->box.b <= this->Paddle[i].box.t) || (this->box.t >= this->Paddle[i].box.b))
				this->y_vel *= -1;

			this->x_vel *= -1;

			if (this->Paddle[i].y_vel != 0)
			{
				this->y_vel = ((this->y < this->Paddle[i].y) ? -abs(this->y_vel) : abs(this->y_vel));
				this->y_vel = ((abs(this->Paddle[i].y - this->y) / (this->Paddle[i].y - this->Paddle[i].box.t))*
					(abs(this->Paddle[i].y_vel * 5)))*((this->y_vel < 0) ? -1 : 1);
			}
		}
	}
}

void Ball_Class::Move()
{
	this->x += this->x_vel*((float)Time::Get()/1000);
	this->y += this->y_vel*((float)Time::Get()/1000);
}

void Ball_Class::SetBox()
{
	this->box.t = this->y - (this->image->h / 2);
	this->box.b = this->y + (this->image->h / 2);
	this->box.l = this->x - (this->image->w / 2);
	this->box.r = this->x + (this->image->w / 2);

	this->box.ox = this->x - (this->image->w / 2);
	this->box.oy = this->y - (this->image->h / 2);
}

void Ball_Class::Reset()
{
	this->x = 960;
	this->y = rand() % 800 + 200;

	x_vel = 1000 * (((rand() % 2) ? 1 : -1));
	y_vel = 600 * (((rand() % 2) ? 1 : -1));

	this->SetBox();
}

void Ball_Class::Draw()
{
	Graphics::DrawImage(this->image, this->x - (this->image->w / 2), this->y - (this->image->h / 2));
	Graphics::DrawImage(this->effect, this->x - (this->effect->w / 2), this->y - (this->effect->h / 2));
}

Ball_Class::~Ball_Class()
{
}
