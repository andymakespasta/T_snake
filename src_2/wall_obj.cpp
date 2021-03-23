#include "wall_obj.hpp"
#include <stdio.h>

Wall::Wall(Point position, int hard) {
	type = WALL;
	pos = position;
	hardness = hard;

}

int Wall::tick() {
	return 0;
}

std::vector<Point> Wall::get_coords(){
	return std::vector<Point>( {pos} );
}

std::shared_ptr<InGameObject> Wall::copy(){
	auto wall_thing = std::make_shared<Wall>(pos, hardness);	
	return std::dynamic_pointer_cast<InGameObject>(wall_thing);
}