#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <lab6.h>
#include "util.h"

SCENARIO( "construct a pythagorean triple from a pair of integers 'm' and 'n'") {

  GIVEN( "A pair of unsigned integers, with m > n > 0" ) {
    WHEN( "2 and 1 are provided" ) {
      auto result = mesa::make_triple(2,1);
      THEN( "a {3,4,5} triangle should be returned" ) {
        CHECK( result.a  == doctest::Approx(3));
        CHECK( result.b  == doctest::Approx(4));
        REQUIRE( result.c  == doctest::Approx(5));
      }
    }
    WHEN( "4 and 3 are provided" ) {
      auto result = mesa::make_triple(4,3);
      THEN( "the fourth pythagorean triple {7,24,25} should be returned" ) {
        CHECK( result.a  == doctest::Approx(7));
        CHECK( result.b  == doctest::Approx(24));
        CHECK( result.c  == doctest::Approx(25));
      }
    }
    WHEN( "13 and 8 are provided" ) {
      auto result = mesa::make_triple(13,8);
      THEN( "the 38th pythagorean triple should be returned" ) {
        CHECK( result.a  == doctest::Approx(105));
        CHECK( result.b  == doctest::Approx(208));
        CHECK( result.c  == doctest::Approx(233));
      }
    }
  }
}



SCENARIO( "validate invariants of make_triple") {

  GIVEN( "A pair of invalid integers" ) {
    WHEN( "n is greater than m" ) {
      auto result = mesa::make_triple(3,4);
      THEN( "a triple = {0,0,0} should be returned" ) {
        CHECK( result.a  == 0);
        CHECK( result.b  == 0);
        CHECK( result.c  == 0);
      }
    }
    WHEN( "n and m are equal" ) {
      auto result = mesa::make_triple(3,3);
      THEN( "a triple = {0,0,0} should be returned" ) {
        CHECK( result.a  == 0);
        CHECK( result.b  == 0);
        CHECK( result.c  == 0);
      }
    }
    WHEN( "n and m are equal" ) {
      auto result = mesa::make_triple(0,0);
      THEN( "a triple = {0,0,0} should be returned" ) {
        CHECK( result.a  == 0);
        CHECK( result.b  == 0);
        CHECK( result.c  == 0);
      }
    }
    WHEN( "n < 0" ) {
      auto result = mesa::make_triple(-3,8);
      THEN( "a triple = {0,0,0} should be returned" ) {
        CHECK( result.a  == 0);
        CHECK( result.b  == 0);
        REQUIRE( result.c  == 0);
      }
    }
    WHEN( "n is 0" ) {
      auto result = mesa::make_triple(0,8);
      THEN( "a triple = {0,0,0} should be returned" ) {
        CHECK( result.a  == 0);
        CHECK( result.b  == 0);
        REQUIRE( result.c  == 0);
      }
    }
    WHEN( "m is 0" ) {
      auto result = mesa::make_triple(5,0);
      THEN( "a triple = {0,0,0} should be returned" ) {
        CHECK( result.a  == 0);
        CHECK( result.b  == 0);
        REQUIRE( result.c  == 0);
      }
    }
    WHEN( "m < 0" ) {
      auto result = mesa::make_triple(13,-8);
      THEN( "a triple = {0,0,0} should be returned" ) {
        CHECK( result.a  == 0);
        CHECK( result.b  == 0);
        REQUIRE( result.c  == 0);
      }
    }
    WHEN( "both n and m < 0" ) {
      auto result = mesa::make_triple(-13,-8);
      THEN( "a triple = {0,0,0} should be returned" ) {
        CHECK( result.a  == 0);
        CHECK( result.b  == 0);
        REQUIRE( result.c  == 0);
      }
    }
  }
}



