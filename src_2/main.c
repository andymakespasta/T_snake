#include <stdio.h>
#include <stdlib.h>

#if __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif 

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void main_loop()
{

// #if __EMSCRIPTEN__
//     // fps: -1: negative for request animation frame frequency; infinite: 1:
//     emscripten_set_main_loop(engine_loop, -1, 1);
// #else
//     while (enginestate != QUIT)
//     {
//         engine_loop();
//     }
// #endif
}

int main()
{
  // init
  
  main_loop();

  // close

    return 0;
}