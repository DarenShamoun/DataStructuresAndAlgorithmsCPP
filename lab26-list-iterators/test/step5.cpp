#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test mesa::list<T> begin and end") {

  GIVEN( "a valid list" ) {
    WHEN( "the list is empty" ) {
    mesa::list<int> actual;
      THEN ( " begin and end should be equal " ) {
        CHECK( operator==(actual.begin(), actual.end()) ); 
      }
      AND_THEN ( " the list should be empty and size == 0 " ) {
        CHECK( actual.size() == 0); 
        CHECK( actual.empty() == true); 
      }
    }

    WHEN( "the list has one elemnt" ) {
    mesa::list<int> actual(1);
      THEN ( " begin and end should not be equal " ) {
        CHECK( operator!=(actual.begin(), actual.end()) ); 
      }
      AND_THEN ( " the list should be non-empty and size == 1 " ) {
        CHECK( actual.size() == 1); 
        CHECK( actual.empty() == false); 
      }
    }
  }

  GIVEN( "a valid const list" ) {
    WHEN( "the list is empty" ) {
    const mesa::list<int> actual;
      THEN ( " begin and end should be equal " ) {
        CHECK( operator==(actual.begin(), actual.end()) ); 
      }
      AND_THEN ( " the list should be empty and size == 0 " ) {
        CHECK( actual.size() == 0); 
        CHECK( actual.empty() == true); 
      }
    }

    WHEN( "the list has one elemnt" ) {
    const mesa::list<int> actual(1);
      THEN ( " begin and end should not be equal " ) {
        CHECK( operator!=(actual.begin(), actual.end()) ); 
      }
      AND_THEN ( " the list should be non-empty and size == 1 " ) {
        CHECK( actual.size() == 1); 
        CHECK( actual.empty() == false); 
      }
    }
  }

}

SCENARIO( "Test mesa::list<T>::insert_after") {

  GIVEN( "a non-empty list" ) {
    mesa::list<int> test_list{1};
    WHEN( "insert_after is called on a list with only 1 element" ) {
      auto head = test_list.front();
      int expected = 13;
      CHECK(test_list.size() == 1);
      THEN( "it should append to the list" ) {
        auto it = test_list.insert_after(test_list.begin(), expected);
        CHECK_MESSAGE(test_list.front() == head, "expected the head to == 1");
        CHECK(test_list.size() == 2);
        CHECK_MESSAGE(*it == expected, "expected the second value to == 13");
      }
    }
    WHEN( "insert_after is called on a 2-element list" ) {
      test_list.push_front(3);
      auto head = test_list.begin();
      CHECK(test_list.size() == 2);
      THEN( " begin should insert between the 2 nodes" ) {
        auto it = test_list.insert_after(head, 2);
        CHECK(test_list.size() == 3);
        CHECK_MESSAGE(3 == *head, "expected the head value to == 3");
        CHECK_MESSAGE(*it == 2, "expected the second value to == 2");
        ++it;
        CHECK_MESSAGE(*it == 1, "expected the last value to == 1");
      }
      AND_THEN( " begin+1 should append to the list 2 element list" ) {
        auto pointer = test_list.begin();
        ++pointer;
        auto it =test_list.insert_after(pointer, 99);
        CHECK_MESSAGE(test_list.size() == 3, "expected 3 elements after insert");
        CHECK_MESSAGE(test_list.front() == *head, "expected the head value to == 3");
        ++head;
        CHECK_MESSAGE(*head == 1, "expected the second value to == 1");
        ++pointer;
        CHECK_MESSAGE(*pointer == *it, "expected the last value to == the inserted value (99)");
      }
    }
  }
}



