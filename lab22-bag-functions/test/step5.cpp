#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bag.h"


SCENARIO( "Test mesa::bag pop_back" ) {

  GIVEN( "a valid bag of 6 elements" ) {
    mesa::bag<int> actual {1,2,3,4,5,6};
    WHEN( "a value is popped off" ) {
      mesa::bag<int> expected {1,2,3,4,5};
      actual.pop_back();
      THEN ("the capacity should not change") {
        CHECK(actual.capacity() == 6);
      } AND_THEN ( "the size should be one less than before" ) {
        CHECK(actual.size() == expected.size());
      } AND_THEN ( "all remaining elements should be unchanged" ) {
        for (int i = 0; i < int(expected.size()); ++i) {
          REQUIRE(actual.at(i) == expected.at(i));
        }
      }
    }

    WHEN( "two values are popped off" ) {
      mesa::bag<int> expected {1,2,3,4};
      actual.pop_back();
      actual.pop_back();
      THEN ("the capacity should not change") {
        CHECK(actual.capacity() == 6);
      } AND_THEN ( "the size should be two less than before" ) {
        CHECK(actual.size() == expected.size());
      } AND_THEN ( "all remaining elements should be unchanged" ) {
        for (int i = 0; i < int(expected.size()); ++i) {
          REQUIRE(actual.at(i) == expected.at(i));
        }
      }
    }
  }

  GIVEN( "a bag of size 1" ) {
    mesa::bag<int> actual {1};

    WHEN( "a value is popped off" ) {
      actual.pop_back();
      THEN ("the capacity should stay the same") {
        CHECK(actual.capacity() == 1);
      } AND_THEN ( "the size should be 0" ) {
        CHECK(actual.size() == 0);
      } AND_THEN ( "the bag is now empty" ) {
        CHECK(actual.empty() == true);
      }
    }

    WHEN( "we try to pop_back more values than are in the bag" ) {
      actual.pop_back();
      actual.pop_back();
      THEN ( "the size should be 0" ) {
        CHECK(actual.size() == 0);
      } AND_THEN ( "the bag is empty" ) {
        CHECK(actual.empty() == true);
      }
    }

  }

}


