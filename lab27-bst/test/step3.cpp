#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <sstream>

#include <doctest.h>
#include "../src/bstree.h"

SCENARIO( "Test bstree decrement") {

  GIVEN ( "an empty tree" ) {
    mesa::bstree<int> test_tree;
    REQUIRE(test_tree.empty() == true);

    WHEN (" a root and a left added" ) {
      auto it1 = test_tree.insert(8);
      auto it2 = test_tree.insert(1);
      THEN ( "they should exist in the tree" ) {
        CHECK( test_tree.contains(8) == true);
        CHECK( test_tree.contains(1) == true);
      }
      AND_THEN ( "the root element should be the max" ) {
        CHECK( *it1 == 8);
      }
      AND_THEN ( "the left child element should be the min" ) {
        CHECK( *it2 == 1);
      }
      AND_THEN ( "decrementing the first (root) iterator should equal the second (min)" ) {
        --it1;
        CHECK( *it1 == *it2);
      }
    }

    WHEN (" a root and a right added" ) {
      auto it1 = test_tree.insert(5);
      auto it2 = test_tree.insert(13);
      THEN ( "they should exist in the tree" ) {
        CHECK( test_tree.contains(5) == true);
        CHECK( test_tree.contains(13) == true);
      }
      AND_THEN ( "the root element should be the min" ) {
        CHECK( *it1 == 5);
      }
      AND_THEN ( "the right child element should be the max" ) {
        CHECK( *it2 == 13);
      }
      AND_THEN ( "decrementing the second iterator should equal the first" ) {
        --it2;
        CHECK( *it1 == *it2);
      }
    }

    WHEN (" a third node is inserted in the left subtree" ) {
      auto it1 = test_tree.insert(8);
      auto it2 = test_tree.insert(1);
      auto it3 = test_tree.insert(3);
      THEN ( "the root element should be the max" ) {
        CHECK( *it1 == 8);
      }
      AND_THEN ( "the left,left child element should be the min" ) {
        CHECK( *it2 == 1);
      }
      AND_THEN ( "the left child element should be the middle" ) {
        CHECK( *it3 == 3);
      }
      AND_THEN ( "decrementing the root iterator should walk to min" ) {
        --it1;
        CHECK( *it3 == *it1);
        --it1;
        CHECK( *it2 == *it1);
      }
    }

    WHEN (" nodes inserted in the right subtree" ) {
      auto it1 = test_tree.insert(8);
      auto it2 = test_tree.insert(1);
      auto it3 = test_tree.insert(9);
      auto it4 = test_tree.insert(13);
      auto it5 = test_tree.insert(14);
      THEN ( "the root element should be 8" ) {
        CHECK( *it1 == 8);
      }
      AND_THEN ( "the left child element should be the min" ) {
        CHECK( *it2 == 1);
      }
      AND_THEN ( "the right-most child element should be max" ) {
        CHECK( *it5 == 14);
      }
      AND_THEN ( "decrementing the max iterator should walk to min" ) {
        --it5;
        CHECK( *it4 == *it5);
        --it5;
        CHECK( *it3 == *it5);
        --it5;
        CHECK( *it1 == *it5);
        --it5;
        CHECK( *it2 == *it5);
      }
    }

  }
}

