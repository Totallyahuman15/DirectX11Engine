#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int width, int height)
{
	timer.Start();

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
	float dt = timer.GetMsElapsed();
	timer.Restart();

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
		if (mouse.IsRightDown())
		{
			if (me.GetType() == MouseEvent::EventType::RAW_MOVE)
			{
				this->gfx.camera.AdjustRotation((float)me.GetPosY() * 0.001f, (float)me.GetPosX() * 0.001f, 0);
			}
		}
	}

	float cameraSpeed = 0.005f;

	if (mouse.IsRightDown())
	{
		if (keyboard.KeyIsPressed('W'))
		{
			this->gfx.camera.AdjustPosition(this->gfx.camera.GetForwardVector() * cameraSpeed * dt);
		}
		if (keyboard.KeyIsPressed('S'))
		{
			this->gfx.camera.AdjustPosition(this->gfx.camera.GetBackwardVector() * cameraSpeed * dt);
		}
		if (keyboard.KeyIsPressed('A'))
		{
			this->gfx.camera.AdjustPosition(this->gfx.camera.GetLeftVector() * cameraSpeed * dt);
		}
		if (keyboard.KeyIsPressed('D'))
		{
			this->gfx.camera.AdjustPosition(this->gfx.camera.GetRightVector() * cameraSpeed * dt);
		}
		if (keyboard.KeyIsPressed(VK_SPACE))
		{
			this->gfx.camera.AdjustPosition(0.0f, cameraSpeed * dt, 0.0f);
		}
		if (keyboard.KeyIsPressed('Z'))
		{
			this->gfx.camera.AdjustPosition(0.0f, -cameraSpeed * dt, 0.0f);
		}
	}
}

void Engine::RenderFrame()
{
	gfx.RenderFrame();
}
