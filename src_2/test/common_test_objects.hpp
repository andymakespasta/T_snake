#ifndef TEST_OBJECTS_HPP
#define TEST_OBJECTS_HPP



class Thing : public InGameObject {
public:
  void tick() {
    tick_count ++;
  }

  Point pos;
  int tick_count;
  std::vector<Point> get_coords() { return std::vector<Point>( {pos} ); }
};


class BigThing : public InGameObject {
public:
  void tick() {
    tick_count ++;
  }

  std::vector<Point> pos;
  int tick_count;
  std::vector<Point> get_coords() { return pos; }
};


#endif //TEST_OBJECTS_HPP