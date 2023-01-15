#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <string>

#include <doctest.h>
#include <lab5.h>

SCENARIO( "display time values") {

  std::ostringstream actual;
  mesa::time_t time_value;

  GIVEN( "a valid time struct" ) {

    WHEN( "setting hour and minute and second" ) {
      auto expected = std::string("3:21:34 AM");
      mesa::set(time_value, 3,21,34);
      THEN( "the display function should print valid values as AM" ) {
        mesa::display(actual, time_value);
        CHECK( expected == actual.str() );
      }
    }

    WHEN( "setting h,m,s and period" ) {
      auto expected = std::string("11:34:59 PM");
      mesa::set(time_value, 11,34,59, 'p');
      THEN( "the display function should print the values as PM" ) {
        mesa::display(actual, time_value);
        CHECK( expected == actual.str() );
      }
    }

  }

  GIVEN( "an invalid time struct" ) {

    WHEN( "setting invalid hour" ) {
      auto expected = std::string("-1:21:34 AM[1]");
      mesa::set(time_value, -1,21,34);
      THEN( "the display function should print the error hour error code" ) {
        mesa::display(actual, time_value);
        CHECK( expected == actual.str() );
      }
    }

    WHEN( "setting invalid minute" ) {
      auto expected = std::string("1:-21:34 PM[2]");
      mesa::set(time_value, 1,-21,34,'p');
      THEN( "the display function should print the error minute error code" ) {
        mesa::display(actual, time_value);
        CHECK( expected == actual.str() );
      }
    }

    WHEN( "setting invalid seconds" ) {
      auto expected = std::string("1:21:-34 PM[4]");
      mesa::set(time_value, 1,21,-34,'p');
      THEN( "the display function should print the error second error code" ) {
        mesa::display(actual, time_value);
        CHECK( expected == actual.str() );
      }
    }

    WHEN( "setting invalid period" ) {
      auto expected = std::string("1:21:34 x[8]");
      mesa::set(time_value, 1,21,34,'x');
      THEN( "the display function should print the error period error code" ) {
        mesa::display(actual, time_value);
        CHECK( expected == actual.str() );
      }
    }

    WHEN( "setting invalid hour and minute and second" ) {
      auto expected = std::string("0:60:99 AM[7]");
      mesa::set(time_value, 0,60,99);
      THEN( "the display function should print error code 7" ) {
        mesa::display(actual, time_value);
        CHECK( expected == actual.str() );
      }
    }

    WHEN( "setting everything invalid" ) {
      auto expected = std::string("0:60:99 q[15]");
      mesa::set(time_value, 0,60,99,'q');
      THEN( "the display function should print error code 15" ) {
        mesa::display(actual, time_value);
        CHECK( expected == actual.str() );
      }
    }

  }
}

