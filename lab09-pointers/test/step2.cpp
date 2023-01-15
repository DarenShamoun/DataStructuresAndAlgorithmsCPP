#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <lab9.h>

SCENARIO( "Transform C string to lower case") {

  GIVEN( "a valid C string" ) {
    WHEN( "HELLO is provided" ) {
      THEN( "the string should become hello" ) {
        char orig[6] = "HELLO";
        char expected[6] = "hello";
        mesa::to_lower(orig);
        REQUIRE(doctest::toString(orig) == doctest::toString(expected));
      }
    }
    WHEN( "'Howdy, There!' is provided" ) {
      THEN( "the string should become howdy, there!" ) {
        char orig[14] = "Howdy, There!";
        char expected[14] = "howdy, there!";
        mesa::to_lower(orig);
        REQUIRE(doctest::toString(orig) == doctest::toString(expected));
      }
    }
    WHEN( "'already lower' is provided" ) {
      THEN( "the string should become howdy, there!" ) {
        char orig[14] = "already lower";
        char expected[14] = "already lower";
        mesa::to_lower(orig);
        REQUIRE(doctest::toString(orig) == doctest::toString(expected));
      }
    }
  }
}

SCENARIO( "Compute the invariants of to_lower") {

  GIVEN( "a C string with an early null" ) {
    WHEN( "'Howdy,\0There!' is provided(null char in space)" ) {
      THEN( "the string should become howdy," ) {
        char orig[14] = "Howdy,\0There!";
        char expected[14] = "howdy,";
        mesa::to_lower(orig);
        REQUIRE(doctest::toString(orig) == doctest::toString(expected));
      }
    }
  }
}




