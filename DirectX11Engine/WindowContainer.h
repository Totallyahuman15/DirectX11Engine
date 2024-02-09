#pragma once

#include "RenderWindow.h"
#include "Keyboard/KeyboardClass.h"
#include "Mouse/MouseClass.h"
#include <memory>
#include "Graphics\Graphics.h"

class WindowContainer
{
public:
	WindowContainer();
	LRESULT WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	RenderWindow renderWindow;
	KeyboardClass keyboard;
	MouseClass mouse;
	Graphics gfx;
};
