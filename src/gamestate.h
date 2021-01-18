// Gamestate.h is the header that contains the definitions for the Gamestate object
// The actual code is in objects (things on the screen) and managers (game systems)

#ifndef GAMESTATE_H
#define GAMESTATE_H

// #include "timeline_manager.h"

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

// enum GameObjectType {
// 	SNAKE,
// 	PELLET,
// 	SNAKE_ECHO,
// };

// struct GameObject {
// 	enum GameObjectType type;
// 	void* pointer;
// };

// the status of the objects at a specific point in time
struct Snapshot {
	int tick;
	struct Snake* snake;
	struct Pellet* pellet;
};

//global object used to find other objects.
struct Gamestate {
	// hardcode objects for now.
	// int active_objects
	// struct GameObject active_object[MAX_ACTIVE_OBJECTS];
	struct Snake* snake;
	struct Pellet* pellet;

	// special objects tied to player input
	struct Snake* player_snake;

	// managers
	struct TimelineManager* timeline_manager;
	int changed;
};



extern struct Gamestate engine_gamestate;

#endif