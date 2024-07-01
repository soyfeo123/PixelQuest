#pragma once
#include <Windows.h>
#include <SDL.h>

class WindowsCore {
public:
	HINSTANCE hInstance;
	HINSTANCE hPreviousInstance;
	LPSTR lpCmdLine;
};

class Application {
public:
	WindowsCore coreInfo;
	SDL_Window* sdlWindow;
	SDL_Renderer* sdlRenderer;
};

Application* application;