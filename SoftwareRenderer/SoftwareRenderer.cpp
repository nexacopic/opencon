// SoftwareRenderer.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "SoftwareRenderer.h"
#pragma comment(lib, "SDL2.lib")


SoftwareRenderer::SoftwareRenderer(SDL_Window* targetwindow) {
	AssignedWindow = targetwindow;
	BackEndRenderer = SDL_CreateRenderer(AssignedWindow, -1, SDL_RENDERER_ACCELERATED);
	// hardware renderer will use ogl
}
void SoftwareRenderer::SetFrameCallback(void (*frame)(double delta)) // call this before starting the rendering loop
{
	FrameCallback = frame;
}
void SoftwareRenderer::DrawPixel(int x, int y, Color *col)
{
	SDL_SetRenderDrawColor(BackEndRenderer, col->r, col->g, col->b, col->a);
	SDL_RenderDrawPoint(BackEndRenderer, x, y); // slow as shit will be swapped out
}

void SoftwareRenderer::DrawRect(int x, int y, int w, int h, Color* col)
{
	for (int xx = 0; xx < w; xx++)
	{
		for (int yy = 0; yy < h; yy++)
		{
			DrawPixel(x + xx, y + yy, col);
		}
	}
}

void SoftwareRenderer::DrawBitmap(int x, int y, int w, int h, int* bitmap) {
	for (int xx = 0; xx < w; xx++)
	{
		for (int yy = 0; yy < h; yy++)
		{
			int curpixel = bitmap[xx + (yy * w)];
			DrawPixel(x + xx, y + yy, new Color((curpixel >> 16) & 0xFF, (curpixel >> 8) & 0xFF, (curpixel) & 0xFF));
		}
	}
}

void SoftwareRenderer::StartRenderLoop()
{
	SDL_Event e; 
	bool quit = false; 
	while (quit == false) 
	{ 
		while (SDL_PollEvent(&e)) 
		{ 
			if (e.type == SDL_QUIT) quit = true; 
		} 
		SDL_SetRenderDrawColor(BackEndRenderer, 0, 0, 0, 255);
		SDL_RenderClear(BackEndRenderer);
		FrameCallback(0);
		SDL_RenderPresent(BackEndRenderer);
	}
}
