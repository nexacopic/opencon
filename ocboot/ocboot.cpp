

#include "pch.h"
#include "framework.h"
#include "ocboot.h"
#include "system.h"
#pragma comment(lib, "SoftwareRenderer.lib")

#include "opencon_logo_bitmap.h"


void frame(double delta);
SoftwareRenderer* CurrentRenderer;
int bootloadersystemain(SoftwareRenderer* renderer)
{
	sysprint("hello from the bootloader\n");
	CurrentRenderer = renderer;
	renderer->SetFrameCallback(frame);
	renderer->StartRenderLoop();
	return 0;
}

void frame(double delta)
{
	CurrentRenderer->DrawBitmap(200 - opencon_logo_width/2, 200 - opencon_logo_height/2, opencon_logo_width, opencon_logo_height, opencon_logo_bitmap);
}