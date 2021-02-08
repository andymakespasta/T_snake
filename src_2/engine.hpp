#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <cstdint>

#include "gamestate.hpp"


#define MS_PER_TICK 15 // ~66 ticks per second


class Gamestate;
class Display;

class Engine {
public:
	enum Enginestate {
		QUIT = 0,
		PAUSED,
		RUNNING_GAME
	} enginestate;

	void init();
	void stop();

	// Call this in a loop as often as possible.
	// The engine will handle everything from there on.
	void loop();

private:
	// everything in the game changes on ticks.
	// ticks always happen at fixed rate in real time
	// multiple ticks may happen before a screen refresh if running slowly.
	void tick();


	// this contains game specific code. Should be moved to input manager.
	void temp_check_inputs();

	// this contains game specific code. Should be moved to menu/level manager.
	void temp_initialize_gamestate();

private:
	Gamestate* game;
	Display* display;
	uint32_t last_loop_time;

};

#endif //ENGINE_HPP