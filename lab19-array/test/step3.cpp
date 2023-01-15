#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "Test mesa::array<T,N> size") {
  size_t expected = 3;

  WHEN( "mesa::array is declared with a size" ) {
    THEN ("size matches non-type parameter value") {
      mesa::array<int, 3> actual;
      CHECK(actual.size() == expected);
    }
    THEN ("size matches non-type parameter value") {
      expected = 5;
      mesa::array<int32_t, 5> actual;
      CHECK(actual.size() == expected);
    }
    THEN ("size matches non-type parameter value") {
      expected = 8;
      mesa::array<size_t, 8> actual;
      CHECK(actual.size() == expected);
    }
    THEN ("size matches non-type parameter value") {
      expected = 13;
      mesa::array<double, 13> actual;
      CHECK(actual.size() == expected);
    }
  }

}


