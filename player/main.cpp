#include <SDL/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window;
    SDL_Surface* winSurface = NULL;

    window = SDL_CreateWindow(
        "opencon",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        std::cout << "Could not create window: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    winSurface = SDL_GetWindowSurface(window);

    if (!winSurface) {
        std::cout << "Error getting surface: " << SDL_GetError() << '\n';
        system("pause");
        return 1;
    }

    SDL_UpdateWindowSurface(window);
    SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;

}