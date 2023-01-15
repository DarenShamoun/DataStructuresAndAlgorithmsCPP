#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bag.h"

SCENARIO( "Test mesa::bag copy constructor" ) {

  WHEN( "a copy is made" ) {
    mesa::bag<int> original {3,1,4,1,5,9};
    mesa::bag<int> copy = original;
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

  WHEN( "a copy is made between 2 cont bags" ) {
    const mesa::bag<int> original {3,1,4,1,5,9};
    const mesa::bag<int> copy = original;
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

