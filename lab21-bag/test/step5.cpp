#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bag.h"

SCENARIO( "Test mesa::bag copy assignment" ) {

  WHEN( "a copy is made" ) {
    mesa::bag<int> original {3,1,4,1,5,9};
    mesa::bag<int> copy {1,2,3};
    copy = original;
    THEN ("the copy should have the same attributes as the original") {
      CHECK(copy.empty() == original.empty());
      CHECK(copy.size() == original.size());
      CHECK(copy.capacity() == original.capacity());
    } AND_THEN ( "all elements should be the same as the original" ) {
      for (int i = 0; i < int(original.size()); ++i) {
        REQUIRE_MESSAGE(copy[i] == original[i], "could not access element " << i << " using operator[]");
      }
    }
  }

  WHEN( "a copy is made with an initialization list" ) {
    auto original = mesa::bag<double>{3,1,4,1,5,9};
    auto copy     = mesa::bag<double>{1,2,3};
    copy = original;
    THEN ("the copy should have the same attributes as the original") {
      CHECK(copy.empty() == original.empty());
      CHECK(copy.size() == original.size());
      CHECK(copy.capacity() == original.capacity());
    } AND_THEN ( "all elements should be the same as the original" ) {
      for (int i = 0; i < int(original.size()); ++i) {
        REQUIRE_MESSAGE(copy[i] == original[i], "could not access element " << i << " using operator[]");
      }
    }
  }

}

