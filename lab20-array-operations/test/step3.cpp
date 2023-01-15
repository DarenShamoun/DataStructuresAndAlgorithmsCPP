#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <numeric>
#include <string>
#include <utility>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "function at() element get" ) {

  WHEN( "constructing mesa::array<int,3>" ) {
    mesa::array<int,3> actual;
    THEN ("empty should return false") {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == 3);
    } AND_THEN ("all three elements should equal 0") {
      CHECK(actual.at(0) == 0);
      CHECK(actual.at(1) == 0);
      CHECK(actual.at(2) == 0);
    }
  }
}

SCENARIO( "function at() element assignment" ) {
  WHEN( "constructing mesa::array<std::string,3>" ) {
    mesa::array<std::string,3> actual;
    THEN ("empty should return false") {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == 3);
    } AND_THEN ("all three elements should equal the empty string") {
      std::string expected;
      CHECK(actual.at(0) == expected);
      CHECK(actual.at(1) == expected);
      CHECK(actual.at(2) == expected);
    } AND_THEN ("element assignment should work using at()") {
      actual.at(0) = "first string";
      CHECK(actual.at(0) == std::string("first string"));
      actual.at(1) = "middle string";
      CHECK(actual.at(1) == std::string("middle string"));
      actual.at(2) = "last string";
      CHECK(actual.at(2) == std::string("last string"));
    }
  }
}

SCENARIO( "Verify at() does bounds checking" 
    * doctest::should_fail(true) ) {
  GIVEN( "A valid array"  ) {
    WHEN( "the array index is out of bounds" ) {
      mesa::array<int,34> actual;
      THEN ("an std:out_of_range exception should throw") {
        std::iota(actual.begin(), actual.end(), 99);
        CHECK(actual.at(0) == 99);
        CHECK(actual.at(34) == 100);
      }
    }
  }

}

