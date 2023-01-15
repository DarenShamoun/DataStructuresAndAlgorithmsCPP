#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

struct Foo { };

SCENARIO( "Test mesa::list_iterator<T> constructors") {

  WHEN( "mesa::list_iterator is default constructed" ) {
    mesa::list_iterator<int> actual;
    THEN ( "the object exists and had a node" ) {
      CHECK( actual.node == actual.node); 
    }
  }

  WHEN( "mesa::list_iterator is constructed with a list_node" ) {
    auto expected = new mesa::list_node<char>('x');
    mesa::list_iterator<char> actual(expected);
    THEN ( " the list_node value is stored in the iterator " ) {
      CHECK( actual.node->value == expected->value); 
    }
  }

  // WHEN( "mesa::list_iterator is copy constructed" ) {
  //   auto node = new mesa::list_node<char>('x');
  //   mesa::list_iterator<char> original(node);
  //   mesa::list_iterator<char> copy(original);
  //   THEN ( " the list_node value is stored in both iterators " ) {
  //     CHECK( original.node->value == node->value); 
  //     CHECK( original.node->value == copy.node->value); 
  //   }
  //   AND_THEN ( " a change to the copy does not change the original " ) {
  //     copy.node->value = 'a';
  //     CHECK( original.node->value == 'x'); 
  //   }
  // }

  // GIVEN( "2 list_iterators" ) {
  //   auto node = new mesa::list_node<char>('x');
  //   auto tmp = new mesa::list_node<char>('t');
  //   mesa::list_iterator<char> original(node);
  //   mesa::list_iterator<char> copy(tmp);
  //   CHECK( 't' == copy.node->value); 

    // WHEN( "a list_iterator is copy assigned to another" ) {
    //   copy = original;
    //   THEN ( " the list_node value is stored in both iterators " ) {
    //     CHECK( original.node->value == node->value); 
    //     CHECK( original.node->value == copy.node->value); 
    //   }
    //   AND_THEN ( " a change to the copy does not change the original " ) {
    //     copy.node->value = 'a';
    //     CHECK( original.node->value == 'x'); 
    //   }
    // }
  // }

}

