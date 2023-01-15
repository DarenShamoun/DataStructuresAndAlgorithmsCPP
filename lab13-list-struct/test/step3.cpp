#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test list struct constructor") {
  WHEN( "the the value is created with 21" ) {
    list x {21};
    THEN( "the value should initialize as 21" ) {
      CHECK (x.val == 21);
    }
    AND_THEN( "the next pointer should initialize == nullptr" ) {
      CHECK (x.next == nullptr);
    }
  }
  WHEN( "the the value is set to -34" ) {
    list x {-34};
    THEN( "the value should initialize to -34" ) {
      CHECK (x.val == -34);
    }
  }
  WHEN( "the the value is set to 5 and a next pointer is created" ) {
    list a {5};
    list* b = new list{-13};
    a.next = b;
    THEN( "the value of the head node should be 5" ) {
      CHECK (a.val == 5);
    }
    AND_THEN( "the value of a.next should be the address of b" ) {
      CHECK (a.next == b);
    }
    AND_THEN( "a.next->value should equal -13" ) {
      CHECK (a.next->val == -13);
    }
  }
}


