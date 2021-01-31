#include "stdio.h"
#include "assert.h"

#include "gamestate.h"



class Thing : public InGameObject {
public:
  Point pos;
};

int main(){
  printf("==============================\n");
  printf("Gamestate Test\n");



  Thing test_thing;
  test_thing.pos.x = 1;
  test_thing.pos.y = 2;
  test_thing.type = InGameObject::SNAKE;

  MapState map_state;

  map_state.objects.push_back(&test_thing);

  Thing* got_thing = static_cast<Thing*>(map_state.objects[0]);


  assert(got_thing->pos.x == 1);
  assert(got_thing->pos.y == 2);
  assert(got_thing->type == InGameObject::SNAKE);
  


  printf("Complete\n");
  printf("==============================\n");
}