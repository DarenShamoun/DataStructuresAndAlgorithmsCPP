#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>
#include <doctest.h>
#include "../src/computer_player.h"

//
// For these tests to compile,
// the computer player functions 
// - how_many
// - choose_heap(int)
// - take_some
// - take_one
// - evaluate
// all need to exist.
//

TEST_CASE("make a winning move in a 3 pile game") {
  std::vector<uint32_t> p {2,1,1};
  evaluate(p);
  CHECK_MESSAGE (p.size() == 3, "did not expect the number of piles to change");
  CHECK_MESSAGE (choose_heap(0) == 0, "did not pick the best pile");
  CHECK_MESSAGE (how_many() == 2, "did not take all the stones");
}


TEST_CASE("end game moves") {

  SUBCASE("leave opponent with a losing position") {
    SUBCASE("2 piles 3 stones") {
      evaluate({1,2});
      CHECK (choose_heap(0) == 1);
      CHECK (how_many() == 1);
    }
    SUBCASE("2 piles 3 stones reversed") {
      evaluate({2,1});
      CHECK (choose_heap(0) == 0);
      CHECK (how_many() == 1);
    }
    SUBCASE("2 piles 10 stones") {
      evaluate({3,7});
      CHECK (choose_heap(0) == 1);
      CHECK (how_many() == 4);
    }
    SUBCASE("3 piles take all") {
      evaluate({1,1,3});
      CHECK (choose_heap(0) == 2);
      CHECK (how_many() == 3);
    }
    SUBCASE("3 piles reduce") {
      evaluate({2,1,4});
      CHECK (choose_heap(0) == 2);
      CHECK (how_many() == 1);
    }
  }
  SUBCASE("lose gracefully") {
    take_one({1,1});
    CHECK (choose_heap(0) == 0);
    CHECK (how_many() == 1);
  }


}
TEST_CASE("not end of game moves (early/mid)") {

    SUBCASE("should remove 13 stones from last pile") {
      evaluate({14,12,6,11,4,8,16});
      CHECK (choose_heap(0) == 6);
      CHECK (how_many() == 13);
    }

    SUBCASE("should remove 10 stones from first pile") {
      evaluate({12,6,11,4,8,3});
      CHECK (choose_heap(0) == 0);
      CHECK (how_many() == 10);
    }

    SUBCASE("should remove 8 stones from pile[2]") {
      evaluate({2,6,11,4,3});
      CHECK (choose_heap(0) == 2);
      CHECK (how_many() == 8);
    }

    SUBCASE("should remove 3 stones from pile[1]") {
      evaluate({11,12,1,3});
      CHECK (choose_heap(0) == 1);
      CHECK (how_many() == 3);
    }

    SUBCASE("should remove 1 stones from pile[1]") {
      evaluate({2,5,4,3});
      CHECK (choose_heap(0) == 1);
      CHECK (how_many() == 1);
    }

    SUBCASE("should remove 1 stones from pile[0]") {
      evaluate({9,5,9,5});
      CHECK (choose_heap(0) == 0);
      CHECK (how_many() == 1);
    }

}
