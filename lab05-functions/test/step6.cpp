#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <lab5.h>

SCENARIO( "convert jiffies to time") {

  mesa::time_t expected;

  GIVEN( "a valid time struct" ) {

    WHEN( "converting an hour of jiffies" ) {
      auto jiffies = mesa::HZ * 3600;
      mesa::set(expected, 1,0,0);
      THEN( "the time is 1 am" ) {
        auto actual = mesa::jiffies_to_time(jiffies);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "converting 13 hours of jiffies" ) {
      auto jiffies = mesa::HZ * 13 *  3600;
      mesa::set(expected, 1,0,0,'p');
      THEN( "the time is 1 pm" ) {
        auto actual = mesa::jiffies_to_time(jiffies);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "converting 12094 seconds worth of jiffies" ) {
      auto jiffies = mesa::HZ * 12094;
      mesa::set(expected, 3,21,34);
      THEN( "the time is 3:21:34 am" ) {
        auto actual = mesa::jiffies_to_time(jiffies);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "converting 48094 seconds worth of jiffies" ) {
      auto jiffies = mesa::HZ * 48094;
      mesa::set(expected, 1,21,34,'p');
      THEN( "the time is 1:21:34 pm" ) {
        auto actual = mesa::jiffies_to_time(jiffies);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "converting 86399 seconds worth of jiffies" ) {
      auto jiffies = mesa::HZ * 86399;
      mesa::set(expected, 11,59,59,'p');
      THEN( "the time is 11:59:59 pm" ) {
        auto actual = mesa::jiffies_to_time(jiffies);
        CHECK( expected.errors == actual.errors );
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }

  }

}

