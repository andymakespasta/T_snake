#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "display.hpp"

#include "snake_obj.hpp"


//utility functions
SDL_Rect point_to_rect(const struct Point &point){
	SDL_Rect block = {.x = SCREEN_MARGIN + (point.x)*BLOCK_SIZE,
					  .y = SCREEN_MARGIN + (point.y)*BLOCK_SIZE,
					  .w = BLOCK_SIZE,
					  .h = BLOCK_SIZE};
	return block;
}


// draw functions for various in game objects

void Display::draw_snake_object(const Snake* snake, const SDL_Color color){
	SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
	SDL_Rect rect;

	for (auto it = snake->q_body.begin(); it!=snake->q_body.end(); ++it){
		rect = point_to_rect(*it);
		// printf("%d", (*it).x);
		SDL_RenderFillRect(renderer, &rect);
	}
}
	