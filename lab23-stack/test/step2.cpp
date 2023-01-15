#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/bag.h"
#include "../src/stack.h"


SCENARIO( "Test mesa::stack value types exist" ) {

  WHEN( "mesa::stack is declared with an int type" ) {
    typedef int int_type;
    mesa::stack<int_type> actual;
    THEN( "the stack compiles" ) {
      CHECK_MESSAGE(&actual == &actual, "placeholder for compilation");
    } AND_THEN ( "the value_type is 'int'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::stack<int>::value_type, int>() == true), 
          "expected 'value_type' to be 'int'");
      CHECK_MESSAGE( (std::is_same<mesa::bag<int>, mesa::stack<int>::container_type>() == true), 
          "expected 'container_type' to be 'bag<int>'");
    }
  }

  WHEN( "mesa::array is declared with other types" ) {
    THEN ( "the value_type should match" ) {
      CHECK_MESSAGE( (std::is_same<mesa::bag<double>::value_type, double>() == true), 
          "expected 'value_type' to be 'double'");
      CHECK_MESSAGE( (std::is_same<mesa::bag<char>::value_type, char>() == true), 
          "expected 'value_type' to be 'char'");
      // CHECK_MESSAGE( (std::is_same<mesa::bag<double>, mesa::stack<double>::container_type>() == true), 
      //     "expected 'container_type' to be 'bag<double>'");
      // CHECK_MESSAGE( (std::is_same<mesa::bag<char>, mesa::stack<char>::container_type>() == true), 
      //     "expected 'container_type' to be 'bag<char>'");
    }
  }


}


