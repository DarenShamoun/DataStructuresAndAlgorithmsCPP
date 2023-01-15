#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <doctest.h>
#include "../src/rational.h"


SCENARIO( "convert a rational to a string") {
  GIVEN ("a valid rational number") {
    WHEN("the rational is 0") {
      rational r {0};
      THEN( "the value should convert to the string '0'" ) {
        REQUIRE (std::string(r) == std::string("0"));
      }
    }
    WHEN("the rational is 0, 5") {
      rational r {0,5};
      THEN( "the value should convert to the string '0'" ) {
        REQUIRE (std::string(r) == std::string("0"));
      }
    }
    WHEN("the rational is 1/2") {
      rational r {1,2};
      THEN( "the value should convert to the string '1/2'" ) {
        REQUIRE (std::string(r) == std::string("1/2"));
      }
    }
    WHEN("the rational is {-22,7}") {
      rational r {-22,7};
      THEN( "the value should convert to the string '-22/7'" ) {
        REQUIRE (std::string(r) == std::string("-22/7"));
      }
    }
    WHEN("the denominator is 0 and the numerator is not") {
      rational r {5,0};
      THEN( "the value should convert to the string 'inf'" ) {
        REQUIRE (std::string(r) == std::string("inf"));
      }
    }
    WHEN("the numerator and denominator are equal") {
      rational r {3,3};
      THEN( "the value should convert to the string '1'" ) {
        REQUIRE (std::string(r) == std::string("1"));
      }
    }
  }
}

