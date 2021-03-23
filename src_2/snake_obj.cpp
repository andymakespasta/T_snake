#include "gamestate.hpp"
#include "snake_obj.hpp"
#include "pellet_obj.hpp"
#include "stdio.h"

#include <cassert>

Snake::Snake(Gamestate* game, Point head, Direction dir, int len, int mtpm) {
	_game = game;
	type = SNAKE;
	milli_ticks_per_move = mtpm;
	milli_ticks_till_move = milli_ticks_per_move;

	last_move = dir;
	direction = dir;
	queued_direction = NONE;

	length = len;
	q_body.push_front(head);
}

int Snake::tick() {
	milli_ticks_till_move -= 1000;
	if (milli_ticks_till_move <= 0){
		milli_ticks_till_move += milli_ticks_per_move;
		move();
		return 1;
	}
	return 0;
}

void Snake::move() {
	struct Point next = q_body.front();;

	switch(direction){
		case UP:
			next.y = next.y - 1;
			break;
		case DOWN:
			next.y = next.y + 1;
			break;
		case LEFT:
			next.x = next.x - 1;
			break;
		case RIGHT:
			next.x = next.x + 1;
			break;
		default:
			break;
	}

	// check boundaries and collisions
	if (_game->map.get_object_type_at_coord(next) == InGameObject::SNAKE ){
		assert(0);
	}
	if (_game->map.get_object_type_at_coord(next) == InGameObject::WALL ){
		assert(0);
	}

	if (_game->map.get_object_type_at_coord(next) == InGameObject::PELLET ){
		++length;
		auto pPellet = _game->map.get_object_at_coord(next);
		_game->map.delete_object(pPellet);
	}

	//TODO: change this into special "portal objects" at the edge
	if (next.y >= MAX_VER_BLOCKS){ next.y = 0; }
	if (next.x >= MAX_HOR_BLOCKS){ next.x = 0; }
	if (next.y < 0){ next.y = MAX_VER_BLOCKS-1; }
	if (next.x < 0){ next.x = MAX_HOR_BLOCKS-1; }

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
		// else {
		// 	direction = new_direction;	
		// }
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

std::vector<Point> Snake::get_coords(){
	std::vector<Point> vec;
	for (auto it = q_body.begin(); it!=q_body.end(); ++it){
		vec.push_back(*it);
	}
	return vec;
}



void Snake::hit_pellet() {
	//get details on pellet
	//update self/score based on pellet
	//delete pellet

}

std::shared_ptr<InGameObject> Snake::copy(){
	auto copy_snake = std::make_shared<Snake>( _game );
	copy_snake->last_move = last_move;
	copy_snake->direction = direction;
	copy_snake->queued_direction = queued_direction;
	copy_snake->milli_ticks_per_move = milli_ticks_per_move;
	copy_snake->milli_ticks_till_move = milli_ticks_till_move;
	copy_snake->length = length;
	copy_snake->q_body.clear();
	for (auto it = q_body.begin(); it!=q_body.end(); ++it){
		copy_snake->q_body.push_front(*it);
	}

	return std::dynamic_pointer_cast<InGameObject>(copy_snake);
}
