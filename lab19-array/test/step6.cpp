#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>
#include <utility>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "Test mesa::array<T,N> initializer list constructor" ) {

  WHEN( "mesa::array is explicitly constructed from a list" ) {
    auto actual = mesa::array<int,3> {1,2,3};
    auto expected = std::vector<int> {1,2,3};
    THEN ("all int elements should match list") {
      for (int i = 0; i < int(expected.size()); ++i) {
        CHECK(*(actual.begin()+i) == expected[i]);
      }
    }
  }

  WHEN( "mesa::array of size_t is explicitly constructed from a list" ) {
    auto actual = mesa::array<size_t,8> {21,13,8,5,3,2,1,1};
    auto expected = std::vector<size_t> {21,13,8,5,3,2,1,1};
    THEN ("all int elements should match list") {
      for (int i = 0; i < int(expected.size()); ++i) {
        CHECK(*(actual.begin()+i) == expected[i]);
      }
    }
  }

}

