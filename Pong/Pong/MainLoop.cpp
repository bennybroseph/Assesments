#include "MainLoop.h"

namespace Handle {
	MainLoop_Class::MainLoop_Class()
	{

	}

	void MainLoop_Class::ReLoad_Textures()
	{
		
	}

	void MainLoop_Class::Update()
	{
		
	}

	void MainLoop_Class::Draw()
	{
		
	}

	void MainLoop_Class::OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (sym)
		{
		case SDLK_ESCAPE: running = false;
			break;

		case SDLK_F1:
			Graphics::Resize(160, 144, 1);
			break;
		case SDLK_F2:
			Graphics::Resize(160, 144, 2);
			break;
		case SDLK_F3:
			Graphics::Resize(160, 144, 3);
			break;
		case SDLK_F4:
			Graphics::Resize(160, 144, 4);
			break;
		case SDLK_F11:
			Graphics::Resize(160, 144, 1, true);
			break;

		default: 
			break;
		}
	}
	void MainLoop_Class::OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
	{
		switch (sym)
		{
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