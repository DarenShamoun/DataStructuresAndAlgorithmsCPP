#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/rational.h"

const rational zero = rational{0};
const rational one = rational{1};

SCENARIO( "Check subtraction") {
  GIVEN( "a single rational" ) {
    WHEN("subtracted from itself") {
      THEN( "result should equal 0" ) {
        REQUIRE (one-one == zero);
        REQUIRE (rational{13/3}-rational{13/3} == zero);
      }
    }
    WHEN("zero is subtracted from anything") {
      THEN( "the identity value should be preserved" ) {
        REQUIRE (zero-zero == zero);
        REQUIRE (one-zero == one);
        REQUIRE (rational{2}-zero == rational{2});
        REQUIRE (rational{-22,7}-zero == rational{-22,7});
      }
    }
    WHEN("one is subtracted from anything") {
      THEN( "the value should decrease by 1" ) {
        REQUIRE (rational{2}-one == one);
        REQUIRE (rational{-22,7}-one == rational{-29,7});
        REQUIRE (rational{1,2}-one == rational{-1,2});
      }
    }
  }
  GIVEN( "two rationals" ) {
    REQUIRE (rational{2} - rational{3} == rational{-1});
    REQUIRE (rational{2} - rational{-2} == rational{4});
    REQUIRE (rational{22,7} - rational{-22,7} == rational{44,7});
    WHEN("using -= ") {
      rational a {1,2};
      rational b {2};
      rational c {1,2};
      rational d {2};
      THEN( "a -= b should change a in the same manner as a = a-b" ) {
        REQUIRE (a-b == c-d);
        a-=b;
        REQUIRE (a == c-d);
      }
      AND_THEN( "a-=b should return a reference" ) {
        REQUIRE (std::is_lvalue_reference<decltype(a-=b)>::value == true);
      }
    }
  }
}



