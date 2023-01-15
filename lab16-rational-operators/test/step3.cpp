#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/rational.h"

const rational zero = rational{0};
const rational one = rational{1};

SCENARIO( "Check addition") {
  GIVEN( "a single rational" ) {
    WHEN("added to itself") {
      THEN( "it should equal a+a" ) {
        REQUIRE (one+one == rational{2});
        REQUIRE (rational{13/3}+rational{13/3} == rational{26/3});
      }
    }
    WHEN("zero is added to anything") {
      THEN( "the identity value should be preserved" ) {
        REQUIRE (zero+zero == zero);
        REQUIRE (one+zero == one);
        REQUIRE (zero+one == one);
        REQUIRE (rational{2}+zero == rational{2});
        REQUIRE (zero+rational{-22,7} == rational{-22,7});
      }
    }
    WHEN("one is added to anything") {
      THEN( "the value should increase by 1" ) {
        REQUIRE (rational{2}+one == rational{3});
        REQUIRE (one+rational{-22,7} == rational{-15,7});
      }
    }
  }
  GIVEN( "two rationals" ) {
    REQUIRE (rational{2} + rational{3} == rational{5});
    REQUIRE (rational{2} + rational{-2} == zero);
    WHEN("using += ") {
      rational a {1,2};
      rational b {2};
      rational c {1,2};
      rational d {2};
      THEN( "a += b should change a in the same manner as a = a+b" ) {
        REQUIRE (a+b == c+d);
        a+=b;
        REQUIRE (a == c+d);
      }
      AND_THEN( "a+=b should return a reference" ) {
        REQUIRE (std::is_lvalue_reference<decltype(a+=b)>::value == true);
      }
    }
  }
}



