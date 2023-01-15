#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/rational.h"

static const rational zero = rational{0};
static const rational one = rational{1};
static const auto inf = rational{0,0};

SCENARIO( "Check division") {
  GIVEN( "a single rational" ) {
    WHEN("divided into itself") {
      THEN( "result should equal 1" ) {
        REQUIRE (one/one == one);
        REQUIRE (rational{3}/rational{3} == one);
        REQUIRE (rational{13/3}/rational{13/3} == one);
      }
    }
    WHEN("one is divided into anything") {
      THEN( "the value should remain unchanged" ) {
        REQUIRE (rational{2}/one == rational{2});
        REQUIRE (rational{-22,7}/one == rational{-22,7});
        REQUIRE (rational{1,2}/one == rational{1,2});
      }
    }
    WHEN("zero is divided into anything") {
      THEN( "the result should be infinity" ) {
        REQUIRE (zero/zero == inf);
        REQUIRE (one/zero == inf);
        REQUIRE (rational{2}/zero == inf);
        REQUIRE (rational{-22,7}/zero == inf);
      }
    }
  }
  GIVEN( "two rationals" ) {
    REQUIRE (rational{2} / rational{3} == rational{2,3});
    REQUIRE (rational{2} / rational{-2} == rational{-1});
    REQUIRE (rational{22,7} / rational{-22,7} == rational{-1});
    WHEN("using /= ") {
      rational a {1,2};
      rational b {2};
      rational c {1,2};
      rational d {2};
      THEN( "a /= b should change a in the same manner as a = a/b" ) {
        REQUIRE (a/b == c/d);
        a/=b;
        REQUIRE (a == c/d);
      }
      AND_THEN( "a/=b should return a reference" ) {
        REQUIRE (std::is_lvalue_reference<decltype(a/=b)>::value == true);
      }
    }
  }
}



