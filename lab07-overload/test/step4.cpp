
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

#include "../src/lab7.h"

SCENARIO( "evaluate if 2 points are equal") {

  GIVEN( "equal points" ) {

    WHEN( "comparing the same point" ) {
      mesa::point a {3,5};
      THEN( "it should equal itself (reflexive)" ) {
        REQUIRE( operator==(a,a) );
      }
    }
  
    WHEN( "different points are eqivalent" ) {
      mesa::point a {8,-13};
      mesa::point b {8,-13};
      THEN( "a == b" ) {
        REQUIRE( operator==(a,b) );
      }
      AND_THEN( "b == a (symmetry)" ) {
        REQUIRE( operator==(b,a) );
      }
    }
  
    WHEN( "a,b, &c are all eqivalent" ) {
      mesa::point a {34,21};
      mesa::point b {34,21};
      mesa::point c {34,21};
      THEN( "the transitive property should be true" ) {
        REQUIRE( operator==(a,b) );
        REQUIRE( operator==(b,c) );
        REQUIRE( operator==(a,c) );
      }
    }
  
  }

  GIVEN( "unequal points" ) {

    WHEN( "different points are not eqivalent" ) {
      mesa::point a {8,-13};
      mesa::point b {8,13};
      THEN( "a != b" ) {
        REQUIRE( !operator==(a,b) );
      }
      AND_THEN( "b != a (symmetry)" ) {
        REQUIRE( !operator==(b,a) );
      }
    }
  
  }

}


