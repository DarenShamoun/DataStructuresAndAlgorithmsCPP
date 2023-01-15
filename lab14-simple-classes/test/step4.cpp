#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <classes.h>

SCENARIO( "Test Truck class") {
  WHEN( "a Truck is created" ) {
    truck t;
    THEN( "the default num tires should == 6" ) {
      REQUIRE (t.tires() == 6);
    }
  }
  WHEN( "the number of tires is set == 18 when constructed" ) {
    truck t {18};
    THEN( "the num tires should == 18" ) {
      REQUIRE (t.tires() == 18);
    }
  }
  WHEN( "the a default constructed truck loses 1 tire" ) {
    truck t;
    t.pop_tire();
    THEN( "the tires remaining should == 5" ) {
      REQUIRE (t.tires() == 5);
    }
    t.pop_tire();
    t.pop_tire();
    t.pop_tire();
    t.pop_tire();
    t.pop_tire();
    AND_WHEN( "the a default constructed truck loses 5 more tires" ) {
      THEN( "the tires remaining should == 0" ) {
        REQUIRE (t.tires() == 0);
      }
    }
    t.pop_tire();
    AND_WHEN( "the number of pop_tire attempts is more than the tires on the truck" ) {
      THEN( "the tires remaining should still == 0" ) {
        REQUIRE (t.tires() == 0);
      }
    }
  }
}


