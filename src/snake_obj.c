#include "gamestate.h"
#include "display.h"
#include "snake_obj.h"
#include "pellet_obj.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


void render_drawobj_snake(const struct Snake * snake, const SDL_Color color){
	SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0x00, 0x00 );
	SDL_Rect rect;
	for (int i=0; i<(snake->length); i++){
		rect = point_to_rect(&snake->body[i]);
		// SDL_RenderDrawRect(renderer, &rect); 
		SDL_RenderFillRect(renderer, &rect);//TODO: possible optimization using SDL_RenderFillRects	
	}
}

void engine_tickobj_snake(struct Snake * snake){
	snake->ticks_till_move -= 1;
	if (snake->ticks_till_move <= 0) {
		snake->ticks_till_move = snake->ticks_per_move;
		snake->turned_this_move = 0;

		// move snake forwards
		struct Point next = snake->body[0];
		switch(snake->direction){
			case UP:
				next.y = snake->body[0].y - 1;
				if (next.y < 0){ next.y = MAX_VER_BLOCKS-1; }
				break;
			case DOWN:
				next.y = snake->body[0].y + 1;
				if (next.y >= MAX_VER_BLOCKS){ next.y = 0; }
				break;
			case LEFT:
				next.x = snake->body[0].x - 1;
				if (next.x < 0){ next.x = MAX_HOR_BLOCKS-1; }
				break;
			case RIGHT:
				next.x = snake->body[0].x + 1;
				if (next.x >= MAX_HOR_BLOCKS){ next.x = 0; }
				break;
		}

		// TODO: check collision
		if (next.x == engine_gamestate.pellet->pos.x &&
			next.y == engine_gamestate.pellet->pos.y ){
			snake->length += 1;
			for (int i=(snake->length)-1;i>0;i--){
				snake->body[i] = snake->body[i-1];
			}
			snake->body[0] = next;
			pellet_refresh_random(engine_gamestate.pellet);
			return;
		}

		// update snake body on no collision
		for (int i=(snake->length)-1;i>0;i--){
			snake->body[i] = snake->body[i-1];
		}
		snake->body[0] = next;
	}
}

//TODO: instead of turned_this_move, make it next_direction, that can be overwritten.
// so that commands can be slightly "queued"
void snake_turn(struct Snake * snake, enum Direction direction){
	if(snake == NULL) return;
	if(snake->turned_this_move) return;

	switch(direction){
		case UP:
		case DOWN:
			if (snake->direction == LEFT || snake->direction == RIGHT){
				snake->direction = direction;
				snake->turned_this_move = 1;
			}
			break;
		case LEFT:
		case RIGHT:
			if (snake->direction == UP || snake->direction == DOWN){
				snake->direction = direction;
				snake->turned_this_move = 1;
			}
			break;
	}
}

struct Snake * create_default_snake(){
	struct Snake * snake = malloc(sizeof(struct Snake));
	snake->direction = RIGHT;
	snake->ticks_per_move = 8;
	snake->ticks_till_move = 0;

	snake->length = 5;
	snake->body[0] = (struct Point){5,10};
	snake->body[1] = (struct Point){6,10};
	snake->body[2] = (struct Point){7,10};
	snake->body[3] = (struct Point){8,10};
	snake->body[4] = (struct Point){9,10};

	return snake;
}


