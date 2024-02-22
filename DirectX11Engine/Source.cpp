#include "Engine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	HRESULT hr;
	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		ErrorLogger::Log(hr, "Failed to call CoInitialize.");
		return -1;
	}

	Engine engine;
	if (!engine.Initialize(hInstance, "DirectX 11 Engine [BETA]", "directx11engine", 800, 600))
	{
		ErrorLogger::Log("Engine failed to initialize.");
		return -1;
	}
	while (engine.ProcessMessages() == true)
	{
		engine.Update();
		engine.RenderFrame();
	}
	return 0;
}
