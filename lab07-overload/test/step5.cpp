
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

#include "../src/lab7.h"

SCENARIO( "evaluate if 2 points are not equal") {

  GIVEN( "equal points" ) {

    WHEN( "comparing the same point" ) {
      mesa::point a {0,0};
      THEN( "it should equal itself (reflexive)" ) {
        REQUIRE( operator==(a,a) );
      }
      AND_THEN( "!= should return false" ) {
        REQUIRE( !operator!=(a,a) );
      }
    }
  }

  GIVEN( "different points" ) {

    WHEN( "different points are compared" ) {
      mesa::point a {-2,-3};
      mesa::point b {8,-13};
      THEN( "a != b" ) {
        REQUIRE( operator!=(a,b) );
      }
      AND_THEN( "b != a (symmetry)" ) {
        REQUIRE( operator!=(b,a) );
      }
    }
  
    WHEN( "the x value is the same and the y is different" ) {
      mesa::point a {21,34};
      mesa::point b {21,-13};
      THEN( "a != b" ) {
        REQUIRE( operator!=(a,b) );
      }
      AND_THEN( "b != a (symmetry)" ) {
        REQUIRE( operator!=(b,a) );
      }
    }
  
    WHEN( "the y value is the same and the x is different" ) {
      mesa::point a {34,13};
      mesa::point b {8,13};
      THEN( "a != b" ) {
        REQUIRE( operator!=(a,b) );
      }
      AND_THEN( "b != a (symmetry)" ) {
        REQUIRE( operator!=(b,a) );
      }
    }
  
  }

}


