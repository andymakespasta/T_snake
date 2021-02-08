#ifndef PELLET_OBJ_HPP
#define PELLET_OBJ_HPP

#include "gamestate.hpp"

// simple pellet that does nothing and snakes can consume.
class Pellet: public InGameObject {
  public:
  	Pellet(Point pos, int expire_ticks = -1);
  	void tick();

	Point pos;
	// negative values will never expire.
	// when pellets expire, they just disappear
	int ticks_till_expire;
	
	Manager::NotifyFunc notify_destruction;

};

#endif
