#include "pellet_obj.hpp"
#include <stdio.h>
#include "wall_obj.hpp"

Pellet::Pellet(Gamestate* game, Point position, int expire) {
	_game = game;
	pos = position;
	type = PELLET;
	curr_ticks = 0;
	expire_ticks = expire;
}

int Pellet::tick() {
	if (expire_ticks) {
		if (++curr_ticks == expire_ticks) {

			printf("expired\n");

			// creating a wall
			// This should be in the "mine object, and not the pellet object"
			auto wall_thing = std::make_shared<Wall>(pos);	
			_game->map.add_object(wall_thing);

			// move self, instead of deleting self then
			Point pt;
			do {
				pt = { rand() % MAX_HOR_BLOCKS,
				       rand() % MAX_VER_BLOCKS };
			} while (_game->map.get_object_type_at_coord(pt) != InGameObject::EMPTY);
			pos = pt;
			expire_ticks = 500;
			curr_ticks = 0;
			return 1;
		}
	}
	return 0;
}

std::vector<Point> Pellet::get_coords() {
	return std::vector<Point>( {pos} );
}


std::shared_ptr<InGameObject> Pellet::copy(){
	auto copy_pellet = std::make_shared<Pellet>(_game, pos, expire_ticks);
	copy_pellet->curr_ticks = curr_ticks;

	return std::dynamic_pointer_cast<InGameObject>(copy_pellet);
}