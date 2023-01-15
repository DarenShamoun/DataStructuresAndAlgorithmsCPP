#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <lab5.h>

static
bool operator== (const mesa::time_t& lhs, const mesa::time_t& rhs) {
  return lhs.errors == rhs.errors
      && lhs.hours == rhs.hours
      && lhs.minutes == rhs.minutes
      && lhs.seconds == rhs.seconds
      && lhs.period == rhs.period;
}

SCENARIO( "define the time struct") {

  mesa::time_t actual;

  GIVEN( "default initialization" ) {

    WHEN( "setting values directly" ) {
      THEN( "the lab defined names should be used" ) {
        mesa::time_t expected {3,21,34,'a',0};
        actual.hours = 3;
        actual.minutes = 21;
        actual.seconds = 34;
        actual.period = 'a';
        actual.errors = 0;
        REQUIRE( expected.errors == actual.errors );
        REQUIRE( expected.hours == actual.hours );
        REQUIRE( expected.minutes == actual.minutes );
        REQUIRE( expected.seconds == actual.seconds );
        REQUIRE( expected.period == actual.period );
      }
    }
  }
}

SCENARIO( "define the time error constants") {
  GIVEN( "default initialization" ) {
    THEN( "the lab defined constants should exist" ) {
      REQUIRE( mesa::ERROR_HOUR == 1 );
      REQUIRE( mesa::ERROR_MINUTE == 2 );
      REQUIRE( mesa::ERROR_SECOND == 4 );
      REQUIRE( mesa::ERROR_PERIOD == 8 );
    }
  }
}


