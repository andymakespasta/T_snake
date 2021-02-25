#ifndef WALL_OBJ_HPP
#define WALL_OBJ_HPP

#include "gamestate.hpp"

// simple wall that does nothing
// has
class Wall: public InGameObject {
  public:
  	Wall(Point pos, int hardness = 10);
  	void tick();
  	std::vector<Point> get_coords();

	int hardness;
	Point pos;

};

#endif
