#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <numeric>
#include <vector>

#include <doctest.h>
#include <classes.h>

SCENARIO( "Test Clock class") {
  WHEN( "a clock is created" ) {
    mesa::clock c;

    THEN( "the default value should be 0" ) {
      CHECK (c.time() == doctest::Approx(0));
    }
  }
  WHEN( "the the time is set to 43425.5" ) {
    mesa::clock c;
    c.time(43425.5);
    THEN( "the time returned should be the same" ) {
      CHECK (c.time() == doctest::Approx(43425.5));
    }
  }
  WHEN( "the the time is set to 1517287309.75" ) {
    mesa::clock c;
    c.time(1517287309.75);
    THEN( "the time returned should be the same" ) {
      CHECK (c.time() == doctest::Approx(1517287309.75));
    }
  }
  WHEN( "the the time is set to -1234567" ) {
    mesa::clock c;
    c.time(-1234567);
    THEN( "the time returned should be the same" ) {
      CHECK (c.time() == doctest::Approx(-1234567));
    }
  }
}


