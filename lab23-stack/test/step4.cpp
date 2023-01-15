#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bag.h"
#include "../src/stack.h"


SCENARIO( "Test mesa::stack operations" ) {

  GIVEN( "an empty stack" ) {
    mesa::stack<int> actual;
    WHEN( "empty" ) {
      THEN ( "the size should be zero" ) {
        CHECK(actual.size() == 0);
      }
      AND_THEN ( "empty == true" ) {
        CHECK(actual.empty() == true);
      }
    }

    WHEN( "a value is pushed on" ) {
      mesa::bag<int> expected {8};
      actual.push(8);
      THEN ( "the size should be 1" ) {
        CHECK(actual.size() == expected.size());
      } AND_THEN ( "the top element should be 8" ) {
        REQUIRE(actual.top() == expected.back());
      }
    }

    WHEN( "5 values are pushed on" ) {
      mesa::bag<int> expected {1,2,3,4,5};
      actual.push(1);
      actual.push(2);
      actual.push(3);
      actual.push(4);
      actual.push(5);
      THEN ( "the size should be 5" ) {
        CHECK(actual.size() == expected.size());
      }
      AND_THEN ( "the top element should be 5" ) {
        CHECK(actual.top() == expected.back());
      }
      AND_THEN ( "pop should remove the last item" ) {
        for (int i = 4; i >= 0; --i) {
          CHECK(actual.top() == expected[i]);
          CHECK(actual.size() == i+1);
          actual.pop();
        }
      }
    }

  }

  // GIVEN( "a valid bag of 6 elements" ) {
  //   mesa::bag<int> actual {1,2,3,4,5,6};
  //   WHEN( "a value is popped off" ) {
  //     mesa::bag<int> expected {1,2,3,4,5};
  //     actual.pop_back();
  //     THEN ("the capacity should not change") {
  //       CHECK(actual.capacity() == 6);
  //     } AND_THEN ( "the size should be one less than before" ) {
  //       CHECK(actual.size() == expected.size());
  //     } AND_THEN ( "all remaining elements should be unchanged" ) {
  //       for (int i = 0; i < int(expected.size()); ++i) {
  //         REQUIRE(actual.at(i) == expected.at(i));
  //       }
  //     }
  //   }

  // WHEN( "two values are popped off" ) {
  //   mesa::bag<int> expected {1,2,3,4};
  //   actual.pop_back();
  //   actual.pop_back();
  //   THEN ("the capacity should not change") {
  //     CHECK(actual.capacity() == 6);
  //   } AND_THEN ( "the size should be two less than before" ) {
  //     CHECK(actual.size() == expected.size());
  //   } AND_THEN ( "all remaining elements should be unchanged" ) {
  //     for (int i = 0; i < int(expected.size()); ++i) {
  //       REQUIRE(actual.at(i) == expected.at(i));
  //     }
  //   }
  // }
  // }

  // GIVEN( "a bag of size 1" ) {
  //   mesa::bag<int> actual {1};

  // WHEN( "a value is popped off" ) {
  //   actual.pop_back();
  //   THEN ("the capacity should stay the same") {
  //     CHECK(actual.capacity() == 1);
  //   } AND_THEN ( "the size should be 0" ) {
  //     CHECK(actual.size() == 0);
  //   } AND_THEN ( "the bag is now empty" ) {
  //     CHECK(actual.empty() == true);
  //   }
  // }
  // }

}


