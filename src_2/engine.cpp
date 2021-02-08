#include <SDL2/SDL.h>

#include "engine.hpp"

#include "gamestate.hpp"
#include "display.hpp"

//temp includes
#include <memory>
#include "snake_obj.hpp"
#include "pellet_obj.hpp"
std::shared_ptr<Snake> player_snake;
std::shared_ptr<Pellet> test_pellet;

void Engine::init() {
	SDL_Init(0);

	game = new Gamestate();

	//TODO: constructor vs init vs static to prevent multi?
	display = new Display();
	display->init();
	


	//temp actions
	temp_initialize_gamestate();


	enginestate = RUNNING_GAME; // TODO: implement menu selection state etc.
	last_loop_time = SDL_GetTicks();
}

void Engine::stop() {
	enginestate = QUIT;

	display->close();

	// TODO: free gamestate

	SDL_Quit();
}

void Engine::loop() {
	temp_check_inputs();
	// run as many ticks as it takes to catch up to now.
    unsigned int current_time = SDL_GetTicks();
    while (last_loop_time < current_time){
        last_loop_time += MS_PER_TICK;
        tick();
    }
    display->draw_mapstate(game->map);
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
                  	player_snake->queued_turn(UP);
                  break;
                  case SDLK_DOWN:
                    // snake_turn(engine_gamestate.snake, DOWN);
                  	player_snake->queued_turn(DOWN);
                  break;
                  case SDLK_LEFT:
                    // snake_turn(engine_gamestate.snake, LEFT);
                  	player_snake->queued_turn(LEFT);
                  break;
                  case SDLK_RIGHT:
                    // snake_turn(engine_gamestate.snake, RIGHT);
                  	player_snake->queued_turn(RIGHT);
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

	InGameObject::game = game;

	// player_snake = new Snake;
	player_snake = std::make_shared<Snake>();
	game->map.objects.push_back(player_snake);

	// test_pellet = new Pellet({10,10});
	// auto test_pellet = std::make_shared<Pellet>({10,10});
	Point pt = {10,10};
	test_pellet = std::make_shared<Pellet>(pt);
	game->map.objects.push_back(test_pellet);	

}