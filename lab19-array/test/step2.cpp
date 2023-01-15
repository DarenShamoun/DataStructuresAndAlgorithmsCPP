#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "Test mesa::array<T,N>") {

  WHEN( "mesa::array is declared with an int type" ) {
    typedef int int_type;
    mesa::array<int_type, 3> actual;
    THEN( "the array compiles" ) {
      CHECK_MESSAGE(&actual == &actual, "placeholder for compilation");
    } AND_THEN ( "the value_type is 'int'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::array<int,1>::value_type, int>() == true), 
          "expected 'value_type' to be 'int'");
    }
  }

  WHEN( "mesa::array is declared with other types" ) {
    THEN ( "the value_type could be 'double'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::array<double,1>::value_type, double>() == true), 
          "expected 'value_type' to be 'double'");
    } AND_THEN ( "the value_type could be 'char'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::array<char,1>::value_type, char>() == true), 
          "expected 'value_type' to be 'char'");
    }
  }

}
