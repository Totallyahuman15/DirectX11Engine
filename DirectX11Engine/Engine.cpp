#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int width, int height)
{
	if (!this->renderWindow.Initialize(this, hInstance, windowTitle, windowClass, width, height))
	{
		return false;
	}
	else if (!gfx.Initialize(this->renderWindow.GetHWND(), width, height))
	{
		return false;
	}

	return true;
}

bool Engine::ProcessMessages()
{
	return this->renderWindow.ProcessMessages();
}

void Engine::Update()
{
	while (!keyboard.CharBufferIsEmpty())
	{
		unsigned char ch = keyboard.ReadChar();
	}
	while (!keyboard.KeyBufferIsEmpty())
	{
		KeyboardEvent kbe = keyboard.ReadKey();
		unsigned char keycode = kbe.GetKeyCode();
	}
	while (!mouse.EventBufferIsEmpty())
	{
		MouseEvent me = mouse.ReadEvent();
	}
}

void Engine::RenderFrame()
{
	gfx.RenderFrame();
}
