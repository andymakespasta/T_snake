#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <memory>

//TODO: either define screen size from blocks (and dynamically resize screen)
//OR define block size from screen size.
#include "gamestate.hpp"

#define SCREEN_MARGIN 8
//if block size is odd, then it's easier to center things using SDL_gfx
#define BLOCK_SIZE 17

#define SCREEN_WIDTH (MAX_HOR_BLOCKS * BLOCK_SIZE) + (SCREEN_MARGIN * 2)
#define SCREEN_HEIGHT (MAX_VER_BLOCKS * BLOCK_SIZE) + (SCREEN_MARGIN * 2)

class SDL_Renderer;
class Snake;
class Pellet;
class Wall;


class Display {
public:
	void init();
	void close();
	void draw_mapstate(const MapState& map);

	void draw_snake_object(const Snake* snake, const SDL_Color* color);
	void draw_pellet_object(const Pellet* pellet);
	void draw_wall_object(const Wall* wall);

	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif //DISPLAY_HPP