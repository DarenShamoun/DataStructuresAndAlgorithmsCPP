#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bag.h"

SCENARIO( "Test mesa::bag size and capacity when capacity is set" ) {

  constexpr int test_capacity = 10;
  WHEN( "constructing mesa::bag<int>(10)" ) {
    mesa::bag<int> actual(test_capacity);
    THEN ("empty should return false and capacity and size = 10") {
      CHECK(actual.empty() == false);
    }
    THEN ("empty should return false and capacity and size = 10") {
      CHECK(actual.size() == test_capacity);
      CHECK(actual.capacity() == test_capacity);
    }
    AND_THEN ( "all elements should be default initialized" ) {
      for (int i = 0; i < test_capacity; ++i) {
        REQUIRE_MESSAGE(actual[i] == 0, 
            "could not access element " << i << " using operator[]");
      }
    }
  }

}

