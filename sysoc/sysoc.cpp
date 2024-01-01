// sysoc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
using namespace std;

#include "SoftwareRenderer.h"
#pragma comment(lib, "SoftwareRenderer.lib")

typedef int*(__stdcall* f_ocboot)(SoftwareRenderer *renderer);
#pragma comment(lib, "SDL2.lib")
#define sysprint(x) printf("[ %s ] %s", __FILE__ + 40, x)
SDL_Window* window;

int main()
{
    // our job is to create a window and create a software renderer and pass it over to the bootloader and let it handler the rest
    printf("opencon system executable\n");
    sysprint("creating window\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // thank you https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index2.php my dimentia means i need this xd
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    window = SDL_CreateWindow("sysoc", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }

    sysprint("creating renderer\n");
    SoftwareRenderer *renderer = new SoftwareRenderer(window);

    sysprint("loading bootloader\n");
    HINSTANCE hGetProcIDDLL = LoadLibrary(L"boot\\ocboot.bin");
    if (!hGetProcIDDLL) {
        std::cout << "could not load bootloader" << std::endl;
        return EXIT_FAILURE;
    }
    sysprint("locating bootloader sysboot\n");
    f_ocboot sysboot = (f_ocboot)GetProcAddress(hGetProcIDDLL, "bootloadersystemain");
    if (!sysboot)
    {
        std::cout << "unknown boot failure" << std::endl;
        return EXIT_FAILURE;
    }
    sysprint("executing bootloader sysboot\n");
    int* sys = (int *)sysboot(renderer);
    printf("sysboot returned %i", sys);
    
}

