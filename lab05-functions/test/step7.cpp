#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <lab5.h>

SCENARIO( "advance time within a single day") {

  mesa::time_t actual;
  mesa::time_t expected;

  GIVEN( "a valid time struct" ) {

    WHEN( "advancing 1am by 1 hour" ) {
      mesa::set(actual, 1,0,0);
      mesa::set(expected, 2,0,0);
      THEN( "the time becomes 2 am" ) {
        mesa::advance(actual, 1);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "advancing 1am by 10 hours, 59min, 59sec" ) {
      mesa::set(actual, 1,0,0);
      mesa::set(expected, 11,59,59);
      THEN( "the time becomes 1 minute before noon" ) {
        mesa::advance(actual, 10, 59, 59);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "advancing 1am by 11 hours" ) {
      mesa::set(actual, 1,0,0);
      mesa::set(expected, 12,0,0,'p');
      THEN( "the time becomes noon" ) {
        mesa::advance(actual, 11);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "advancing 2:01am by 59 minutes" ) {
      mesa::set(actual, 2,1,0);
      mesa::set(expected, 3,0,0);
      THEN( "the time becomes 3am" ) {
        mesa::advance(actual, 0,59);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "advancing 3:59:01am by 59 seconds" ) {
      mesa::set(actual, 3,59,1);
      mesa::set(expected, 4,0,0);
      THEN( "the time becomes 4am" ) {
        mesa::advance(actual, 0,0,59);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "advancing midnight by 12 hours" ) {
      mesa::set(actual, 12,0,0);
      mesa::set(expected, 12,0,0,'p');
      THEN( "the time becomes noon" ) {
        mesa::advance(actual, 12);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "advancing midnight by 15.5 hours" ) {
      mesa::set(actual, 12,0,0);
      mesa::set(expected, 3,30,0,'p');
      THEN( "the time becomes 3:30pm" ) {
        mesa::advance(actual, 15, 30);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

  }

}

SCENARIO( "advance time wrapping to next day") {

  mesa::time_t actual;
  mesa::time_t expected;

  GIVEN( "a valid time struct" ) {

    WHEN( "advancing midnight by 27.5 hours" ) {
      mesa::set(actual, 12,0,0);
      mesa::set(expected, 3,30,0,'a');
      THEN( "the time becomes 3:30am (next day)" ) {
        mesa::advance(actual, 27, 30);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "advancing 10am by 15:30:30" ) {
      mesa::set(actual, 10,0,0);
      mesa::set(expected, 1,30,30,'a');
      THEN( "the time becomes 1:30:30am (next day)" ) {
        mesa::advance(actual, 15, 30,30);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

  }

}

