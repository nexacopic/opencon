#pragma once
#ifdef SOFTWARERENDERER_EXPORTS
#define SOFTWARERENDERER_API __declspec(dllexport)
#else
#define SOFTWARERENDERER_API __declspec(dllimport)
#endif

#include <SDL/SDL.h>

// This class is exported from the dll
class SOFTWARERENDERER_API SoftwareRenderer {
public:
	class SOFTWARERENDERER_API Color {
	public:
		int r;
		int g;
		int b;
		int a;
		Color(int rr, int gg, int bb, int aa = 255) {r = rr; g = gg; b = bb; a = aa;}
	};
	SoftwareRenderer(SDL_Window *targetwindow);
	void SetFrameCallback(void (*frame)(double delta)); // call this before starting the rendering loop
	void StartRenderLoop(); // starts the render loop using the given callback
	void DrawPixel(int x, int y, Color* col);
	void DrawRect(int x, int y, int w, int h, Color* col);
	void DrawBitmap(int x, int y, int w, int h, int* bitmap);
private:
	SDL_Window* AssignedWindow;
	SDL_Renderer* BackEndRenderer;
	void (*FrameCallback)(double delta) = [](double delta) {};
};

