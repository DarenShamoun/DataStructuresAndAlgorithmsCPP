#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <sstream>

#include <doctest.h>
#include "../src/tree_node.h"
#include "../src/bstree.h"

// test the functions provided as part of the lab
// that have already been implemented
SCENARIO( "Test tree(T)") {

  WHEN( "tree_node(T) is declared with an int type" ) {
    int expected = 8;
    mesa::tree::tree_node<int> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.value == expected);
      CHECK_MESSAGE(actual.left == nullptr, "Left child is not the nullptr");
      CHECK_MESSAGE(actual.right == nullptr, "Left child is not the nullptr");
    }
  }

  WHEN( "tree_node(T) is declared with a double type" ) {
    double expected = 2.781828;
    mesa::tree::tree_node<double> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.value == expected);
    }
  }

  WHEN( "mesa::tree_node(T) is declared with a string type" ) {
    std::string expected = "hello, there!";
    mesa::tree::tree_node<std::string> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.value == expected);
    }
  }

  WHEN( "mesa::tree_node(T) is declared with a UDT" ) {
    struct test_step {
      int x = 3;
      int y = 4;
    };
    test_step expected;
    mesa::tree::tree_node<test_step> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.value.x == expected.x);
      REQUIRE(actual.value.y == expected.y);
    }
  }

}

SCENARIO( "Test bstree(T) contains") {
  WHEN( " a bstree is empty" ) {
    mesa::bstree<int> actual;
    CHECK_MESSAGE(actual.empty() == true, " tree is not empty!");
    THEN ( "contains return false" ) {
      REQUIRE(actual.contains(0) == false);
      REQUIRE(actual.contains(3) == false);
    }
  }
  WHEN( "mesa::bstree(T) is declared with a single int" ) {
    int expected = 8;
    mesa::bstree<int> actual(expected);
    THEN( "the tree_node contains a value and contains finds it" ) {
      REQUIRE(actual.contains(expected) == true);
    }
    AND_THEN( "values not in the tree return false from contains" ) {
      REQUIRE(actual.contains(21) == false);
    }
  }
}


SCENARIO( "Test bstree(T) copy") {
  WHEN( " a bstree is empty" ) {
    mesa::bstree<int> expected;
    CHECK_MESSAGE(expected.empty() == true, " tree is not empty!");
    THEN ( "the copy should be empty " ) {
      auto actual(expected);
      REQUIRE(actual.empty() == true);
    }
  }
  WHEN( "mesa::bstree(T) is declared with a single int" ) {
    int expected_value = 8;
    mesa::bstree<int> expected(expected_value);
    THEN( "the copy contains the expected value" ) {
      auto actual = expected;
      REQUIRE(actual.contains(expected_value) == true);
    }
  }
}


