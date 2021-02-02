#include "snake_obj.hpp"
#include "stdio.h"

Snake::Snake(Point head, Direction dir, int len, int mtpm) {
	milli_ticks_per_move = mtpm;
	milli_ticks_till_move = milli_ticks_per_move;

	last_move = dir;
	direction = dir;
	queued_direction = NONE;

	length = len;

	q_body.push_front(head);
}

void Snake::tick() {
	milli_ticks_till_move -= 1000;
	if (milli_ticks_till_move <= 0){
		milli_ticks_till_move += milli_ticks_per_move;
		move();
	}
}

void Snake::move() {
	struct Point head = q_body.front();
	struct Point next;

	switch(direction){
		case UP:
			next.y = head.y - 1;
			break;
		case DOWN:
			next.y = head.y + 1;
			break;
		case LEFT:
			next.x = head.x - 1;
			break;
		case RIGHT:
			next.x = head.x + 1;
			break;
		default:
			break;
	}

	// check boundaries and collisions
	// if (next.y >= MAX_VER_BLOCKS){ next.y = 0; }
	// if (next.x >= MAX_HOR_BLOCKS){ next.x = 0; }
	// if (next.y < 0){ next.y = MAX_VER_BLOCKS-1; }
	// if (next.x < 0){ next.x = MAX_HOR_BLOCKS-1; }

	// update snake body 1 space
	q_body.push_front(next);
	while (q_body.size() > length) {
		q_body.pop_back();	
	}

	//TODO: vector version

	last_move = direction;
	if (queued_direction != NONE) {
		direction = queued_direction;
		queued_direction = NONE;
	}

	// printf(".");	
}

void Snake::queued_turn(enum Direction new_direction) {
	if (direction == last_move){ //no queued
		if ((direction == UP || direction == DOWN) &&
			(new_direction == LEFT || new_direction == RIGHT)) {
			direction = new_direction;
		}
		if ((direction == LEFT || direction == RIGHT) &&
			(new_direction == UP || new_direction == DOWN)) {
			direction = new_direction;
		}
		else {
			direction = new_direction;	
		}
	}
	else {
		if (queued_direction != NONE) return; // already queued
		else {
			if ((direction == UP || direction == DOWN) &&
				(new_direction == LEFT || new_direction == RIGHT)) {
				queued_direction = new_direction;
			}
			if ((direction == LEFT || direction == RIGHT) &&
				(new_direction == UP || new_direction == DOWN)) {
				queued_direction = new_direction;
			}
		}
	}
}