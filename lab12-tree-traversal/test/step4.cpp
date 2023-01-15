#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <sstream>
#include <doctest.h>
#include <tree.h>

static
mesa::tree<int>* unbalanced_tree() {
  using mesa::make_tree;
  auto two = make_tree(2);
  auto three = make_tree(3);
  auto four = make_tree(4);
  auto five = make_tree(5);
  auto six = make_tree(6);
  auto seven = make_tree(7);
  two->left = four;
  four->left = five;
  four->right = six;
  six->right = seven;
  auto root = make_tree(1, two, three);
  return root;
}

SCENARIO( "Test mesa::level_order") {
  std::stringstream actual;

  WHEN( "mesa::level_order is called with an int" ) {
    auto left = mesa::make_tree<int>(2);
    auto right = mesa::make_tree<int>(3);
    auto root = mesa::make_tree<int>(1, left, right);
    mesa::level_order(actual,root);
    auto expected = std::string("1 2 3 ");
    THEN( "the stream should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

  WHEN( "mesa::make_tree is called with a double" ) {
    auto left = mesa::make_tree(2.71828);
    auto right = mesa::make_tree(1.618);
    auto root = mesa::make_tree(3.14, left, right);
    mesa::level_order(actual,root);
    auto expected = std::string("3.14 2.71828 1.618 ");
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

  WHEN( "mesa::make_tree is called with a string" ) {
    auto left = mesa::make_tree<std::string>("cruel");
    auto right = mesa::make_tree<std::string>("world!");
    auto root = mesa::make_tree<std::string>("goodbye,", left, right);
    mesa::level_order(actual,root);
    auto expected = std::string("goodbye, cruel world! ");
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

  WHEN( "mesa::level_order is called with an unbalanced tree" ) {
    auto root = unbalanced_tree();
    mesa::level_order(actual,root);
    auto expected = std::string("1 2 3 4 5 6 7 ");
    THEN( "the stream should contain the tree values in post order" ) {
      CHECK(actual.str() == expected);
    }
  }


}


