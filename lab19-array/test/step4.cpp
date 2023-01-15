#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iterator>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "Test mesa::array<T,N> begin and end") {

  WHEN( "mesa::array is declared with a size 3" ) {
    THEN ("end should return a value 3 positions past begin") {
      mesa::array<int, 3> actual;
      CHECK(actual.begin()+actual.size() == actual.end());
    }
  }

  WHEN( "mesa::array is declared with a size 13" ) {
    THEN ("the std::distance between begin and end should equal the size") {
      mesa::array<int, 13> actual;
      CHECK(std::distance(actual.begin(), actual.end()) == actual.size());
    }
  }

}

SCENARIO( "Test const versions of begin and end") {

  WHEN( "mesa::array is declared with a size 3" ) {
    THEN ("end should return a value 3 positions past begin") {
      const mesa::array<int, 3> actual;
      CHECK(actual.begin()+actual.size() == actual.end());
    }
  }

  WHEN( "mesa::array is declared with a size 13" ) {
    THEN ("the std::distance between begin and end should equal the size") {
      const mesa::array<int, 13> actual;
      CHECK(std::distance(actual.begin(), actual.end()) == actual.size());
    }
  }

}

