#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/tree_node.h"

SCENARIO( "Test min_element") {

  WHEN( "a tree is empty" ) {
    mesa::tree::tree_node<int>* test_tree = nullptr;
    THEN( "min_element should return null" ) {
      REQUIRE(mesa::tree::min_element(test_tree) == nullptr);
    }
  }

  WHEN( "a tree has no left child" ) {
    mesa::tree::tree_node<int> test_tree(3);
    THEN( "min_element should return the current node" ) {
      REQUIRE(mesa::tree::min_element(&test_tree) == &test_tree);
    }
  }

  WHEN( "a tree has a left child" ) {
    mesa::tree::tree_node<int> test_tree(8);
    mesa::tree::tree_node<int> left(3);
    mesa::tree::tree_node<int> right(10);
    test_tree.left = &left;
    test_tree.right = &right;
    THEN( "min_element should return the left child" ) {
      CHECK(mesa::tree::min_element(&test_tree)->value == left.value);
    }
  }

  WHEN( "a tree has a left subtree" ) {
    mesa::tree::tree_node<int> test_tree(8);
    mesa::tree::tree_node<int> left(3);
    mesa::tree::tree_node<int> ll(1);
    mesa::tree::tree_node<int> lr(6);
    left.left = &ll;
    left.right = &lr;
    mesa::tree::tree_node<int> right(10);
    test_tree.left = &left;
    test_tree.right = &right;
    THEN( "min_element should return the left-most child" ) {
      CHECK(mesa::tree::min_element(&test_tree)->value == ll.value);
    }
  }

  WHEN( "a tree has a right subtree only" ) {
    mesa::tree::tree_node<int> test_tree(7);
    mesa::tree::tree_node<int> right(10);
    test_tree.right = &right;
    THEN( "min_element should return the root node" ) {
      CHECK(mesa::tree::min_element(&test_tree)->value == test_tree.value);
    }
  }

}



SCENARIO( "Test max_element") {

  WHEN( "a tree is empty" ) {
    mesa::tree::tree_node<int>* test_tree = nullptr;
    THEN( "max_element should return null" ) {
      REQUIRE(mesa::tree::max_element(test_tree) == nullptr);
    }
  }

  WHEN( "a tree has no right child" ) {
    mesa::tree::tree_node<int> test_tree(3);
    THEN( "max_element should return the current node" ) {
      REQUIRE(mesa::tree::max_element(&test_tree) == &test_tree);
    }
  }

  WHEN( "a tree has a right child" ) {
    mesa::tree::tree_node<int> test_tree(8);
    mesa::tree::tree_node<int> left(3);
    mesa::tree::tree_node<int> right(10);
    test_tree.left = &left;
    test_tree.right = &right;
    THEN( "max_element should return the right child" ) {
      CHECK(mesa::tree::max_element(&test_tree)->value == right.value);
    }
  }

  WHEN( "a tree has a left subtree + a right child" ) {
    mesa::tree::tree_node<int> test_tree(8);
    mesa::tree::tree_node<int> left(3);
    mesa::tree::tree_node<int> ll(1);
    mesa::tree::tree_node<int> lr(6);
    left.left = &ll;
    left.right = &lr;
    mesa::tree::tree_node<int> right(10);
    test_tree.left = &left;
    test_tree.right = &right;
    THEN( "max_element should return the root node" ) {
      CHECK(mesa::tree::max_element(&test_tree)->value == right.value);
    }
  }

  WHEN( "a tree has a left subtree only" ) {
    mesa::tree::tree_node<int> test_tree(8);
    mesa::tree::tree_node<int> left(3);
    mesa::tree::tree_node<int> ll(1);
    mesa::tree::tree_node<int> lr(6);
    left.left = &ll;
    left.right = &lr;
    test_tree.left = &left;
    THEN( "max_element should return the root node" ) {
      CHECK(mesa::tree::max_element(&test_tree)->value == test_tree.value);
    }
  }

  WHEN( "a tree has a right subtree only" ) {
    mesa::tree::tree_node<int> test_tree(8);
    mesa::tree::tree_node<int> right(10);
    mesa::tree::tree_node<int> rl(9);
    mesa::tree::tree_node<int> rr(14);
    right.left = &rl;
    right.right = &rr;
    test_tree.right = &right;
    THEN( "max_element should return the right-most child" ) {
      CHECK(mesa::tree::max_element(&test_tree)->value == rr.value);
    }
  }

}



