#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test mesa::list<T>::erase_after") {

  GIVEN( "a non-empty ordered list" ) {
    mesa::list<int> actual;
    actual.push_front(4);
    actual.push_front(3);
    actual.push_front(2);
    actual.push_front(1);
    WHEN( "erase_after is called on a 4-element list" ) {
      auto head = actual.begin();
      CHECK(actual.size() == 4);
      THEN( " begin should erase the 2nd element" ) {
        auto it = actual.erase_after(head);
        CHECK(actual.size() == 3);
        CHECK(*head == 1);
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 4);
      }
      AND_THEN( " begin+1 should remove the third element" ) {
        auto tmp = actual.begin();
        ++tmp;
        auto it = actual.erase_after(tmp);
        CHECK(actual.size() == 3);
        CHECK(*head == 1);
        CHECK(*it == 4);
      }
    }
  }

  GIVEN( "a non-empty unordered list" ) {
    mesa::list<std::string> actual;
    actual.push_front("cursed");
    actual.push_front("be");
    actual.push_front("also");
    actual.push_front("may");
    actual.push_front("frogurt");
    actual.push_front("the");
    WHEN( "erase_after is called on a 6-element list" ) {
      auto head = actual.begin();
      CHECK(actual.size() == 6);
      THEN( " begin should erase the 2nd element" ) {
        auto it = actual.erase_after(head);
        CHECK(actual.size() == 5);
        CHECK(*head == std::string("the"));
        CHECK(*it == std::string("may"));
        ++it;
        CHECK(*it == std::string("also"));
      }
      AND_THEN( " begin+1 should remove the third element" ) {
        auto tmp = actual.begin();
        ++tmp;
        auto it = actual.erase_after(tmp);
        CHECK(actual.size() == 5);
        CHECK(*head == std::string("the"));
        CHECK(*it == std::string("also"));
      }
    }
  }
}

