#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <random>
#include <vector>

#include <doctest.h>
#include "../src/bstree.h"

SCENARIO( "Test bstree find") {
  mesa::bstree<int> test_tree;

    WHEN (" nodes inserted in the right subtree" ) {
      auto it1 = test_tree.insert(8);
      auto it2 = test_tree.insert(1);
      auto it3 = test_tree.insert(9);
      auto it4 = test_tree.insert(13);
      auto it5 = test_tree.insert(14);
      THEN ( "find (8) returns an iterator to the root element" ) {
        CHECK( *it1 == *(test_tree.find(8)));
      }
      AND_THEN ( "find (1) returns an iterator to the root left child" ) {
        CHECK( *it2 == *(test_tree.find(1)));
      }
      AND_THEN ( "find(14) returns an iterator to the right-most child element" ) {
        CHECK( *it5 == *(test_tree.find(14)));
      }
      AND_THEN ( "find(9) returns an iterator to the 9 element" ) {
        CHECK( *it3 == *(test_tree.find(9)));
      }
      AND_THEN ( "find(13) returns an iterator to the 13 element" ) {
        CHECK( *it4 == *(test_tree.find(13)));
      }
    }
}


