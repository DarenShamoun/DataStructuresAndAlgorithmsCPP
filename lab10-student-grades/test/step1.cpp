#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <average.h>

#include <vector>

SCENARIO( "Compute average") {

  GIVEN( "a vector of int values" ) {
    WHEN( "the vector = {1,2,3}" ) {
      THEN( "the average should be 2" ) {
        REQUIRE(average({1,2,3}) == 2);
      }
    }
    WHEN( "the vector = {100, 99, 88, 77, 83, 80}" ) {
      THEN( "the average should be 87.83" ) {
        REQUIRE(doctest::Approx(
                  average({100, 99, 88, 77, 83, 80})
                ).epsilon(0.01) == 87.83);
      }
    }
    WHEN( "the vector = {4,4,4,4,4,4,4,4,3,3,3,3}" ) {
      THEN( "the average should be 3.66" ) {
        REQUIRE(doctest::Approx(
                  average({4,4,4,4,4,4,4,4,3,3,3,3})
                ).epsilon(0.01) == 3.66);
      }
    }
    WHEN( "the vector = {-2,-1,0,6,9,5,-3,13,5,8}" ) {
      THEN( "the average should be 4" ) {
        REQUIRE(doctest::Approx(
                  average({-2,-1,0,6,9,5,-3,13,5,8})
                ).epsilon(0.01) == 4);
      }
    }
    WHEN( "the vector = {1,1,3,5,8,13,21,34,55,89}" ) {
      THEN( "the average should be 23" ) {
        REQUIRE(doctest::Approx(
                  average({1,1,3,5,8,13,21,34,55,89})
                ).epsilon(0.01) == 23);
      }
    }
  }
}


SCENARIO( "Function average error cases") {

  WHEN( "an emtpy vector is passed to average" ) {
    std::vector<int> empty;
    THEN( "the average should be 0" ) {
      REQUIRE(average(empty) == 0);
    }
  }

}


