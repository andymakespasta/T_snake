#include "stdio.h"
#include "assert.h"
#include <chrono>

#include "gamestate.hpp"
#include "snake_obj.hpp"

// #include "common_test_objects.hpp"

int main(){
  printf("==============================\n");
  printf("Snake Object Test\n");

  Snake snake_1;
  Snake snake_2({8,8}, DOWN, 7, 4000);



  printf("testing snake efficiency");
  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i = 10000; i>=0; --i){
    snake_1.tick();
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  long int microseconds = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  printf("no external objects, 10K ticks took %li \tmicroseconds\n", microseconds);


  printf("Complete\n");
  printf("==============================\n");
}