#include "gamestate.hpp"
#include "gamestate.hpp"

InGameObject* MapState::get_object_at_coord(Point){
	// //TODO: add caching
	// for (auto iter = objects.begin(); iter != objects.end(); ++iter ) {
	// 	(*iter)->tick();
	// }
	return NULL;
}

InGameObject::ObjectType MapState::get_object_type_at_coord(Point) {
	//TODO: add caching

	// for (auto iter = objects.begin(); iter != objects.end(); ++iter ) {
	// 	(*iter)->tick();
	// }
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