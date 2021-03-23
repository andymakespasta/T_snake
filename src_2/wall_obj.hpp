#ifndef WALL_OBJ_HPP
#define WALL_OBJ_HPP

#include "gamestate.hpp"

// simple wall that does nothing
// each wall object can be a section of wall, and will be drawn as such.
// each wall section also shares hardness + debuffs
class Wall: public InGameObject {
  public:
  	Wall(Point pos, int hardness = 3);
  	int tick();
  	std::vector<Point> get_coords();
  	std::shared_ptr<InGameObject> copy();

	int hardness;
	Point pos;
};

#endif
