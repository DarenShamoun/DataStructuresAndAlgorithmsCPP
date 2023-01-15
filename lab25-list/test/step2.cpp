#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test mesa::list<T>") {

  WHEN( "mesa::list is declared with an int type" ) {
    typedef int int_type;
    mesa::list<int_type> actual;
    THEN( "the list compiles" ) {
      CHECK_MESSAGE(&actual == &actual, "placeholder for compilation");
    } AND_THEN ( "the value_type is 'int'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list<int>::value_type, int>() == true), 
          "expected 'value_type' to be 'int'");
    }
  }

  WHEN( "mesa::list is declared with other types" ) {
    THEN ( "the value_type could be 'double'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list<double>::value_type, double>() == true), 
          "expected 'value_type' to be 'double'");
    } AND_THEN ( "the value_type could be 'char'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list<char>::value_type, char>() == true), 
          "expected 'value_type' to be 'char'");
    }
  }

}
