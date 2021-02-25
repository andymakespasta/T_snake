#include "stdio.h"
#include "assert.h"

#include "gamestate.hpp"

#include "common_test_objects.hpp"

int main(){
  printf("==============================\n");
  printf("Gamestate Test\n");

  std::shared_ptr<Thing> thing1 = std::make_shared<Thing>();
  thing1->tick_count = 0;
  thing1->pos.x = 69;
  thing1->pos.y = 420;
  thing1->type = InGameObject::SNAKE;

  std::shared_ptr<Thing> thing2 = std::make_shared<Thing>();
  thing2->tick_count = 0;
  thing2->pos.x = 5;
  thing2->pos.y = 5;
  thing2->type = InGameObject::EMPTY;

  std::shared_ptr<BigThing> bigthing3 = std::make_shared<Thing>();
  thing2->tick_count = 0;
  thing2->pos.x = 5;
  thing2->pos.y = 5;
  thing2->type = InGameObject::EMPTY;


  Gamestate* game = new Gamestate();

  game->map.add_object(thing1);
  game->map.add_object(thing2);


  delete_object


  Thing* got_thing_1 = static_cast<Thing*>(game->map.objects[0]);
  Thing* got_thing_2 = static_cast<Thing*>(game->map.objects[1]);

  assert(got_thing_1->pos.x == 69);
  assert(got_thing_1->pos.y == 420);
  assert(got_thing_1->type == InGameObject::SNAKE);
  assert(got_thing_2->type == InGameObject::EMPTY);

  printf("Complete\n");
  printf("==============================\n");
}