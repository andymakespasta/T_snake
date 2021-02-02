#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "gamestate.hpp"

//TODO: either define screen size from blocks (and dynamically resize screen)
//OR define block size from screen size.

#define SCREEN_MARGIN 8
#define BLOCK_SIZE 16
#define SCREEN_WIDTH (MAX_HOR_BLOCKS * BLOCK_SIZE) + (SCREEN_MARGIN * 2)
#define SCREEN_HEIGHT (MAX_VER_BLOCKS * BLOCK_SIZE) + (SCREEN_MARGIN * 2)

class Snake;
class SDL_Renderer;

class Display {
public:
	void init();
	void close();
	void draw_mapstate(const MapState* map);


	void draw_snake_object(const Snake* snake, const SDL_Color color);

SDL_Renderer *renderer;
};

#endif //DISPLAY_HPP