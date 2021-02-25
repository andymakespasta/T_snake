#include "pellet_obj.hpp"
#include <stdio.h>

Pellet::Pellet(Point position, int expire_ticks) {
	pos = position;
	type = PELLET;
	ticks_till_expire = expire_ticks;
}

void Pellet::tick() {
	if (ticks_till_expire > 0) {
		--ticks_till_expire;
	}
	else if (ticks_till_expire == 0) {
		// printf("expired");

		// creating a wall
		// This should be in the "mine object, and not the pellet object"
		auto pWall = std::make_shared<InGameObject>();
		pWall->type = InGameObject::WALL;
		_game->map.add_object(pWall);

		auto pPellet = _game->map.get_object_at_coord(pos);
		_game->map.delete_object(pPellet);
	}
}

std::vector<Point> Pellet::get_coords() {
	return std::vector<Point>( {pos} );
}

