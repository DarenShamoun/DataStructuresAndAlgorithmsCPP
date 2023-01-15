#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <utility>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "Test mesa::array<T,N> default constructor") {

  WHEN( "mesa::array is declared with a numeric type" ) {
    THEN ("all int elements should == 0") {
      mesa::array<int32_t, 3> array;
      for (const auto& actual: array) {
        CHECK(actual == 0);
      }
    }
    AND_THEN ("all double elements should == 0") {
      mesa::array<double, 21> array;
      for (const auto& actual: array) {
        REQUIRE(actual == doctest::Approx(0));
      }
    }
  }

  WHEN( "mesa::array is declared with a string type" ) {
    THEN ("all elements should == the empty string") {
      mesa::array<std::string, 3> array;
      std::string expected;
      for (const auto& actual: array) {
        CHECK(actual == expected);
      }
    }
  }

  WHEN( "mesa::array is declared with a std::pair type" ) {
    THEN ("all elements should == the empty string") {
      mesa::array<std::pair<std::string, float>, 34> array;
      std::pair<std::string, float> expected;
      for (const auto& actual: array) {
        CHECK(actual.first == expected.first);
        CHECK(actual.second == doctest::Approx(expected.second));
      }
    }
  }

}

