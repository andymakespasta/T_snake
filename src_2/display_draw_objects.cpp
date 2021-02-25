#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "display.hpp"

#include "gamestate.hpp"
#include "snake_obj.hpp"
#include "pellet_obj.hpp"


//utility functions and objects
const SDL_Color t_white_c = {255,255,255};

SDL_Rect point_to_rect(const struct Point &point){
	SDL_Rect block = {.x = SCREEN_MARGIN + (point.x)*BLOCK_SIZE,
					  .y = SCREEN_MARGIN + (point.y)*BLOCK_SIZE,
					  .w = BLOCK_SIZE,
					  .h = BLOCK_SIZE};
	return block;
}


void Display::draw_mapstate(const MapState& map){
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear(renderer);

	for (auto iter = map.objects.begin(); iter != map.objects.end(); ++iter ) {
		//TODO: comapre efficiency of using vtables to manual switch
		// (*iter)->draw();
		switch((*iter)->type){
			case InGameObject::SNAKE:
				draw_snake_object(static_cast<Snake*>(iter->get()), &t_white_c);
				printf("s");
				break;
			case InGameObject::PELLET:
				draw_pellet_object(static_cast<Pellet*>(iter->get()));
				printf("p");
				break;
			default:
				printf("unknown object type- %d\n", (*iter)->type);
				break;
		}
	}
	printf("-draw\n");

    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
}



// draw functions for various in game objects
void Display::draw_snake_object(const Snake* snake, const SDL_Color* color){
	SDL_SetRenderDrawColor( renderer, color->r, color->g, color->b, color->a );
	SDL_Rect rect;
	for (auto it = snake->q_body.begin(); it!=snake->q_body.end(); ++it){
		// printf("%d-%d|",(*it).x , (*it).y);
		rect = point_to_rect(*it);
		SDL_RenderFillRect(renderer, &rect);
	}
}

void Display::draw_pellet_object(const Pellet* pellet){
	// if (pellet->ticks_till_expire > 0){
	// 	//TODO: add text counter;
	// }
	if (pellet->ticks_till_expire > 100 || pellet->ticks_till_expire < 0){
		SDL_SetRenderDrawColor( renderer, 0xaf, 0xff, 0xaf, 0x00 );	
	}
	else {
		short val = pellet->ticks_till_expire * 0xff / 100;
		SDL_SetRenderDrawColor( renderer, 0xff, 
					pellet->ticks_till_expire * 0xff / 100,
					pellet->ticks_till_expire * 0xaf / 100, 0x00 );		
	}
	SDL_Rect rect = point_to_rect(pellet->pos);
	//TODO: make this pixel diamond.
	rect.x += 3;
	rect.y += 3;
	rect.w -= 6;
	rect.h -= 6;
	SDL_RenderFillRect(renderer, &rect);//TODO: possible optimization using SDL_RenderFillRects	
}

// void Display::draw_wall_object(const Wall* snake){
// 	SDL_SetRenderDrawColor( renderer, color->r, color->g, color->b, color->a );
// 	SDL_Rect rect;
// 	for (auto it = snake->q_body.begin(); it!=snake->q_body.end(); ++it){
// 		// printf("%d-%d|",(*it).x , (*it).y);
// 		rect = point_to_rect(*it);
// 		SDL_RenderFillRect(renderer, &rect);
// 	}
// }