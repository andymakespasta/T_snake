#ifndef TEST_OBJECTS_HPP
#define TEST_OBJECTS_HPP



class Thing : public InGameObject {
public:
  void tick() {
    tick_count ++;
  }

  Point pos;
  int tick_count;
};


#endif //TEST_OBJECTS_HPP