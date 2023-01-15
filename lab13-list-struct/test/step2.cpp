#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test list struct") {
  WHEN( "a list is created" ) {
    list x;

    THEN( "the default value should be 0" ) {
      CHECK (x.val == 0);
    }
    AND_THEN( "the next pointer should == nullptr" ) {
      CHECK (x.next == nullptr);
    }
  }
  WHEN( "the the value is set to 13" ) {
    list x;
    x.val = 13;
    THEN( "the value should change" ) {
      CHECK (x.val == 13);
    }
  }
  WHEN( "the the value is set to -8" ) {
    list x;
    x.val = -8;
    THEN( "the value should change" ) {
      CHECK (x.val == -8);
    }
  }
  WHEN( "the the value is set to 5 and a next pointer is created" ) {
    list a;
    a.val = 5;
    list* b = new list;
    a.next = b;
    THEN( "the value should change" ) {
      CHECK (a.val == 5);
    }
    AND_THEN( "the value of a.next should be the address of b" ) {
      CHECK (a.next == b);
    }
  }
}


