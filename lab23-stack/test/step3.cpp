#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <utility>
#include <doctest.h>
#include "../src/bag.h"
#include "../src/stack.h"


SCENARIO( "Test mesa::stack constructors" ) {

  WHEN( "a stack is created by default" ) {
    mesa::stack<int> actual;
    THEN( "the stack is empty" ) {
      CHECK(actual.empty() == true);
      CHECK(actual.size() == 0);
    }
  }

  WHEN( "a stack is created from a bag" ) {
    mesa::bag<int> expected {1,2,3,4,5};
    mesa::stack<int> actual {expected};
    THEN( "the stack has the same size as the bag" ) {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == expected.size());
    }
  }

  WHEN( "a stack is created by copying from a stack" ) {
    mesa::bag<int> stuff {1,2,3,4,5};
    mesa::stack<int> expected {stuff};
    mesa::stack<int> actual {expected};
    THEN( "the stack has the same size as the original stack" ) {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == expected.size());
    }
  }

  WHEN( "a stack is assigned new values copied from a stack" ) {
    mesa::bag<int> stuff {1,2,3,4,5};
    mesa::stack<int> expected {stuff};
    mesa::stack<int> actual;
    actual = expected;
    THEN( "the stack has the same size as the original stack" ) {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == expected.size());
    }
  }

  WHEN( "a stack is created by moving from a stack" ) {
    mesa::bag<int> stuff {1,2,3,4,5};
    mesa::stack<int> expected {stuff};
    CHECK(expected.size() == 5);
    mesa::stack<int> actual {std::move(expected)};
    THEN( "the stack has the same size as the original stack" ) {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == 5);
    }
  }

  WHEN( "a stack is assigned new values moved from a stack" ) {
    mesa::bag<int> stuff {1,2,3,4,5};
    mesa::stack<int> expected {stuff};
    mesa::stack<int> actual;
    CHECK(expected.size() == 5);
    actual = std::move(expected);
    THEN( "the stack has the same size as the original stack" ) {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == 5);
    }
  }

}


