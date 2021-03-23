// Defines commonly used types, and the Gamestate object which is passed around to many objects.
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <vector>
#include <list>
#include <array>
#include <memory>
#include <functional>
#include <deque>
// #include <compare>

#define GAMESTATE_MANAGERS 0

//TODO: make this dynamic and defined by level
// TODO: see display.hpp
#define MAX_HOR_BLOCKS 40
#define MAX_VER_BLOCKS 30

// TODO: this is temporary before we have serialization.
#define HISTORY_FRAMES 300

class Gamestate;
class Snake;

// common types
struct Point {
  int x,y; // coordinates, not screen location 0,0 is top left block, x+ is rightwards, y+ is downwards
  bool operator==(const Point& rh){return (this->x == rh.x && this->y == rh.y); }
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

  // update object by 1 tick.
  virtual int tick() {};
  // exposed for easier object interaction
  virtual std::vector<Point> get_coords() {return {};};
  // used for history
  virtual std::shared_ptr<InGameObject> copy() {return NULL;};


  enum ObjectType {
    EMPTY,
    SNAKE,
    PELLET,
    WALL,
    SNAKE_ECHO,
  } type;
  //maybe make this weak_ptr
  Gamestate* _game; // pointer to top level gamestate
};

class Manager {
public:
  typedef std::function<void (InGameObject*)> NotifyFunc;
public:
  virtual void tick();
};



// // a view of the world based on the map
// class MapCache {

// };

// all the objects currently in the world
// provides easy to use API to get information on the map
class MapState {
public:
  // MapState();
  // list of pointers to static game objects.
  // list of pointers to moving game objects.
  // TODO: check if vector of pointers is best type for this
  // std::vector<InGameObject*> objects;
  std::list<std::shared_ptr<InGameObject>> objects;

public:
  // MapstateGridCache* // speeds up get_object_at_coord
  
  // adds an object to the vector (and map cache)
  void add_object(std::shared_ptr<InGameObject>);
  // deletes an object by removing all shared_ptr references 
  void delete_object(std::shared_ptr<InGameObject>);

  std::shared_ptr<Snake> get_snake_obj();
  std::shared_ptr<InGameObject> get_object_at_coord(Point);
  InGameObject::ObjectType get_object_type_at_coord(Point);
};

class Snapshot {
public:
  std::list<std::shared_ptr<InGameObject>> objects;
  int time_ticks;
};


class Gamestate {
  // TimelineManager
  // PelletManager
  // History
  
public:

  enum state {
    NORMAL,       // time marches forwards
    REWINDING,    // timeline is undone, No control, backwards movement.
    TIMEJUMPING,  // we're traveling back in time. No movement, doesn't affect timeline
  } game_time_state;
  

void take_snapshot();
void load_snapshot(int time) ;
void load_snapshot(Snapshot snapshot) ;
void start_rewind();
void stop_rewind();

//TODO: this belongs in some manager

  std::deque<Snapshot> history;
  int time_ticks;
  MapState map;
  std::array<Manager* ,GAMESTATE_MANAGERS> managers;
};

#endif //GAMESTATE_HPP