#include "App.h"

App::App()
	:
	wnd(800, 600, L"Window!")
{}

int App::Go()
{
	MSG msg;
	BOOL gResult;

	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}

	// check if GetMessage call itself borked
	if (gResult == -1)
	{
		throw CHWND_LAST_EXCEPT();
	}

	// wParam here is the value passed to PostQuitMessage
	return msg.wParam;
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().EndFrame();
}