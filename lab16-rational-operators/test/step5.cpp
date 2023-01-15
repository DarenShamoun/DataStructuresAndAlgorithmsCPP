#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/rational.h"

const rational zero = rational{0};
const rational one = rational{1};

SCENARIO( "Check multiplication") {
  GIVEN( "a single rational" ) {
    WHEN("multiplied to itself") {
      THEN( "it should equal a*a" ) {
        REQUIRE (one*one == one);
        REQUIRE (rational{13/3}+rational{13/3} == rational{26/3});
      }
    }
    WHEN("zero is multiplied by anything") {
      THEN( "the result is zero" ) {
        REQUIRE (zero*zero == zero);
        REQUIRE (one*zero == zero);
        REQUIRE (zero*one == zero);
        REQUIRE (rational{2}*zero == zero);
        REQUIRE (zero*rational{-22,7} == zero);
      }
    }
    WHEN("one is multiplied by anything") {
      THEN( "the value is unchanged" ) {
        REQUIRE (zero*one == zero);
        REQUIRE (rational{13}*one == rational{13});
        REQUIRE (rational{-34}*one == rational{-34});
        REQUIRE (rational{1,9}*one == rational{1,9});
        REQUIRE (one*rational{-22,7} == rational{-22,7});
      }
    }
  }
  GIVEN( "two rationals" ) {
    REQUIRE (rational{2} * rational{3} == rational{6});
    REQUIRE (rational{5} * rational{-4} == rational{-20});
    WHEN("using *= ") {
      rational a {1,2};
      rational b {2};
      rational c {1,2};
      rational d {2};
      THEN( "a *= b should change a in the same manner as a = a*b" ) {
        REQUIRE (a*b == c*d);
        a*=b;
        REQUIRE (a == c*d);
      }
      AND_THEN( "a*=b should return a reference" ) {
        REQUIRE (std::is_lvalue_reference<decltype(a*=b)>::value == true);
      }
    }
  }
}



