#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bag.h"

SCENARIO( "Test mesa::bag resize" ) {

  GIVEN( "a valid bag of 6 elements" ) {
    mesa::bag<int> actual {3,1,4,1,5,9};
    mesa::bag<int> expected {3,1,4,1,5,9,0,0,0,0};
    WHEN( "the bag is resized to 10" ) {
      actual.resize(10);
      THEN ("the capacity should increase by 4") {
        CHECK(actual.capacity() == 10);
      } AND_THEN ( "the size should be 10" ) {
        CHECK(actual.size() == expected.size());
      } AND_THEN ( "old elements should be unchanged and new elements should be initialized" ) {
        for (int i = 0; i < int(expected.size()); ++i) {
          REQUIRE(actual.at(i) == expected.at(i));
        }
      }
    }
  }

  GIVEN( "an empty bag" ) {
    mesa::bag<int> actual;
    WHEN( "the bag is resized" ) {
      actual.resize(13);
      THEN ("the capacity should increase to 13") {
        CHECK(actual.capacity() == 13);
      } AND_THEN ( "the size should be 13" ) {
        CHECK(actual.size() == 13);
      } AND_THEN ( "all elements should be initialized" ) {
        for (int i = 0; i < 13; ++i) {
          REQUIRE_MESSAGE(actual.at(i) == 0, 
              "could not access element " << i);
        }
      }
    }
  }

}

SCENARIO( "Test mesa::bag resize invariants" ) {

  GIVEN( "a valid bag of 6 elements and capacity 6" ) {
    mesa::bag<int> actual {3,1,4,1,5,9};
    mesa::bag<int> expected {3,1,4};
    WHEN( "the bag is resized to 3" ) {
      actual.resize(3);
      THEN ("the bag capacity is unchanged") {
        CHECK(actual.capacity() == 6);
      } AND_THEN ( "the size should be reduced to 3" ) {
        CHECK(actual.size() == expected.size());
      } AND_THEN ( "all remaining elements should be unchanged" ) {
        for (int i = 0; i < int(actual.size()); ++i) {
          REQUIRE(actual.at(i) == expected.at(i)); 
        }
      }
    }
  }

}

