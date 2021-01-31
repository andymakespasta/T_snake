#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

// common types
struct Point {
  int x,y; // coordinates, not screen location 0,0 is top left block, x is rightwards, y is downwards
};

// Base Class for all objects
class InGameObject {
 public:
  enum ObjectType {
    EMPTY,
    SNAKE,
    PELLET,
    SNAKE_ECHO,
  } type;

  // update object by 1 tick.
  void Tick();
};


// // a view of the world based on the map
// class MapCache {

// }

// all the objects currently in the world
// provides easy to use API to get information on the map
class MapState {
public:
  // list of pointers to static game objects.
  // list of pointers to moving game objects.
  // TODO: check if vector of pointers is best type for this
  std::vector<InGameObject*> objects;


public:
  InGameObject* get_object_at_coord();
  InGameObject::ObjectType get_object_type_at_coord();
};


class Gamestate {

};


#endif //GAMESTATE_H