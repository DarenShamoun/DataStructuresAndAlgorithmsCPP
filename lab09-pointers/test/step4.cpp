#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <lab9.h>

SCENARIO( "Count letters in C string matching a character") {

  GIVEN( "a valid C string" ) {
    WHEN( "HELLO is provided" ) {
      char orig[6] = "HELLO";
      THEN("count should find 2 L's" ) {
        auto actual = mesa::count(orig, 'L');
        REQUIRE(actual == 2);
      }
      AND_THEN("count should find 1 'O'" ) {
        auto actual = mesa::count(orig, 'O');
        REQUIRE(actual == 1);
      }
      AND_THEN("count should find no 'e'" ) {
        auto actual = mesa::count(orig, 'e');
        REQUIRE(actual == 0);
      }
    }
    WHEN( "'the quick brown fox jumped over the lazy dogs' is provided" ) {
      char orig[64] = "the quick brown fox jumped over the lazy dogs";
      THEN("count should find 4 'o's" ) {
        auto actual = mesa::count(orig, 'o');
        REQUIRE(actual == 4);
      }
      AND_THEN("count should find 2 'd's" ) {
        auto actual = mesa::count(orig, 'd');
        REQUIRE(actual == 2);
      }
      AND_THEN("count should find 1 'z'" ) {
        auto actual = mesa::count(orig, 'z');
        REQUIRE(actual == 1);
      }
      AND_THEN("count should find no 'T'" ) {
        auto actual = mesa::count(orig, 'T');
        REQUIRE(actual == 0);
      }
    }
  }
}

SCENARIO( "Compute the invariants of count") {

  GIVEN( "a C string with only null" ) {
    WHEN( "nothing is provided" ) {
        char empty[1] = {0};
      THEN("the count should be zero" ) {
        auto actual = mesa::count(empty, 'A');
        REQUIRE(actual == 0);
      }
    }
  }
}




