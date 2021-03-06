#include "gamestate.h"
#include "display.h"
#include "pellet_obj.h"

#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define DEFAULT_TICKS_TILL_EXPIRE 200


void render_drawobj_pellet(const struct Pellet * pellet){

	if (pellet->ticks_till_expire > 100){
		SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0xff, 0x00 );	
	}
	else {
		short val = pellet->ticks_till_expire * 0xff / 100;
		SDL_SetRenderDrawColor( renderer, 0xff, val, val, 0x00 );		
	}
	SDL_Rect rect = point_to_rect(&pellet->pos);
	rect.x += 3;
	rect.y += 3;
	rect.w -= 6;
	rect.h -= 6;
	SDL_RenderFillRect(renderer, &rect);//TODO: possible optimization using SDL_RenderFillRects	

}
void engine_tickobj_pellet(struct Pellet * pellet){
	pellet->ticks_till_expire -= 1;
	if (pellet->ticks_till_expire <= 0){
		pellet_refresh_random(pellet);
		printf("expired\n");
	}
}

void pellet_refresh_random(struct Pellet * pellet){
	pellet->pos.x = rand() % MAX_HOR_BLOCKS ;
	pellet->pos.y = rand() % MAX_VER_BLOCKS ;
	pellet->ticks_till_expire = DEFAULT_TICKS_TILL_EXPIRE;
}

struct Pellet * create_default_pellet(){
	struct Pellet * pellet = malloc(sizeof(struct Pellet));
	pellet_refresh_random(pellet);
	return pellet;
}

struct Pellet * copy_pellet(struct Pellet * source_pellet){
	struct Pellet * pellet = malloc(sizeof(struct Pellet));
	pellet->pos.x = source_pellet->pos.x;
	pellet->pos.y = source_pellet->pos.y;
	pellet->ticks_till_expire = source_pellet->ticks_till_expire;
	return pellet;
}



//TODO: reset rand if collision