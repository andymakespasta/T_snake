#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "display.hpp"

// #include "gamestate.hpp"


void Display::init() {
	SDL_InitSubSystem(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "WEBASM",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
}

void Display::close(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
