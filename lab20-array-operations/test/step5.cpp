#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iterator>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "Check array equality") {
  GIVEN( "a single array" ) {
    mesa::array<int,2> a {1,3};
    WHEN("compared with itself") {
      THEN( "it should be considered equal (reflexive property)" ) {
        REQUIRE (operator==(a,a));
      }
    }
  }

  GIVEN( "eqivalent arrays" ) {
    WHEN("two different arrays store the same values") {
      mesa::array<int,5> a {1,3,2,5,8};
      mesa::array<int,5> b {1,3,2,5,8};
      THEN( "the two objects should be considered equal (a==b)" ) {
        REQUIRE (operator==(a,b));
      }
      AND_THEN( "symmetry should also hold (b==a)" ) {
        REQUIRE (operator==(b,a));
      }
    }
    WHEN("there are 3 equal arrays, a == b == c") {
      mesa::array<int,8> a {1,3,2,5,8,13,21,34};
      mesa::array<int,8> b {1,3,2,5,8,13,21,34};
      mesa::array<int,8> c {1,3,2,5,8,13,21,34};
      THEN( "equality is symmetric" ) {
        REQUIRE ( (operator==(a,b) && operator==(b,a)) );
      }
      AND_THEN( "equality is transitive" ) {
        REQUIRE ( (operator==(a,b) && operator==(b,c) && operator==(a,c)) );
      }
    }
  }

  GIVEN( "two unequal arrays" ) {
    WHEN("a = 1/3, b = 1/4") {
      mesa::array<int,2> a {1,3};
      mesa::array<int,2> b {1,4};
      THEN( "the two arrays should be considered not equal (a!=b)" ) {
        REQUIRE (operator!=(a,b));
      }
      AND_THEN( "symmetry should also hold (b!=a)" ) {
        REQUIRE (operator!=(b,a));
      }
    }
    WHEN("there are 3 unequal numbers, a != b != c") {
      mesa::array<int,2> a {2,3};
      mesa::array<int,2> b {2,9};
      mesa::array<int,2> c {8,27};
      THEN( "a != b" ) {
        REQUIRE (operator!=(a,b));
      }
      AND_THEN( "b != c" ) {
        REQUIRE (operator!=(b,c));
      }
      AND_THEN( "a != c (transitive property)" ) {
        REQUIRE (operator!=(a,c));
      }
    }
  }
  GIVEN( "two unequal arrays" ) {
    WHEN("a = 1/3, b = 1/4") {
      mesa::array<int,2> a {1,3};
      mesa::array<int,2> b {1,4};
      CHECK (operator!=(a,b));
      AND_WHEN("a is assigned to b") {
        b = a;
        THEN( "the two numbers should be considered equal" ) {
          REQUIRE (operator==(a,b));
        }
      }
      AND_WHEN("b is assigned to a") {
        a = b;
        THEN( "the two numbers should be considered equal" ) {
          REQUIRE (operator==(a,b));
        }
      }
    }
  }

}


