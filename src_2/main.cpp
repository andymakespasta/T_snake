#include <stdio.h>
#include <stdlib.h>

#if __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif 

#include "engine.hpp"

Engine* engine;

void engine_loop_callback(){
	engine->loop();
}

#ifndef TEST_BUILD
int main()
{
  // init
  engine = new Engine();
  engine->init();
#if __EMSCRIPTEN__
    // fps: -1: negative for request animation frame frequency; infinite: 1:
    emscripten_set_main_loop(engine_loop_callback, -1, 1);
#else
    while (engine->enginestate != Engine::QUIT)
    {
        engine->loop();
    }
#endif

  // close
  engine->stop();
    return 0;
}
#endif