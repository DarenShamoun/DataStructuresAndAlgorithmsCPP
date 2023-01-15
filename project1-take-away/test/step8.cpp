#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>
#include <doctest.h>
#include "../src/computer_player.h"

//
// For these tests to compile,
// the computer player functions 
// - how_many
// - choose_heap(int)
// - take_one
// all need to exist.
//

TEST_CASE("Take one from the first pile") {
  std::vector<uint32_t> p {8,5,3,2,1,1};
  take_one(p);
  CHECK_MESSAGE (p.size() == 6, "did not expect the number of piles to change");
  CHECK_MESSAGE (choose_heap(0) == 0, "did not pick the largest pile");
  CHECK_MESSAGE (how_many() == 1, "did not take one");
}

TEST_CASE("Take one from the last pile") {
  std::vector<uint32_t> p {5,3,2,1,9};
  take_one(p);
  CHECK_MESSAGE (p.size() == 5, "did not expect the number of piles to change");
  CHECK_MESSAGE (choose_heap(0) == 4, "did not pick the largest pile");
  CHECK_MESSAGE (how_many() == 1, "did not take one");
}

TEST_CASE("Take one from the middle pile") {
  std::vector<uint32_t> p {5,3,6,1,4};
  take_one(p);
  CHECK_MESSAGE (p.size() == 5, "did not expect the number of piles to change");
  CHECK_MESSAGE (choose_heap(0) == 2, "did not pick the largest pile");
  CHECK_MESSAGE (how_many() == 1, "did not take one");
}


