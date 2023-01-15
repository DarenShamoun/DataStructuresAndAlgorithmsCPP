#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <string>
#include <vector>

#include <doctest.h>
#include <lab4.h>
#include "util.h"

SCENARIO( "make a vector") {

  GIVEN( "typical arrays" ) {

    WHEN( "the array has 1 element" ) {
      THEN( "it should be converted and returned in a vector" ) {
        std::vector<int> expected {3};
        const char* data[] = {"3"};
        auto actual = make_vector(1, data);
        REQUIRE( expected == actual );
      }
    }

    WHEN( "the array has 2 elements" ) {
      THEN( "they should be converted and returned in a vector" ) {
        std::vector<int> expected {3, 5};
        const char* data[] = {"3", "5"};
        auto actual = make_vector(2, data);
        REQUIRE( expected == actual );
      }
    }

    WHEN( "the array has several elements" ) {

      THEN( "they should be converted and returned in a vector" ) {
        std::vector<int> expected {3, 5, 8};
        const char* data[] = {"3", "5", "8"};
        auto actual = make_vector(3, data);
        REQUIRE( expected == actual );
      }

      AND_THEN( "they should be converted and returned in a vector" ) {
        std::vector<int> expected {-1, 0, 1, 999};
        const char* data[] = {"-1", "0", "1", "999"};
        auto actual = make_vector(4, data);
        REQUIRE( expected == actual );
      }

      AND_THEN( "an array of all '0' is valid" ) {
        std::vector<int> expected {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        const char* data[] = {"0", "0", "0", "0", "0",
                              "0", "0", "0", "0", "0"};
        auto actual = make_vector(10, data);
        REQUIRE( expected == actual );
      }

    }

  }

  GIVEN( "empty arrays" ) {

    WHEN( "argv contains nothing" ) {
      const char** data = nullptr;
      THEN( "return an empty vector" ) {
        CHECK( make_vector(0, data).empty() );
      }
    }

  }

}



