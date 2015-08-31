#include "Paddle.h"

Paddle_Class::Paddle_Class(int x, int y)
{
	this->image = Graphics::LoadImage("Images/Paddle_Clean.png");
	this->effect = Graphics::LoadImage("Images/Paddle.png");

	if (x < 960)
		this->x = x + this->image->w / 2;
	else if (x > 960)
		this->x = x - this->image->w / 2;
	else
		this->x = x;

	this->y = y;

	reset = false;
	this->SetBox();
}

void Paddle_Class::Handle()
{
	if ((Time::pause)&&(!this->reset))
		this->Reset();
	else if (!Time::pause)
		this->reset = false;

	this->Move();
	this->SetBox();
}

void Paddle_Class::Move()
{
	this->x += this->x_vel*((float)Time::GetIgnore() / 1000);
	this->y += this->y_vel*((float)Time::GetIgnore() / 1000);

	if ((this->up_flag) && (this->y > 0 + (this->image->h / 2)))
		this->y_vel = -500;
	else if ((this->down_flag) && (this->y < 1080 - (this->image->h / 2)))
		this->y_vel = 500;
	else
		this->y_vel = 0;

	if (this->box.t < 0)
	{
		this->y_vel = 0;
		this->y = 0 + this->image->h / 2;
	}
	if (this->box.b > 1080)
	{
		this->y_vel = 0;
		this->y = 1080 - this->image->h / 2;
	}
}

void Paddle_Class::SetBox()
{
	this->box.t = this->y - (this->image->h / 2);
	this->box.b = this->y + (this->image->h / 2);
	this->box.l = this->x - (this->image->w / 2);
	this->box.r = this->x + (this->image->w / 2);

	this->box.ox = this->x - (this->image->w / 2);
	this->box.oy = this->y - (this->image->h / 2);
}

void Paddle_Class::OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
{
	switch (sym)
	{
	case SDLK_UP: this->up_flag = true;
		break;
	case SDLK_DOWN: this->down_flag = true;
		break;

	case SDLK_w: this->up_flag = true;
		break;
	case SDLK_s: this->down_flag = true;
		break;
	}
}

void Paddle_Class::OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
{
	switch (sym)
	{
	case SDLK_UP: this->up_flag = false;
		break;
	case SDLK_DOWN: this->down_flag = false;
		break;

	case SDLK_w: this->up_flag = false;
		break;
	case SDLK_s: this->down_flag = false;
		break;
	}
}

void Paddle_Class::Draw()
{
	Graphics::DrawImage(this->image, this->box.ox, this->box.oy);
	Graphics::DrawImage(this->effect, this->x -(this->effect->w /2), this->y - (this->effect->h / 2));
}

void Paddle_Class::Reset()
{
	this->y = 540;

	this->x_vel = 0;
	this->y_vel = 0;

	this->reset = true;
}

Paddle_Class::~Paddle_Class()
{

}
