#include "gamestate.hpp"
#include "gamestate.hpp"

Gamestate* InGameObject::game = NULL;

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