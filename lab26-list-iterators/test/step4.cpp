#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test mesa::list_iterator<T> dereference") {

  WHEN( "mesa::list_iterator is constructed with a list_node" ) {
    auto node = new mesa::list_node<char>('n');
    mesa::list_iterator<char> actual(node);
    THEN ( " the dereference operator returns the node value " ) {
      CHECK( *actual == 'n'); 
    }
  }
}

SCENARIO( "Test mesa::list_iterator<T> increment") {

  GIVEN( "a list_iterator" ) {
    auto next = new mesa::list_node<int>(2);
    auto node = new mesa::list_node<int>(1, next);
    mesa::list_iterator<int> expected(next);
    mesa::list_iterator<int> actual(node);
    WHEN( "the iterator is incremented" ) {
      THEN ( " the prefix iterator should advance to the next pointer " ) {
        ++actual;
        CHECK( *actual == *expected); 
      }
      AND_THEN ( " the postfix iterator should advance to the next pointer " ) {
        actual++;
        CHECK( *actual == *expected); 
      }
    }
  }

}

SCENARIO( "Test mesa::list_iterator<T> equivalence") {

  GIVEN( "a list_iterator" ) {
    auto node = new mesa::list_node<int>(2);
    mesa::list_iterator<int> a(node);
    WHEN( "the iterator is compared to itself" ) {
      THEN ( " it should be equal " ) {
        CHECK(operator==(a,a)); 
      }
    }
  }

  GIVEN( "two list_iterators" ) {
    auto node = new mesa::list_node<int>(3);
    auto other = new mesa::list_node<int>(5);
    WHEN( "the iterators point to the same list_node" ) {
      mesa::list_iterator<int> a(node);
      mesa::list_iterator<int> b(node);
      THEN ( " they should be equal " ) {
        CHECK(operator==(a,b)); 
        CHECK(operator==(b,a)); 
      }
    }
    WHEN( "the iterators point to different list_nodes" ) {
      mesa::list_iterator<int> a(node);
      mesa::list_iterator<int> b(other);
      THEN ( " they should not be equal " ) {
        CHECK(operator!=(a,b)); 
        CHECK(operator!=(b,a)); 
      }
    }
  }

  GIVEN( "three list_iterators" ) {
    auto node = new mesa::list_node<int>(3);
    WHEN( "the iterators point to the same list_node" ) {
      mesa::list_iterator<int> a(node);
      mesa::list_iterator<int> b(node);
      mesa::list_iterator<int> c(node);
      THEN ( " they should be equal " ) {
        CHECK(operator==(a,b)); 
        CHECK(operator==(a,c)); 
        CHECK(operator==(b,c)); 
        CHECK(operator==(b,a)); 
        CHECK(operator==(c,b)); 
        CHECK(operator==(c,a)); 
      }
    }
  }

}

