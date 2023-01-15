#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <utility>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "Test mesa::array<T,N> operator[]" ) {

  WHEN( "constructing mesa::array<int,3>" ) {
    mesa::array<int,3> actual;
    THEN ("empty should return false") {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == 3);
    } AND_THEN ("all three elements should equal 0") {
      CHECK(actual[0] == 0);
      CHECK(actual[1] == 0);
      CHECK(actual[2] == 0);
    }
  }

  WHEN( "constructing mesa::array<std::string,3>" ) {
    mesa::array<std::string,3> actual;
    THEN ("empty should return false") {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == 3);
    } AND_THEN ("all three elements should equal the empty string") {
      std::string expected;
      CHECK(actual[0] == expected);
      CHECK(actual[1] == expected);
      CHECK(actual[2] == expected);
    } AND_THEN ("element assignment should work using []") {
      actual[0] = "first string";
      CHECK(actual[0] == std::string("first string"));
      actual[1] = "middle string";
      CHECK(actual[1] == std::string("middle string"));
      actual[2] = "last string";
      CHECK(actual[2] == std::string("last string"));
    }
  }

}

