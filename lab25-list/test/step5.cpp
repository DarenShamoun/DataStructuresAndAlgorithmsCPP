#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test list pop_front()") {

  GIVEN( "an empty list" ) {
    mesa::list<int> test_list;
    WHEN( "the list is empty" ) {
      THEN( "the pop_front should do nothing" ) {
        CHECK(test_list.empty() == true);
        CHECK(test_list.size() == 0);
        test_list.pop_front();
        CHECK(test_list.empty() == true);
        CHECK(test_list.size() == 0);
      }
    }

    WHEN( "pop_front is called on a list with only 1 element" ) {
      test_list.push_front(13);
      CHECK(test_list.size() == 1);
      THEN( "it should empty the list" ) {
        test_list.pop_front();
        CHECK(test_list.empty() == true);
        CHECK(test_list.size() == 0);
      }
    }

    WHEN( "pop_front is called on a 2-element list" ) {
      int expected = 5;
      test_list.push_front(expected);
      test_list.push_front(8);
      CHECK(test_list.size() == 2);
      THEN( "the front element is removed with 1 remaining" ) {
        test_list.pop_front();
        CHECK(test_list.front() == expected);
        CHECK(test_list.size() == 1);
        CHECK(test_list.empty() == false);
      }
    }

    WHEN( "pop_front is called on a 3-element list" ) {
      int expected = 3;
      test_list.push_front(8);
      test_list.push_front(expected);
      test_list.push_front(5);
      CHECK(test_list.size() == 3);
      THEN( "the front element is removed with 2 remaining" ) {
        test_list.pop_front();
        CHECK(test_list.front() == expected);
        CHECK(test_list.size() == 2);
      }
    }

  }

}
