#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

struct Foo { };

SCENARIO( "Test mesa::list_iterator<T> typedefs") {

  WHEN( "mesa::list_iterator is declared with an int type" ) {
    typedef int int_type;
    mesa::list_iterator<int_type> actual;
    THEN( "the list_iterator compiles" ) {
      CHECK_MESSAGE(actual.node == actual.node, "placeholder for compilation");
    } AND_THEN ( "the 'int' typesdefs are correct" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<int>::value_type, int>() == true), 
          "expected 'value_type' to be 'int'");
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<int>::pointer, int*>() == true), 
          "expected 'pointer' to be 'int*'");
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<int>::reference, int&>() == true), 
          "expected 'reference' to be 'int&'");
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<int>::difference_type, ptrdiff_t>() == true), 
          "expected 'difference_type' to be 'ptrdiff_t'");
    }
  }

  WHEN( "mesa::list_iterator is declared with other types" ) {
    THEN ( "the value_type could be 'double'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<double>::value_type, double>() == true), 
          "expected 'value_type' to be 'double'");
    } AND_THEN ( "the value_type could be 'Foo'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<Foo>::value_type, Foo>() == true), 
          "expected 'value_type' to be 'Foo'");
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<Foo>::pointer, Foo*>() == true), 
          "expected 'pointer' to be 'Foo*'");
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<Foo>::reference, Foo&>() == true), 
          "expected 'reference' to be 'Foo&'");
      CHECK_MESSAGE( (std::is_same<mesa::list_iterator<Foo>::difference_type, ptrdiff_t>() == true), 
          "expected 'difference_type' to be 'ptrdiff_t'");
    }
  }

}

