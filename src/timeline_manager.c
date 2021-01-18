#include "gamestate.h"
#include "timeline_manager.h"
#include "stdio.h"
#include "snake_obj.h"
#include "pellet_obj.h"

struct TimelineManager* t_manager;

void timeline_start_rewind() {
	t_manager->state = REWINDING;
	t_manager->rewind_start_tick = t_manager->current_tick;
	// t_manager->current_tick = t_manager->current_tick;
	t_manager->current_snapshot = t_manager->latest_snapshot;
	printf("start rewind");
}
void timeline_stop_rewind() {
	t_manager->state = NORMAL;
	printf("stop rewind");
}

void timeline_take_snapshot(){ //TODO: generalize this
	t_manager->latest_snapshot++;
	t_manager->snapshot[t_manager->latest_snapshot].tick = t_manager->current_tick;
	t_manager->snapshot[t_manager->latest_snapshot].snake = copy_snake(engine_gamestate.snake);
	t_manager->snapshot[t_manager->latest_snapshot].pellet = copy_pellet(engine_gamestate.pellet);
}

void timeline_manager_init(){
	t_manager = malloc(sizeof(struct TimelineManager));
	t_manager->state = NORMAL;
	t_manager->current_tick = 0; //TODO: overflow
	t_manager->current_tick = 0; //TODO: overflow

	t_manager->latest_snapshot = 0;
	t_manager->first_snapshot = 0;
	timeline_take_snapshot();

	engine_gamestate.timeline_manager = t_manager;
}

void engine_tick_timelinemanager(){
	if (t_manager->state == NORMAL){
    	t_manager->current_tick++;
		if (engine_gamestate.changed){
			//take snapshot
			timeline_take_snapshot();
			printf("%d-%d\n", t_manager->latest_snapshot, t_manager->current_tick);
		}
	}
	else if (t_manager->state == REWINDING){
		t_manager->current_tick--;
		if (t_manager->current_tick < t_manager->snapshot[t_manager->current_snapshot].tick){
			t_manager->current_snapshot--;
			free(engine_gamestate.snake);
			engine_gamestate.snake = copy_snake(t_manager->snapshot[t_manager->current_snapshot].snake);
			free(engine_gamestate.pellet);
			engine_gamestate.pellet = copy_pellet(t_manager->snapshot[t_manager->current_snapshot].pellet);
		}

		printf("%d - %d\n", t_manager->current_tick, t_manager->snapshot[t_manager->current_snapshot].tick);
		// printf("%d\n",t_manager->current_snapshot);
	}
}
