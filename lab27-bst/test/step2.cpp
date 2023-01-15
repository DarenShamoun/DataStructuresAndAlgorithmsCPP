#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <sstream>

#include <doctest.h>
#include "../src/bstree.h"

SCENARIO( "Test bstree insert") {

  GIVEN ( "an empty tree" ) {
    mesa::bstree<int> test_tree;
    REQUIRE(test_tree.empty() == true);
    WHEN (" a value is added" ) {
      test_tree.insert(8);
      THEN ( "it should exist in the tree" ) {
        REQUIRE( test_tree.contains(8) == true);
      }
    }

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
      AND_THEN ( "incrementing the second (min) iterator should equal the first (root)" ) {
        ++it2;
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
      AND_THEN ( "incrementing the first iterator should equal the second" ) {
        ++it1;
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
      AND_THEN ( "incrementing the min iterator should walk to root" ) {
        ++it2;
        CHECK( *it3 == *it2);
        ++it2;
        CHECK( *it1 == *it2);
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
      AND_THEN ( "incrementing the min iterator should walk to max" ) {
        ++it2;
        CHECK( *it1 == *it2);
        ++it2;
        CHECK( *it3 == *it2);
        ++it2;
        CHECK( *it4 == *it2);
        ++it2;
        CHECK( *it5 == *it2);
      }
    }

  }

}






