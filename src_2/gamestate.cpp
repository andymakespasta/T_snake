#include "gamestate.hpp"


//TODO: maybe move this
#include "pellet_obj.hpp"
#include "snake_obj.hpp"
#include <stdlib.h>

// adds an object to the vector (and map cache)
void MapState::add_object(std::shared_ptr<InGameObject> object){
	objects.push_back(object);
	//TODO: cache
}

// deletes an object by removing all shared_ptr references
// also, this needs to hold off on deletions until after the main engine loop completes, otherwise you can't remove yourself
void MapState::delete_object(std::shared_ptr<InGameObject> object){
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter) == object ){
			// printf("match\n");

			// TODO: if object has delete callback, call from here
			if (object->type == InGameObject::PELLET){
				// TODO: this code should not be here.
				// handleObjectDestroyed( object );
				for (int i = (rand()%10)/9 +1; i>0; --i ){
					Point pt;
					do {
						pt = { rand() % MAX_HOR_BLOCKS,
						       rand() % MAX_VER_BLOCKS };
					} while (get_object_type_at_coord(pt) != InGameObject::EMPTY);

					objects.push_back(std::make_shared<Pellet>(object->_game, pt, 500));	
				}
			}
			objects.erase(iter);
			//TODO: update map cache
			break;
			
		}
	}
}

std::shared_ptr<Snake> MapState::get_snake_obj(){
	for (auto iter = objects.begin(); iter != objects.end(); ++iter ) {
		if ((*iter)->type == InGameObject::SNAKE){
			printf("found snake\n");
			// std::shared_ptr<Snake> 
			return std::dynamic_pointer_cast<Snake>(*iter);
			// return NULL;
		}
	}
} 

std::shared_ptr<InGameObject> MapState::get_object_at_coord(Point point){
	// //TODO: add caching / better system
	for (auto iter = objects.begin(); iter != objects.end(); ++iter ) {
		auto object_coord_list = (*iter)->get_coords();
		for (auto object_iter = object_coord_list.begin(); object_iter != object_coord_list.end(); ++object_iter) {
			if ((*object_iter) == point ) {
				return (*iter);
			}
		}
	}
	return NULL;
}

InGameObject::ObjectType MapState::get_object_type_at_coord(Point point) {
	//TODO: add caching
	for (auto iter = objects.begin(); iter != objects.end(); ++iter ) {
		auto object_coord_list = (*iter)->get_coords();
		for (auto object_iter = object_coord_list.begin(); object_iter != object_coord_list.end(); ++object_iter) {
			if ((*object_iter) == point ) {
				return (*iter)->type;
			}
		}
	}
	return InGameObject::EMPTY;
}

void Gamestate::take_snapshot() {
	Snapshot snapshot;
	std::shared_ptr<InGameObject> object_copy;

	for (auto iter = map.objects.begin(); iter != map.objects.end(); ++iter){
		// this should probably be replaced with serialize
		object_copy = (*iter)->copy();
		snapshot.objects.push_back(object_copy);
		object_copy.reset();
	}

	snapshot.time_ticks = time_ticks;
	printf("saving snapshot for time %d\n", time_ticks);
	history.push_back(snapshot);
	if (history.size() > HISTORY_FRAMES) {
		history.pop_front();
		printf("poppint snapshot\n");
	}
}

void Gamestate::load_snapshot(int time) {
	printf("loading time %d \n", time);


	// for (auto iter = history.rbegin(); iter != history.rend(); ++iter) {
	// 	printf(" snapshot time %d \n", (*iter).time_ticks);
	// }


	for (auto iter = history.rbegin(); iter != history.rend(); ++iter) {
		// printf("  last snapshot time %d \n", (*iter).time_ticks);
		if ((*iter).time_ticks < time){
			printf("loading %d \n", (*iter).time_ticks);
			load_snapshot( (*iter));
			history.pop_back();
			printf("history size: %d\n", history.size());
			break;
		}
	}
}

void Gamestate::load_snapshot(Snapshot snapshot) {
	std::shared_ptr<InGameObject> object_copy;

	map.objects.clear();

	for (auto iter = snapshot.objects.begin(); iter != snapshot.objects.end(); ++iter){
		// this should probably be replaced with serialize
		if ((*iter)-> type == InGameObject::SNAKE) {printf("s");}
		if ((*iter)-> type == InGameObject::PELLET) {printf("p");}
		if ((*iter)-> type == InGameObject::WALL) {printf("w");}
		object_copy = (*iter)->copy();
		// map.objects.push_back(object_copy);
		map.add_object(object_copy);
		object_copy.reset();
	}
	printf("\n");
}


void Gamestate::start_rewind() {
    if (game_time_state == Gamestate::NORMAL){
      game_time_state = Gamestate::REWINDING;
    }

}
void Gamestate::stop_rewind() {
    if (game_time_state == Gamestate::REWINDING)
      game_time_state = Gamestate::NORMAL;
}



// class MapState {
// public:
//   // list of pointers to static game objects.
//   // list of pointers to moving game objects.
//   // TODO: check if vector of pointers is best type for this

//   // std::vector<InGameObject*> objects;
//   std::vector<std::shared_ptr<InGameObject>> objects;

// public:
//   // MapstateGridCache* // speeds up get_object_at_coord
//   InGameObject* get_object_at_coord();
//   InGameObject::ObjectType get_object_type_at_coord();
// };