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
		printf("expired");
	}
}

std::vector<Point> Pellet::get_coords() {
	return std::vector<Point>( {pos} );
}