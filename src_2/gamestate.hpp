#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <vector>
#include <array>
#include <memory>
#include <functional>

#define GAMESTATE_MANAGERS 0

//TODO: make this dynamic and defined by level
// TODO: see display.hpp
#define MAX_HOR_BLOCKS 40
#define MAX_VER_BLOCKS 30


// common types
struct Point {
  int x,y; // coordinates, not screen location 0,0 is top left block, x is rightwards, y is downwards
};
enum Direction {
  NONE = 0,
  UP,
  DOWN,
  LEFT,
  RIGHT,
};

// Base Class for all objects
class InGameObject {
 public:
  // InGameObject();
  enum ObjectType {
    EMPTY,
    SNAKE,
    PELLET,
    SNAKE_ECHO,
  } type;

  // update object by 1 tick.
  virtual void tick() {};
  virtual std::vector<Point> get_coords() {return {}; };
};

class Manager {
public:
  typedef std::function<void (InGameObject*)> NotifyFunc;
public:
  virtual void tick();
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

  // std::vector<InGameObject*> objects;
  std::vector<std::shared_ptr<InGameObject>> objects;

public:
  // MapstateGridCache* // speeds up get_object_at_coord
  InGameObject* get_object_at_coord(Point);
  InGameObject::ObjectType get_object_type_at_coord(Point);
};



class Gamestate {
  // TimelineManager
  // PelletManager
  // History
public:
  MapState map;
  std::array<Manager* ,GAMESTATE_MANAGERS> managers;
};


#endif //GAMESTATE_HPP