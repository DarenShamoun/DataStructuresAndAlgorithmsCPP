#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iterator>
#include <vector>

#include <doctest.h>
#include <lab9.h>

SCENARIO( "return a pointer to the smallest element in a range") {

  GIVEN( "a list of values {1,4,1,5,9,2,6}" ) {
    std::vector<int> v{1,4,1,5,9,2,6};

    WHEN( "the first element is smallest" ) {
      std::vector<int>::iterator actual = mesa::min(v.begin(), v.end());
      THEN("min should return the first '1'" ) {
        auto actual_index = std::distance(v.begin(), actual);
        auto expected_index = std::distance(v.begin(), v.begin());
        REQUIRE(actual_index == expected_index);
        REQUIRE(*actual == 1);
      }
    }

    WHEN( "the last element is smallest" ) {
      std::vector<int>::iterator actual = mesa::min(v.begin()+3, v.end()-1);
      THEN("min should return the '2'" ) {
        auto actual_index = std::distance(v.begin()+3, actual);
        auto expected_index = std::distance(v.begin()+3, v.end()-2);
        REQUIRE(actual_index == expected_index);
        REQUIRE(*actual == 2);
      }
    }

    WHEN( "there is only 1 element in the range" ) {
      std::vector<int>::iterator actual = mesa::min(v.begin()+1, v.begin()+2);
      THEN("min should return it (a 4 in this case)" ) {
        auto actual_index = std::distance(v.begin()+1, actual);
        auto expected_index = std::distance(v.begin()+1, v.begin()+1);
        REQUIRE(actual_index == expected_index);
        REQUIRE(*actual == 4);
      }
    }

  }

  GIVEN( "an array of values {2,7,1,-8,2,-8,1,8,2,-8}" ) {
    int v[] = {2,7,1,-8,2,-8,1,8,2,-8};
    WHEN( "there is more than 1 element in the range" ) {
      int* actual = mesa::min(std::begin(v), std::end(v));
      THEN("min should return the first (the -8 at position 4)" ) {
        auto actual_index = std::distance(std::begin(v), actual);
        auto expected_index = std::distance(std::begin(v), std::begin(v)+3);
        REQUIRE(actual_index == expected_index);
        REQUIRE(*actual == -8);
      }
    }


  }
}

SCENARIO( "Compute the invariants of min") {

  GIVEN( "an empty range" ) {
    WHEN( "the end pointer equals the begin pointer" ) {
      std::vector<int> empty;
      THEN("the end pointer is returned" ) {
        auto actual = mesa::min(empty.begin(), empty.end());
        REQUIRE(actual == empty.end());
      }
    }
  }
}




