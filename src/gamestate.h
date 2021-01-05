#ifndef GAMESTATE_H
#define GAMESTATE_H

#define MAX_ACTIVE_OBJECTS 10

#define MAX_HOR_BLOCKS 40
#define MAX_VER_BLOCKS 30

// shared types
struct Point {
	int x,y; // coordinates, not screen location 0,0 is top left block, x is rightwards, y is downwards
};

enum Direction {
	UP=0,
	DOWN,
	LEFT,
	RIGHT,
};

enum GameObjectType {
	SNAKE,
	PELLET,
	SNAKE_ECHO
};

struct GameObject {
	enum GameObjectType type;
	void* pointer;
};

struct Gamestate {
	struct Pellet* pellet;

	int current_tick; //TODO: overflow
	// int active_objects
	// struct GameObject active_object[MAX_ACTIVE_OBJECTS];
	struct Snake* snake;
};

extern struct Gamestate engine_gamestate;

#endif