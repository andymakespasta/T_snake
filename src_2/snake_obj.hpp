#ifndef SNAKE_OBJ_HPP
#define SNAKE_OBJ_HPP

#include <queue> //TODO: test different types for speed

#include "gamestate.hpp"

class Snake: public InGameObject {
public:
	Snake(Gamestate* game,
		  Point head={5,10}, 
		  Direction direction = RIGHT, 
		  int length = 5, 
		  int mtpm = 7000);

	void tick();
	void move();
	void queued_turn(enum Direction direction);
	//void draw()??
	//temp solution 
	std::vector<Point> get_coords();

	void hit_pellet();

	enum Direction last_move;
	enum Direction direction; //where next block is to be placed
	enum Direction queued_direction; //makes for a smoother ride??
	int milli_ticks_per_move;
	int milli_ticks_till_move;

	int length;
	// normally there are (length) points in the body (including head)
	// however, there can bq_bodye fewer, in which case the snake will grow until it has length segments

	// being a queue, the body.back is head (newest item), while body.front is tail (next item to die)	
	// std::queue<Point> q_body;

	// the front of the deque is the head, the back is the tail
	std::deque<Point> q_body;
	
	Gamestate* _game;
	//TODO: compare speed with vectors.
	// std::vector<Point> v_body;
};

#endif