// #include <stdio.h>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>

// #if __EMSCRIPTEN__
// #include <emscripten.h>
// #endif

// // This enables us to have a single point of reference
// // for the current iteration and renderer, rather than
// // have to refer to them separately.
// typedef struct Context {
// SDL_Renderer *renderer;
// int iteration;
// } Context;

// /*
// * Looping function that draws a blue square on a red
// * background and moves it across the <canvas>.
// */
// void mainloop(void *arg) {
// Context *ctx = (Context *)arg;
// SDL_Renderer *renderer = ctx->renderer;
// int iteration = ctx->iteration;

// // This sets the background color to red:
// SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
// SDL_RenderClear(renderer);

// // This creates the moving blue square, the rect.x
// // and rect.y values update with each iteration to move
// // 1px at a time, so the square will move down and
// // to the right infinitely:
// SDL_Rect rect;
// rect.x = iteration;
// rect.y = iteration;
// rect.w = 50;
// rect.h = 50;
// SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
// SDL_RenderFillRect(renderer, &rect);

// SDL_RenderPresent(renderer);

// // This resets the counter to 0 as soon as the iteration
// // hits the maximum canvas dimension (otherwise you'd
// // never see the blue square after it travelled across
// // the canvas once).
// if (iteration == 255) {
// ctx->iteration = 0;
// } else {
// ctx->iteration++;
// }
// }

// int main() {
// SDL_Init(SDL_INIT_VIDEO);
// SDL_Window *window;
// SDL_Renderer *renderer;

// // The first two 255 values represent the size of the <canvas>
// // element in pixels.
// SDL_CreateWindowAndRenderer(255, 255, 0, &window, &renderer);

// Context ctx;
// ctx.renderer = renderer;
// ctx.iteration = 0;

// // Call the function repeatedly:
// int infinite_loop = 1;

// // Call the function as fast as the browser wants to render
// // (typically 60fps):
// int fps = -1;

// // This is a function from emscripten.h, it sets a C function
// // as the main event loop for the calling thread:
// emscripten_set_main_loop_arg(mainloop, &ctx, fps, infinite_loop);

// SDL_DestroyRenderer(renderer);
// SDL_DestroyWindow(window);
// SDL_Quit();

// return EXIT_SUCCESS;
// }

#include "display.h"

#include <stdio.h>
#include <stdlib.h>

#if __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif 

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

int posX=0;
int posY=0;
int sizeW=40;
int sizeH=40;

static int quit = 0;


void render()
{
    SDL_Rect r_scr;
    r_scr.x = posX;
    r_scr.y = posY;
    r_scr.w = sizeW;
    r_scr.h = sizeH;
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0x00, 0x00 );
    SDL_RenderDrawRect(renderer, &r_scr);

 //    SDL_Rect text_dest = {.x = posX, .y = posY, .w = 20, .h = 20};
	
	// text_message_texture[0] = SDL_CreateTextureFromSurface(renderer, surface_text);
	// SDL_QueryTexture(text_message_texture[0], NULL, NULL, &text_dest.w, &text_dest.h);
 //    // SDL_QueryTexture(text_message_texture[0], NULL, NULL, &text_dest.w, &text_dest.h);
 //    // SDL_RenderDrawRect(renderer, &text_dest);
 //    SDL_RenderCopy(renderer, text_message_texture[0], NULL, &text_dest);
 //    // SDL_FreeSurface(surface);

    SDL_RenderPresent(renderer);
    TTF_Font *font;

}

void main_tick() {

    SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
            {
                quit = 1;
                break;
            }
            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                {
                    if (posY>=20)
                    {
                        posY-=20;
                    }
                    break;
                }
                case SDLK_DOWN:
                {
                    if (posY+sizeH<SCREEN_HEIGHT)
                    {
                        posY += 20;
                    }
                    break;
                }
                case SDLK_LEFT:
                {
                    if (posX>=20)
                    {
                        posX-=20;
                    }
                    break;
                }
                case SDLK_RIGHT:
                {
                    if (posX+sizeW<SCREEN_WIDTH)
                    {
                        posX+=20;
                    }
                    break;
                }
                }
                break;
            }
            }

        }


    render();
    SDL_UpdateWindowSurface(window);

}

void main_loop()
{

#if __EMSCRIPTEN__
    emscripten_set_main_loop(main_tick, -1, 1);
#else
    while (0 == quit)
    {
        main_tick();
    }
#endif
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "WEBASM",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    prerender_text();

    main_loop();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}