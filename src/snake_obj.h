#ifndef SNAKE_OBJ_H
#define SNAKE_OBJ_H

#include "gamestate.h"
#include <SDL2/SDL.h>

#define MAX_SNAKE_LENGTH 100

struct Snake {
	enum Direction direction;
	int ticks_per_move; //ticks / block
	int ticks_till_move;
	int turned_this_move;

	int length;
	struct Point body[MAX_SNAKE_LENGTH];
	// TODO: optimization using cyclical buffer
	// TODO: optimization using dynamic memory body.
	// TODO: make length positive
	// body[0] is head
	// body[length - 1] is tail
};

void render_drawobj_snake(const struct Snake * snake, const SDL_Color color);

void engine_tickobj_snake(struct Snake * snake);

void snake_turn(struct Snake * snake, enum Direction direction);

struct Snake * create_default_snake();
#endif