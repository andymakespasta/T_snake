
#include "gamestate.h"
#include "engine.h"
#include "snake_obj.h"
#include "pellet_obj.h"

#include <stdio.h>
#include <stdlib.h>

#if __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif 

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void test_setup() {
    //test block
    engine_gamestate.snake = create_default_snake();
    engine_gamestate.pellet = create_default_pellet();
    //end test block   
}

void main_loop()
{

#if __EMSCRIPTEN__
    // fps: -1: negative for request animation frame frequency; infinite: 1:
    emscripten_set_main_loop(engine_tick, -1, 1);
#else
    while (enginestate != QUIT)
    {
        engine_tick();
    }
#endif
}

int main()
{
    test_setup();

    engine_init();

    main_loop();

    engine_close();

    return 0;
}