#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test list push_front() and front()") {

  GIVEN( "an empty list" ) {
    mesa::list<int> test_list;

    WHEN( "push_front is called on an empty list" ) {
      int expected = 13;
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
    }

    WHEN( "push_front is called on a 2-element list" ) {
      int expected = 5;
      test_list.push_front(8);
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
    }

    WHEN( "push_front is called on a 3-element list" ) {
      int expected = 3;
      test_list.push_front(8);
      test_list.push_front(5);
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
    }

  }

  GIVEN( "a constant list is constructed" ) {
    int expected = 2;
    const mesa::list<int> test_list{expected};

    WHEN( "front is called on a const list" ) {
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
    }
  }

}
