#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iterator>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "function data() returns an array pointer" ) {

  WHEN( "mesa::array is declared" ) {
    THEN ("data returns a pointer to the first element") {
      mesa::array<int, 5> actual;
      CHECK(actual.data()+actual.size() == actual.end());
    }
  }

  WHEN( "mesa::array is declared" ) {
    THEN ("the std::distance between begin and end should equal the size") {
      mesa::array<int, 13> actual;
      CHECK(std::distance(actual.data(), actual.end()) == actual.size());
    }
  }

}

SCENARIO( "function back() returns a reference" ) {

  WHEN( "mesa::array is declared" ) {
    mesa::array<int, 5> actual {5,8,13,21,34};
    THEN ( "back is a reference to the last element" ) {
      CHECK(actual.back() == 34);
      CHECK(&(actual.back()) == &(actual.data()[4]));
    }
  }

  WHEN( "a const mesa::array is declared" ) {
    const mesa::array<int, 5> actual {5,8,13,21,34};
    THEN ( "back is a reference to the last element" ) {
      CHECK(actual.back() == 34);
      CHECK(&(actual.back()) == &(actual.data()[4]));
    }
  }

}

