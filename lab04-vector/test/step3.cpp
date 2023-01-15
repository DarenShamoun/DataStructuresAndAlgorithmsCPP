#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include <doctest.h>
#include <lab4.h>
#include "util.h"

SCENARIO( "add elements") {

  GIVEN( "typical arrays" ) {

    WHEN( "the array has 1 element" ) {
      THEN( "the sum should be equal to the value provided" ) {
        int expected = 21;
        const char* data[] = {"21"};
        auto actual = add(1, data);
        CHECK( expected == actual );
      }
    }

    WHEN( "the array has 2 elements" ) {
      THEN( "the sum should be returned" ) {
        int expected = 8;
        const char* data[] = {"3", "5"};
        auto actual = add(2, data);
        CHECK( expected == actual );
      }
    }

    WHEN( "the array has several elements" ) {

      THEN( "the sum should be returned" ) {
        int expected = 232;
        const char* data[] = {"1", "1", "2", "3", "5",
                              "8", "13", "21", "34", "55", "89"};
        auto actual = add(11, data);
        REQUIRE( expected == actual );
      }

      AND_THEN( "the sum should be returned" ) {
        int expected = 55;
        const char* data[] = {"1", "2", "3", "4", "5",
                              "6", "7", "8", "9", "10"};
        auto actual = add(10, data);
        CHECK( expected == actual );
      }


      AND_THEN( "the sum should be returned" ) {
        int expected = 0;
        const char* data[] = {"-1", "0", "1"};
        auto actual = add(3, data);
        CHECK( expected == actual );
      }

      AND_THEN( "the sum should be returned" ) {
        int expected = 101663;
        const char* data[] = {"92172", "21", "8236", "01234"};
        auto actual = add(4, data);
        CHECK( expected == actual );
      }

      AND_THEN( "an array of all '0' is valid" ) {
        int expected = 0;
        const char* data[] = {"0", "0", "0", "0", "0",
                              "0", "0", "0", "0", "0"};
        auto actual = add(10, data);
        CHECK( expected == actual );
      }

      AND_THEN( "an array of all '4' is valid" ) {
        int expected = 40;
        const char* data[] = {"4", "4", "4", "4", "4",
                              "4", "4", "4", "4", "4"};
        auto actual = add(10, data);
        CHECK( expected == actual );
      }

    }

  }

  GIVEN( "empty arrays" ) {

    WHEN( "argv contains nothing" ) {
      const char** data = nullptr;
      int expected = 0;
      THEN( "return a zero" ) {
        CHECK( expected == add(0, data) );
      }
    }

  }

}



