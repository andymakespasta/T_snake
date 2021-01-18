#ifndef SNAKE_ECHO_OBJ_H
#define SNAKE_ECHO_OBJ_H

#include "gamestate.h"
#include <SDL2/SDL.h>


#define MAX_SNAKE_ECHO_PATH 200

//if your snake eats a pellet: use two snake echos pack to back
struct SnakeEcho {
	int current_tail;
	int current_head;
	int path length;
	struct Point path[MAX_SNAKE_ECHO_PATH];
	// timeline
};

void render_drawobj_snake_echo(const struct Snake * snake, const SDL_Color color);
void engine_tickobj_snake_echo(struct Snake * snake);

struct Snake * create_default_snake();

#endif