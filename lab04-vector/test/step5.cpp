#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include <doctest.h>
#include <lab4.h>
#include "util.h"

SCENARIO( "return a vector of odd elements") {

  GIVEN( "typical vectors" ) {

    WHEN( "the vector has 1 odd element" ) {
      THEN( "the vector should be equal to the vector provided" ) {
        std::vector<int> expected = {21};
        std::vector<int> data = {21};
        auto actual = odd(data);
        CHECK( expected == actual );
      }
    }

    WHEN( "the vector has several elements" ) {

      THEN( "the odd elements should be returned" ) {
        std::vector<int> expected = {1,3,5};
        std::vector<int> data = {1,2,3,4,5};
        auto actual = odd(data);
        REQUIRE( expected == actual );
      }

      AND_THEN( "the odd elements should be returned" ) {
        std::vector<int> expected = {1,1,3,5,13,21,55,89};
        std::vector<int> data = {1,1,3,5,8,13,21,34,55,89};
        auto actual = odd(data);
        CHECK( expected == actual );
      }

      AND_THEN( "the odd elements should be returned" ) {
        std::vector<int> expected {21};
        std::vector<int> data = {92172,21,8236,1234};
        auto actual = odd(data);
        CHECK( expected == actual );
      }

      AND_THEN( "the odd elements should be returned" ) {
        std::vector<int> expected = {9,1,3,5,7,9};
        std::vector<int> data = {9,1,2,3,4,5,6,7,8,9,10};
        auto actual = odd(data);
        CHECK( expected == actual );
      }

      AND_THEN( "an vector of all '4' is valid, but empty" ) {
        std::vector<int> expected;
        std::vector<int> data = {4,4,4,4,4,4,4,4,4,4,4};
        auto actual = odd(data);
        CHECK( expected == actual );
      }

    }

  }

  GIVEN( "empty vector" ) {

    WHEN( "value contains nothing" ) {
      std::vector<int> expected;
      THEN( "return an empty vector" ) {
        CHECK( expected == odd(expected) );
      }
    }

  }

}



