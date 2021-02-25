#include "gamestate.hpp"


//TODO: maybe move this
#include "pellet_obj.hpp"
#include <stdlib.h>

// adds an object to the vector (and map cache)
void MapState::add_object(std::shared_ptr<InGameObject> object){
	objects.push_back(object);
	//TODO: cache
}

// deletes an object by removing all shared_ptr references 
void MapState::delete_object(std::shared_ptr<InGameObject> object){
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter) == object ){
			printf("match");

			// TODO: if object has delete callback, call from here
			if (object->type == InGameObject::PELLET){
				// TODO: this code should not be here.
				// handleObjectDestroyed( object );
				for (int i = (rand()%10)/9 +1; i>0; --i ){
					Point pt = { rand() % MAX_HOR_BLOCKS,
						  		 rand() % MAX_VER_BLOCKS };
					objects.push_back(std::make_shared<Pellet>(pt, 500));	
				}
			}


			objects.erase (iter);
			//TODO: update map cache
			break;
			
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