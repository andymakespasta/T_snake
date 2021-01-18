#ifndef TIMELINE_MANAGER_H
#define TIMELINE_MANAGER_H

#include "gamestate.h"

#define TIMETRAVEL_SNAPSHOTS 500

enum TimeTravelState {
	NORMAL,
	REWINDING, //for all objects, time is travelling backwards. Player head position stuck
	SUPERPOSITION,
};
// access via engine_gamestate.timeline_manager.state
struct TimelineManager {
	enum TimeTravelState state;
	int latest_tick; // latest tick in the timeline
	int current_tick; // currently displayed tick

	int rewind_start_tick;
	
	int latest_snapshot;  //snapshot[next_snapshot-1] should be most recent snapshot to current_tick
	int current_snapshot; //snapshot closest to currently displayed;
	int first_snapshot; //TODO: change when snapshots can have echoes
	struct Snapshot snapshot[TIMETRAVEL_SNAPSHOTS]; //TODO: change to main_timeline
	//TODO: unstable_timeline
};

void timeline_start_rewind();
void timeline_stop_rewind();


void timeline_manager_init();
void engine_tick_timelinemanager();

// int engine_tickobj_snake();
// int timeline_rewinding

#endif