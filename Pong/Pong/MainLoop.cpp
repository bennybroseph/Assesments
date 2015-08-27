#include "MainLoop.h"

namespace Handle {
	MainLoop_Class::MainLoop_Class()
	{
		Ball.push_back(Ball_Class());

		Paddle.push_back(Paddle_Class());
		Paddle.push_back(Paddle_Class(1900));
	}

	void MainLoop_Class::ReLoad_Textures()
	{
		
	}

	void MainLoop_Class::Update()
	{
		int i;
		for (i = 0; i < Paddle.size(); i++)
			Paddle[i].Handle();
		for (i = 0; i < Ball.size(); i++)
			Ball[i].Handle(Paddle);

		Score::Handle();
	}

	void MainLoop_Class::Draw()
	{
		int i;
		for (i = 0; i < Paddle.size(); i++)
			Paddle[i].Draw();
		for (i = 0; i < Ball.size(); i++)
			Ball[i].Draw();

		Score::Draw();
	}

	void MainLoop_Class::OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (sym)
		{
		case SDLK_ESCAPE: running = false;
			break;

		case SDLK_SPACE: Score::OnKeyDown(sym, mod, scancode);
			break;

		case SDLK_UP: Paddle[0].OnKeyDown(sym, mod, scancode);
			break;
		case SDLK_DOWN: Paddle[0].OnKeyDown(sym, mod, scancode);
			break;

		case SDLK_w: Paddle[1].OnKeyDown(sym, mod, scancode);
			break;
		case SDLK_s: Paddle[1].OnKeyDown(sym, mod, scancode);
			break;

		case SDLK_F1:
			Graphics::Resize(640, 360, 1);
			break;
		case SDLK_F2:
			Graphics::Resize(960, 540, 1);
			break;
		case SDLK_F3:
			Graphics::Resize(1280, 720, 1);
			break;
		case SDLK_F4:
			Graphics::Resize(1600, 900, 1);
			break;
		case SDLK_F11:
			Graphics::Resize(1920, 1080, 1, true);
			break;

		default: 
			break;
		}
	}
	void MainLoop_Class::OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (sym)
		{
		case SDLK_UP: Paddle[0].OnKeyUp(sym, mod, scancode);
			break;
		case SDLK_DOWN: Paddle[0].OnKeyUp(sym, mod, scancode);
			break;

		case SDLK_w: Paddle[1].OnKeyUp(sym, mod, scancode);
			break;
		case SDLK_s: Paddle[1].OnKeyUp(sym, mod, scancode);
			break;

		default: 
			break;
		}
	}

	void MainLoop_Class::OnMouseMove(int mx, int my, int xvel, int yvel, bool left, bool right, bool middle)
	{
		
	}
	void MainLoop_Class::OnLButtonDown(int mx, int my)
	{

	}
	void MainLoop_Class::OnRButtonDown(int mx, int my)
	{

	}
	void MainLoop_Class::OnResize(int w, int h)
	{
		Graphics::Resize(w, h);
	}

	MainLoop_Class::~MainLoop_Class()
	{

	}
}