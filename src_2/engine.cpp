#include "engine.hpp"
#include "gamestate.hpp"
#include <SDL2/SDL.h>

//temp includes

void Engine::init() {
	SDL_Init(0);

	game = new Gamestate();

	// display_init()	

	enginestate = RUNNING_GAME; // TODO: implement menu selection state etc.
	last_loop_time = SDL_GetTicks();
}

void Engine::stop() {
	enginestate = QUIT;

	// display stop

	// free gamestate

	SDL_Quit();
}

void Engine::loop() {
	temp_check_inputs();
	// run as many ticks as it takes to catch up to now.
    unsigned int current_time = SDL_GetTicks();
    while (last_loop_time < current_time){
        last_loop_time += MS_PER_TICK;
        // engine_tick();
    }

    // display_draw_gamestate();
}

void Engine::tick() {
	// tick all managers
	for (auto iter = game->managers.begin(); iter != game->managers.end(); ++iter) {
		(*iter)->tick();
		printf("m");
	}
	// tick all objects in map
	for (auto iter = game->map.objects.begin(); iter != game->map.objects.end(); ++iter ) {
		(*iter)->tick();
		printf("o");
	}
	printf("-tick\n");
}


//TODO: this should be moved to input manager.
void Engine::temp_check_inputs() {
    SDL_Event event;
    // clear out all events in buffer
    while (SDL_PollEvent(&event))
    {
        switch (event.type) {
          case SDL_QUIT:
            enginestate = QUIT;
          break;
          case SDL_KEYDOWN: //TODO: separate into separate function for key inputs, and gamestates
            if(event.key.repeat != 1){ //only accept originals
                switch (event.key.keysym.sym){
                  case SDLK_UP:
                    // snake_turn(engine_gamestate.snake, UP);
                  	printf("up\n");
                  break;
                  case SDLK_DOWN:
                    // snake_turn(engine_gamestate.snake, DOWN);
                  break;
                  case SDLK_LEFT:
                    // snake_turn(engine_gamestate.snake, LEFT);
                  break;
                  case SDLK_RIGHT:
                    // snake_turn(engine_gamestate.snake, RIGHT);
                  break;
                  case SDLK_x:
                  // case SDLK_SPACE: TODO: handle multiple key hold
                    printf("rewind start\n");
                    // timeline_start_rewind();
                  break;
                }
            }
          break;
          case SDL_KEYUP:
            switch (event.key.keysym.sym){
                case SDLK_x:
                    printf("rewind end\n");
                    // timeline_stop_rewind();
                break;
            }
        }
    }
}

void Engine::temp_initialize_gamestate() {
	// game->map.objects.
}