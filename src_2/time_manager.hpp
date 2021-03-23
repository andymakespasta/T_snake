class TimeManager {
  public:  	
	enum state {
		NORMAL,       // time marches forwards
		REWINDING,    // timeline is undone, No control, backwards movement.
		TIMEJUMPING,  // we're traveling back in time. No movement, doesn't affect timeline
	} game_time_state;

	void tick();

	void start_rewind();
		// load snapshop
		// ticks - 
		// repeat
	void stop_rewind();

	void start_timejump();
		// jump_entry_tick = now
		// 	load snapshot
		// 	add warping snake
		// 	ticks - 
		// 	repeat
	void exit_backjump();
		// now = jump_entry_tick + 1
		// remove traveler_object (snake)
		// spawn traveler_echo_object (paradox undo point: jump_entry_tick)

  private:
	int jump_entry_tick;
	int current_tick;

	void normal_tick();
	void rewind_tick();
	void time_jumping_tick

	void create_echo(traveler_object); // create echo for time_jumper object
	void take_snapshot();
	void load_snapshot(Snapshot snapshot);
	void load_snapshot(int time);


}