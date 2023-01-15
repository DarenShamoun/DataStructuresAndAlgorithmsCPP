#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bag.h"


SCENARIO( "Test mesa::bag push_back" ) {

  GIVEN( "a valid bag of 6 elements" ) {
    mesa::bag<int> actual {1,2,3,4,5,6};
    mesa::bag<int> expected {1,2,3,4,5,6,7};
    WHEN( "a value is pushed back" ) {
      actual.push_back(7);
      THEN ("the capacity should double") {
        CHECK(actual.capacity() == 12);
      } AND_THEN ( "the size should be 7" ) {
        CHECK(actual.size() == expected.size());
      } AND_THEN ( "old elements should be unchanged and the new alement should be the last" ) {
        for (int i = 0; i < int(expected.size()); ++i) {
          REQUIRE(actual.at(i) == expected.at(i));
        }
      }
    }
  }

  GIVEN( "an empty bag" ) {
    mesa::bag<int> actual;

    WHEN( "a value is pushed back" ) {
      actual.push_back(1);
      THEN ("the capacity should increase to 1") {
        CHECK(actual.capacity() == 1);
      } AND_THEN ( "the size should be 1" ) {
        CHECK(actual.size() == 1);
      } AND_THEN ( "the new value should be the first element" ) {
        CHECK(actual.at(0) == 1);
      }
    }

    WHEN( "two values are pushed back" ) {
      actual.push_back(1);
      actual.push_back(2);
      THEN ("the capacity should double") {
        CHECK(actual.capacity() == 2);
      } AND_THEN ( "the size should be 1" ) {
        CHECK(actual.size() == 2);
      } AND_THEN ( "the new value should be appended in order" ) {
        CHECK(actual.at(0) == 1);
        CHECK(actual.at(1) == 2);
      }
    }

    WHEN( "three values are pushed back" ) {
      actual.push_back(1);
      actual.push_back(2);
      actual.push_back(3);
      THEN ("the capacity should double twice") {
        CHECK(actual.capacity() == 4);
      } AND_THEN ( "the size should be 3" ) {
        CHECK(actual.size() == 3);
      } AND_THEN ( "the new value should be appended in order" ) {
        CHECK(actual.at(0) == 1);
        CHECK(actual.at(1) == 2);
        CHECK(actual.at(2) == 3);
      }
    }

  }

}


