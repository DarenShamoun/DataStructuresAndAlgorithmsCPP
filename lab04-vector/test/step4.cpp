#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include <doctest.h>
#include <lab4.h>
#include "util.h"

SCENARIO( "compute the average of elements") {

  GIVEN( "typical arrays" ) {

    WHEN( "the array has 1 element" ) {
      THEN( "the mean should be equal to the value provided" ) {
        double expected = 21;
        const char* data[] = {"21"};
        auto actual = mean(1, data);
        CHECK( expected == actual );
      }
    }

    WHEN( "the array has 2 elements" ) {
      THEN( "the mean should be returned" ) {
        double expected = 3.5;
        const char* data[] = {"1", "2", "3", "4,", "5", "6"};
        auto actual = mean(6, data);
        CHECK( expected == doctest::Approx(actual) );
      }
    }

    WHEN( "the array has several elements" ) {

      THEN( "the mean should be returned" ) {
        double expected = 21.0909;
        const char* data[] = {"1", "1", "2", "3", "5",
                              "8", "13", "21", "34", "55", "89"};
        auto actual = mean(11, data);
        REQUIRE( expected == doctest::Approx(actual) );
      }

      AND_THEN( "the mean should be returned" ) {
        double expected = 5;
        const char* data[] = {"1", "2", "3", "4", "5",
                              "6", "7", "8", "9"};
        auto actual = mean(9, data);
        CHECK( expected == actual );
      }


      AND_THEN( "the mean should be returned" ) {
        double expected = 0;
        const char* data[] = {"-1", "0", "1"};
        auto actual = mean(3, data);
        CHECK( expected == actual );
      }

      AND_THEN( "the mean should be returned" ) {
        double expected = 25415.8;
        const char* data[] = {"92172", "21", "8236", "01234"};
        auto actual = mean(4, data);
        REQUIRE( expected == doctest::Approx(actual) );
      }

      AND_THEN( "an array of all '0' is valid" ) {
        double expected = 0;
        const char* data[] = {"0", "0", "0", "0", "0",
                              "0", "0", "0", "0", "0"};
        auto actual = mean(10, data);
        CHECK( expected == actual );
      }

      AND_THEN( "an array of all '4' is valid" ) {
        double expected = 4;
        const char* data[] = {"4", "4", "4", "4", "4",
                              "4", "4", "4", "4", "4"};
        auto actual = mean(10, data);
        CHECK( expected == actual );
      }

    }

  }

  GIVEN( "empty arrays" ) {

    WHEN( "argv contains nothing" ) {
      const char** data = nullptr;
      double expected = 0;
      THEN( "return a zero" ) {
        CHECK( expected == mean(0, data) );
      }
    }

  }

}



