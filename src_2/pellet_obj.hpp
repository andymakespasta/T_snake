#ifndef PELLET_OBJ_HPP
#define PELLET_OBJ_HPP

#include "gamestate.hpp"

// simple pellet that does nothing and snakes can consume.
class Pellet: public InGameObject {
  public:
  	Pellet(Gamestate* game, Point pos, int expire_ticks = 0);
  	int tick();
  	std::vector<Point> get_coords();

  	std::shared_ptr<InGameObject> copy();

	Point pos;
	// when curr_ticks = expire_ticks, it expires
	// if expire_ticks = 0, it never expires
	// when pellets expire, they just disappear
	int curr_ticks;
	int expire_ticks;
	
	Manager::NotifyFunc notify_destruction;

	// Gamestate* _game;
};

#endif
