#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test list insert_after()") {

  GIVEN( "a non-empty list" ) {
    mesa::list<int> test_list{1};
    WHEN( "insert_after is called on a list with only 1 element" ) {
      auto head = test_list.front();
      int expected = 13;
      CHECK(test_list.size() == 1);
      THEN( "it should append to the list" ) {
        test_list.insert_after(0, expected);
        CHECK_MESSAGE(test_list.front() == head, "expected the head to == 1");
        CHECK(test_list.size() == 2);
        test_list.pop_front();
        CHECK_MESSAGE(test_list.front() == expected, "expected the second value to == 13");
      }
    }
    WHEN( "insert_after is called on a 2-element list" ) {
      test_list.push_front(3);
      auto head = test_list.front();
      CHECK(test_list.size() == 2);
      THEN( " pos == 0 should insert between the 2 nodes" ) {
        test_list.insert_after(0, 2);
        CHECK_MESSAGE(test_list.front() == head, "expected the head value to == 3");
        CHECK_MESSAGE(test_list.size() == 3, "expected 3 elements after insert");
        test_list.pop_front();
        CHECK_MESSAGE(test_list.front() == 2, "expected the second value to == 2");
        test_list.pop_front();
        CHECK_MESSAGE(test_list.front() == 1, "expected the first value to == 1");
      }
      AND_THEN( " pos == 1 should append to the list 2 element list" ) {
        test_list.insert_after(1, 99);
        CHECK_MESSAGE(test_list.front() == head, "expected the head value to == 3");
        CHECK_MESSAGE(test_list.size() == 3, "expected 3 elements after insert");
        test_list.pop_front();
        CHECK_MESSAGE(test_list.front() == 1, "expected the second value to == 1");
        test_list.pop_front();
        CHECK_MESSAGE(test_list.front() == 99, "expected the first value to == 99");
      }
    }
  }
}
