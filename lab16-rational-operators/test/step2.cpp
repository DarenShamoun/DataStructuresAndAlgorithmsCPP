#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/rational.h"

SCENARIO( "Check equality") {
  GIVEN( "a single rational" ) {
    rational a {1,3};
    WHEN("compared with itself") {
      THEN( "it should be considered equal (reflexive property)" ) {
        REQUIRE (a == a);
      }
    }
  }
  GIVEN( "eqivalent rationals" ) {
    WHEN("a = 1/3, b = 1/3") {
      rational a {1,3};
      rational b {1,3};
      THEN( "the two numbers should be considered equal (a==b)" ) {
        REQUIRE (a == b);
      }
      AND_THEN( "symmetry should also hold (b==a)" ) {
        REQUIRE (b == a);
      }
    }
    WHEN("a = 1/2, b = 5/10") {
      rational a {1,2};
      rational b {5,10};
      THEN( "the two numbers should be considered equal" ) {
        REQUIRE (a == b);
        CHECK (a <= b);
      }
    }
    WHEN("there are 3 equal numbers, a == b == c") {
      rational a {1,3};
      rational b {3,9};
      rational c {9,27};
      THEN( "equality is symmetric" ) {
        REQUIRE ((a == b && b == a));
      }
      AND_THEN( "equality is transitive" ) {
        REQUIRE ((a == b && b == c && a == c));
      }
      AND_THEN( "a <= b <= c" ) {
        CHECK (a <= b);
        CHECK (b <= c);
        CHECK (a <= c);
      }
      rational d {1,9};
      rational e {2,18};
      rational f {-1,-9};
      CHECK_MESSAGE(d == d, "reflexive property");
      CHECK_MESSAGE((d == e && e == d), "symmetry property");
      CHECK_MESSAGE((d == e && e == f && d == f), "transitive property");
    }
  }

  GIVEN( "two unequal rationals" ) {
    WHEN("a = 1/3, b = 1/4") {
      rational a {1,3};
      rational b {1,4};
      THEN( "the two numbers should be considered not equal (a!=b)" ) {
        REQUIRE (a != b);
      }
      AND_THEN( "symmetry should also hold (b!=a)" ) {
        REQUIRE (b != a);
      }
      AND_THEN( "b < a" ) {
        CHECK (b <= a);
        REQUIRE (b < a);
      }
      AND_THEN( "a > b" ) {
        CHECK (a >= b);
        REQUIRE (a > b);
      }
    }
    WHEN("a = 1/9, b = 1/11") {
      REQUIRE (rational{1,9} > rational{1,11});
      REQUIRE (rational{1,11} < rational{1,9});
    }
    WHEN("there are 3 unequal numbers, a != b != c") {
      rational a {2,3};
      rational b {2,9};
      rational c {8,27};
      THEN( "a != b" ) {
        REQUIRE (a != b);
      }
      AND_THEN( "b != c" ) {
        REQUIRE (b != c);
      }
      AND_THEN( "a != c (transitive property)" ) {
        REQUIRE (a != c);
      }
    }
  }
  GIVEN( "two unequal rationals" ) {
    WHEN("a = 1/3, b = 1/4") {
      rational a {1,3};
      rational b {1,4};
      AND_WHEN("a is assigned to b") {
        b = a;
        THEN( "the two numbers should be considered equal" ) {
          REQUIRE (a == b);
        }
      }
      AND_WHEN("b is assigned to a") {
        a = b;
        THEN( "the two numbers should be considered equal" ) {
          REQUIRE (a == b);
        }
      AND_THEN( "assignment should return a reference" ) {
        REQUIRE (std::is_lvalue_reference<decltype(b=a)>::value == true);
      }
      }
    }
  }

}


