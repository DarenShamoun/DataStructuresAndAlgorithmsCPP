#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>
#include <string>
#include <sstream>
#include <vector>

#include <doctest.h>
#include "../src/binary_heap.h"

SCENARIO( "Test mesa::binary_heap<T> compiles") {

  WHEN( "mesa::binary_heap is declared with an int type" ) {
    typedef int int_type;
    mesa::binary_heap<int_type> actual;
    THEN( "the binary_heap compiles" ) {
      CHECK_MESSAGE(&actual == &actual, "placeholder for compilation");
    } AND_THEN ( "the value_type is 'int'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::binary_heap<int>::value_type, int>() == true), 
          "expected 'value_type' to be 'int'");
    }
  }

  WHEN( "mesa::binary_heap is declared with other types" ) {
    THEN ( "the value_type could be 'double'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::binary_heap<double>::value_type, double>() == true), 
          "expected 'value_type' to be 'double'");
    } AND_THEN ( "the value_type could be 'char'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::binary_heap<char>::value_type, char>() == true), 
          "expected 'value_type' to be 'char'");
    }
  }

}

SCENARIO( "Test mesa::binary_heap<T> constructor") {

  WHEN( "mesa::binary_heap is constructed with a small vector" ) {
    std::vector<int> v = {1,8,5};
    mesa::binary_heap<int> h{v};
    THEN( "the binary_heap is constructed as expected" ) {
      std::string value = "0 1 8 5 ";
      std::ostringstream actual (value);
      std::ostringstream expected;
      expected << h;
      CHECK(expected.str() == actual.str());
    }
  }

  WHEN( "mesa::binary_heap is constructed with a typical vector" ) {
    std::vector<int> v = {14,19,16,19,8,21,26,65,32,31,14};
    mesa::binary_heap<int> h{v};
    THEN( "the binary_heap is constructed as expected" ) {
      std::string value = "0 8 14 16 19 14 21 26 65 32 31 19 ";
      std::ostringstream actual (value);
      std::ostringstream expected;
      expected << h;
      CHECK(expected.str() == actual.str());
    }
  }

  WHEN( "constructed with an empty vector" ) {
    std::vector<int> v;
    mesa::binary_heap<int> h{v};
    THEN( "the binary_heap is constructed as expected" ) {
      std::string value = "0 ";
      std::ostringstream actual (value);
      std::ostringstream expected;
      expected << h;
      CHECK(expected.str() == actual.str());
    }
  }

}
