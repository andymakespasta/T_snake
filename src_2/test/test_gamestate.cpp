#include "stdio.h"
#include "assert.h"

#include "gamestate.hpp"

#include "common_test_objects.hpp"

int main(){
  printf("==============================\n");
  printf("Gamestate Test\n");

  Thing test_thing;
  test_thing.tick_count = 0;
  test_thing.pos.x = 69;
  test_thing.pos.y = 420;
  test_thing.type = InGameObject::SNAKE;

  Thing test_thing_2;
  test_thing_2.tick_count = 100;
  test_thing_2.type = InGameObject::EMPTY;

  Gamestate* game = new Gamestate();
  game->map.objects.push_back(&test_thing);
  game->map.objects.push_back(&test_thing_2);

  Thing* got_thing_1 = static_cast<Thing*>(game->map.objects[0]);
  Thing* got_thing_2 = static_cast<Thing*>(game->map.objects[1]);

  assert(got_thing_1->pos.x == 69);
  assert(got_thing_1->pos.y == 420);
  assert(got_thing_1->type == InGameObject::SNAKE);
  assert(got_thing_2->type == InGameObject::EMPTY);

  printf("Complete\n");
  printf("==============================\n");
}