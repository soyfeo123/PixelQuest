#include <Windows.h>
#include "Entry.h"
#include <SDL.h>
#include <stdio.h>
#include <string>

void DisplayInitError(const char* text) {
	if (MessageBoxA(NULL, text, "PixelQuest Init Error", MB_ICONERROR | MB_YESNO) == IDYES) {
		MessageBoxA(NULL, SDL_GetError(), "PixelQuest Init Error", MB_ICONERROR | MB_OK);
	}
}

void ShutdownSDL() {
	SDL_DestroyWindow(application->sdlWindow);
	SDL_Quit();
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR     lpCmdLine,_In_ int       nCmdShow) {
	application = new Application();
	application->coreInfo.hInstance = hInstance;
	application->coreInfo.hPreviousInstance = hPrevInstance;
	application->coreInfo.lpCmdLine = lpCmdLine;
	application->sdlWindow = NULL;
	application->sdlRenderer = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		DisplayInitError("Video init failure.");
	}
	else {
		application->sdlWindow = SDL_CreateWindow("PixelQuest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
		if (application->sdlWindow == NULL) {
			DisplayInitError("Window creation error.");
		}
		else {
			application->sdlRenderer = SDL_CreateRenderer(application->sdlWindow, -1, SDL_RENDERER_ACCELERATED);

			if (application->sdlRenderer == NULL) {
				DisplayInitError("SDL Renderer creation error.");
			}
			else {
				SDL_SetRenderDrawColor(application->sdlRenderer, 255, 255, 255, 255);
				
				SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
			}

			
			
		}
	}
	ShutdownSDL();
}