#ifndef PELLET_OBJ_H
#define PELLET_OBJ_H

#include "gamestate.h"

struct Pellet {
	int ticks_till_expire;
	struct Point pos;
};

void render_drawobj_pellet(const struct Pellet * pellet);
void engine_tickobj_pellet(struct Pellet * pellet);

void pellet_refresh_random(struct Pellet * pellet);

struct Pellet * create_default_pellet();
struct Pellet * copy_pellet(struct Pellet * source_pellet);
#endif