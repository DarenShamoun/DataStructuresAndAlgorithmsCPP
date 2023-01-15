#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <utility>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "Test mesa::array<T,N> empty" ) {

  WHEN( "mesa::array has non-zero size" ) {
    mesa::array<int,3> actual;
    THEN ("empty should return false") {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == 3);
    }
  }

  WHEN( "mesa::array has non-zero size and non-integral type" ) {
    mesa::array<std::pair<int,int>,3> actual;
    THEN ("empty should return false") {
      CHECK(actual.empty() == false);
      CHECK(actual.size() == 3);
    }
  }

  WHEN( "mesa::array has zero size" ) {
    mesa::array<int,0> actual;
    THEN ("empty should return true") {
      CHECK(actual.empty() == true);
      CHECK(actual.size() == 0);
    }
  }

    WHEN( "mesa::array has zero size and non-numeric type" ) {
    mesa::array<std::pair<int,int>,0> actual;
    THEN ("empty should return true") {
      CHECK(actual.empty() == true);
      CHECK(actual.size() == 0);
    }
  }
}

