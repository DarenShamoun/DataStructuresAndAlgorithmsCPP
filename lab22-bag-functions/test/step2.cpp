#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <utility>

#include <doctest.h>
#include "../src/bag.h"

SCENARIO( "Test mesa::bag reserve" ) {

  GIVEN( "a valid bag of 6 elements" ) {
    mesa::bag<int> actual {3,1,4,1,5,9};
    mesa::bag<int> expected {3,1,4,1,5,9};
    WHEN( "10 spaces are reserved" ) {
      actual.reserve(10);
      THEN ("the capacity should increase by 4") {
        CHECK(actual.capacity() == 10);
      } AND_THEN ( "the size should be unchanged" ) {
        CHECK(actual.size() == expected.size());
      } AND_THEN ( "all elements should be unchanged" ) {
        for (int i = 0; i < int(actual.size()); ++i) {
          REQUIRE_MESSAGE(actual.at(i) == expected.at(i), 
              "could not access element " << i);
        }
      }
    }
  }

  GIVEN( "an empty bag" ) {
    mesa::bag<int> actual;
    mesa::bag<int> expected;
    WHEN( "13 spaces are reserved" ) {
      actual.reserve(13);
      THEN ("the capacity should increase to 13") {
        CHECK(actual.capacity() == 13);
      } AND_THEN ( "the size should be 0" ) {
        CHECK(actual.size() == expected.size());
      }
    }
  }

}

SCENARIO( "Test mesa::bag reserve invariants" ) {

  GIVEN( "a valid bag of 6 elements and capacity 6" ) {
    mesa::bag<int> actual {3,1,4,1,5,9};
    mesa::bag<int> expected {3,1,4,1,5,9};
    WHEN( "3 spaces are reserved" ) {
      actual.reserve(3);
      THEN ("the capacity should not change") {
        CHECK(actual.capacity() == 6);
      } AND_THEN ( "the size should be unchanged" ) {
        CHECK(actual.size() == expected.size());
      } AND_THEN ( "all elements should be unchanged" ) {
        for (int i = 0; i < int(actual.size()); ++i) {
          REQUIRE_MESSAGE(actual.at(i) == expected.at(i), 
              "could not access element " << i);
        }
      }
    }
  }

}

