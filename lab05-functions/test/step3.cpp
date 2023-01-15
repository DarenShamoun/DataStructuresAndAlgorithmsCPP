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

SCENARIO( "define the set function") {

  mesa::time_t actual;

  GIVEN( "a default initialized struct" ) {

    WHEN( "setting hour and minute and second" ) {
      mesa::time_t expected {3,21,34,'a',0};
      mesa::set(actual, 3,21,34);
      THEN( "there should be no errors" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the hours, minutes, and seconds should be set correctly" ) {
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
      }
      AND_THEN( "the period should default" ) {
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "setting hour and minute and second to midnight" ) {
      mesa::time_t expected {12,0,0,'a',0};
      mesa::set(actual, 12,0,0);
      THEN( "there should be no errors" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the hours, minutes, and seconds should be set correctly" ) {
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
      }
      AND_THEN( "the period should default" ) {
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "setting hour and minute and second and period" ) {
      mesa::time_t expected {8,13,21,'p',0};
      mesa::set(actual, 8,13,21,'p');
      THEN( "there should be no errors" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the hours, minutes, seconds, and period should be set correctly" ) {
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }
  }
}

SCENARIO( "using the set function to overwrite") {

  mesa::time_t actual {13,60,60,'x',15};

  GIVEN( "a time struct with values already" ) {

    WHEN( "setting hour and minute and second" ) {
      mesa::time_t expected {3,21,34,'a',0};
      mesa::set(actual, 3,21,34);
      THEN( "there should be no errors" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the hours, minutes, and seconds should be set correctly" ) {
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
      }
      AND_THEN( "the period should default" ) {
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "setting hour and minute and second and period" ) {
      mesa::time_t expected {8,13,21,'p',0};
      mesa::set(actual, 8,13,21,'p');
      THEN( "there should be no errors" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the hours, minutes, seconds, and period should be set correctly" ) {
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
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

SCENARIO( "checking error input") {
  mesa::time_t actual;

  GIVEN( "a time struct with no values yet" ) {

    WHEN( "setting an invalid hour bigger than max" ) {
      mesa::time_t expected {13,21,34,'a',mesa::ERROR_HOUR};
      mesa::set(actual, 13,21,34);
      THEN( "ERROR_HOUR should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the hours, minutes, and seconds should still get set" ) {
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
      }
      AND_THEN( "the period should default" ) {
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "setting an invalid hour smaller than min" ) {
      mesa::time_t expected {0,21,34,'a',mesa::ERROR_HOUR};
      mesa::set(actual, 0,21,34);
      THEN( "ERROR_HOUR should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the hours, minutes, and seconds should still get set" ) {
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
      }
      AND_THEN( "the period should default" ) {
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "setting an invalid minute bigger than max" ) {
      mesa::time_t expected {1,60,34,'a',mesa::ERROR_MINUTE};
      mesa::set(actual, 1,60,34);
      THEN( "ERROR_MINUTE should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
    }

    WHEN( "setting an invalid minute smaller than min" ) {
      mesa::time_t expected {2,-1,34,'a',mesa::ERROR_MINUTE};
      mesa::set(actual, 2,-1,34);
      THEN( "ERROR_MINUTE should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
    }

    WHEN( "setting an invalid second bigger than max" ) {
      mesa::time_t expected {1,6,60,'a',mesa::ERROR_SECOND};
      mesa::set(actual, 1,6,60);
      THEN( "ERROR_SECOND should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
    }

    WHEN( "setting an invalid second smaller than min" ) {
      mesa::time_t expected {2,1,-1,'a',mesa::ERROR_SECOND};
      mesa::set(actual, 2,1,-1);
      THEN( "ERROR_SECOND should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
    }

    WHEN( "period is upper case A" ) {
      mesa::time_t expected {1,6,5,'A',mesa::ERROR_PERIOD};
      mesa::set(actual, 1,6,5,'A');
      THEN( "ERROR_PERIOD should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the period should still get set" ) {
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "period is upper case P" ) {
      mesa::time_t expected {1,6,5,'P',mesa::ERROR_PERIOD};
      mesa::set(actual, 1,6,5,'P');
      THEN( "ERROR_PERIOD should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the period should still get set" ) {
        CHECK( expected.period == actual.period );
      }
    }

    WHEN( "period is not a valid character" ) {
      mesa::time_t expected {1,6,5,'x',mesa::ERROR_PERIOD};
      mesa::set(actual, 1,6,5,'x');
      THEN( "ERROR_PERIOD should be set" ) {
        CHECK( expected.errors == actual.errors );
      }
      AND_THEN( "the period should still get set" ) {
        CHECK( expected.period == actual.period );
      }
    }

  }
}

SCENARIO( "set handles multiple errors") {
  mesa::time_t actual; // {13,60,60,'x',15};

    WHEN( "setting an invalid hour and minute" ) {
      mesa::time_t expected {-1,-1,34,'a',mesa::ERROR_HOUR+mesa::ERROR_MINUTE};
      mesa::set(actual, -1,-1,34);
      THEN( "both hour and minute error bits should be set" ) {
        CHECK( expected.errors == actual.errors );
        CHECK( mesa::ERROR_HOUR == (mesa::ERROR_HOUR & actual.errors) );
        CHECK( mesa::ERROR_MINUTE == (mesa::ERROR_MINUTE & actual.errors) );
      }
    }

    WHEN( "setting an invalid hour and second" ) {
      mesa::time_t expected {-1,59,60,'a',mesa::ERROR_HOUR+mesa::ERROR_SECOND};
      mesa::set(actual, -1,59,60);
      THEN( "both hour and second error bits should be set" ) {
        CHECK( expected.errors == actual.errors );
        CHECK( mesa::ERROR_HOUR == (mesa::ERROR_HOUR & actual.errors) );
        CHECK( mesa::ERROR_SECOND == (mesa::ERROR_SECOND & actual.errors) );
      }
    }

    WHEN( "setting an invalid hour and period" ) {
      mesa::time_t expected {-1,59,59,'\0',mesa::ERROR_HOUR+mesa::ERROR_PERIOD};
      mesa::set(actual, -1,59,59, 0);
      THEN( "both hour and period error bits should be set" ) {
        CHECK( expected.errors == actual.errors );
        CHECK( mesa::ERROR_HOUR == (mesa::ERROR_HOUR & actual.errors) );
        CHECK( mesa::ERROR_PERIOD == (mesa::ERROR_PERIOD & actual.errors) );
      }
    }

    WHEN( "setting an invalid minute and second" ) {
      mesa::time_t expected {1,60,60,'p',mesa::ERROR_MINUTE+mesa::ERROR_SECOND};
      mesa::set(actual, 1,60,60,'p');
      THEN( "both minute and second error bits should be set" ) {
        CHECK( expected.errors == actual.errors );
        CHECK( mesa::ERROR_MINUTE == (mesa::ERROR_MINUTE & actual.errors) );
        CHECK( mesa::ERROR_SECOND == (mesa::ERROR_SECOND & actual.errors) );
      }
    }

    WHEN( "all inputs are invalid" ) {
      mesa::time_t expected {13,60,60,'x',15};
      mesa::set(actual, 13,60,60,'x');
      THEN( "all error bits should be set" ) {
        CHECK( expected.errors == actual.errors );
        CHECK( mesa::ERROR_HOUR == (mesa::ERROR_HOUR & actual.errors) );
        CHECK( mesa::ERROR_MINUTE == (mesa::ERROR_MINUTE & actual.errors) );
        CHECK( mesa::ERROR_SECOND == (mesa::ERROR_SECOND & actual.errors) );
        CHECK( mesa::ERROR_PERIOD == (mesa::ERROR_PERIOD & actual.errors) );
      }
      AND_THEN( "the hours, minutes, and seconds should still get set" ) {
        CHECK( expected.hours == actual.hours );
        CHECK( expected.minutes == actual.minutes );
        CHECK( expected.seconds == actual.seconds );
        CHECK( expected.period == actual.period );
      }
    }
}

