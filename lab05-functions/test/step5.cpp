#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <lab5.h>

SCENARIO( "convert time to jiffies") {

  mesa::time_t time_value;

  GIVEN( "a valid time struct" ) {

    WHEN( "converting 1 am" ) {
      auto expected = mesa::HZ * 3600;
      mesa::set(time_value, 1,0,0);
      THEN( "the jiffies == an hours worth of ticks" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( expected == actual );
      }
    }

    WHEN( "converting 1 pm" ) {
      auto expected = mesa::HZ * 13*3600;
      mesa::set(time_value, 1,0,0,'p');
      THEN( "the jiffies need to add 12 hours to the ticks" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( expected == actual );
      }
    }

    WHEN( "converting midnight" ) {
      auto expected = 0;
      mesa::set(time_value, 12,0,0);
      THEN( "the jiffies == no ticks" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( expected == actual );
      }
    }

    WHEN( "converting noon" ) {
      auto expected = mesa::HZ * 43200;
      mesa::set(time_value, 12,0,0,'p');
      THEN( "the jiffies == no ticks" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( expected == actual );
      }
    }

    WHEN( "converting 3:21:34 pm" ) {
      auto expected = mesa::HZ * 12094;
      mesa::set(time_value, 3,21,34);
      THEN( "the jiffies need to add hours,min, and secs" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( expected == actual );
      }
    }

    WHEN( "converting 1:21:34 pm" ) {
      auto expected = mesa::HZ * 48094;
      mesa::set(time_value, 1,21,34,'p');
      THEN( "the jiffies need to add hours,min, and secs AND add 12 hours" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( expected == actual );
      }
    }

    WHEN( "converting 11:59:59 pm" ) {
      auto expected = mesa::HZ * 86399;
      mesa::set(time_value, 11,59,59,'p');
      THEN( "the jiffies need to add hours,min, and secs AND add 12 hours" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( expected == actual );
      }
    }

  }

  GIVEN( "an invalid time struct" ) {

    WHEN( "converting an invalid hour" ) {
      mesa::set(time_value, 0,59,59,'p');
      THEN( "the time_to_jiffies function should return 0" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( 0 == actual );
      }
    }

    WHEN( "converting an invalid minute" ) {
      mesa::set(time_value, 1,-1,59);
      THEN( "the time_to_jiffies function should return 0" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( 0 == actual );
      }
    }

    WHEN( "converting an invalid second" ) {
      mesa::set(time_value, 1,1,60,'p');
      THEN( "the time_to_jiffies function should return 0" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( 0 == actual );
      }
    }

    WHEN( "converting an invalid period" ) {
      mesa::set(time_value, 1,1,1,'x');
      THEN( "the time_to_jiffies function should return 0" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( 0 == actual );
      }
    }

    WHEN( "converting an invalid struct - all invalid" ) {
      mesa::set(time_value, 0,60,60,'x');
      THEN( "the time_to_jiffies function should return 0" ) {
        auto actual = mesa::time_to_jiffies(time_value);
        CHECK( 0 == actual );
      }
    }

  }
}

