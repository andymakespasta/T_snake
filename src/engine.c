#include "engine.h"
#include "gamestate.h"
#include "display.h"


// list of objects
#include "snake_obj.h"
#include "pellet_obj.h"

enum Enginestate enginestate;
struct Gamestate engine_gamestate;
unsigned int last_loop_time;

#define MS_PER_TICK 15
// this means 66 ticks per second


void check_inputs() {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
        {
            enginestate = QUIT;
            break;
        }
        case SDL_KEYDOWN: //TODO: separate into separate function for key inputs, and gamestates
            switch (event.key.keysym.sym){
                case SDLK_UP:
                	snake_turn(engine_gamestate.snake, UP);
                  break;
                case SDLK_DOWN:
                	snake_turn(engine_gamestate.snake, DOWN);
                  break;
                case SDLK_LEFT:
                	snake_turn(engine_gamestate.snake, LEFT);
                  break;
            	case SDLK_RIGHT:
            		snake_turn(engine_gamestate.snake, RIGHT);
                  break;
			}
			break;
        }

    }

}

void engine_init() {
    SDL_Init(0);
    display_init();
    enginestate = RUNNING_GAME; // TODO: implement menu selection state etc.
    last_loop_time = SDL_GetTicks();
}

void engine_close() {	
    display_close();
    SDL_Quit();
}

void engine_tick() {
	check_inputs(); //sets gamestate / actor state

	engine_tickobj_snake(engine_gamestate.snake);
	engine_tickobj_pellet(engine_gamestate.pellet);	
}

void engine_loop() {

	unsigned int current_time = SDL_GetTicks();

	while (last_loop_time < current_time){
		last_loop_time += MS_PER_TICK;
		engine_tick();	
	}
	display_draw_gamestate();

    // unsigned int ticks = SDL_GetTicks();
    // printf("%u\n", ticks);
	// check_inputs(); //sets gamestate / actor state
	// update_snake
	// update_actors(); // actors are things that change with time (snakes, timers)
	// draw_scene();
}