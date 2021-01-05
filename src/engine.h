// This engine owns and updates a gamestate object defined in gamestate.h
// This engine also calls the display code.
// This engine does not really know the insides of the gamestate, and instead relies on the various objects
#ifndef ENGINE_H
#define ENGINE_H


enum Enginestate {
	QUIT = 0,
	PAUSED,
	RUNNING_GAME
};

extern enum Enginestate enginestate;

// Call this first.
void engine_init();
void engine_close();

// Call this in a loop as often as possible.
// The engine will handle everything from there on.
void engine_tick();

// Methods of interacting with gamestate.
// void add_active_object(void* object);
// void remove_active_object(void* object);
#endif