#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <doctest.h>
#include <tree.h>

SCENARIO( "Test mesa::make_tree(T, tree<T>* tree<T>*)") {

  WHEN( "mesa::make_tree is called with an int" ) {
    auto left = mesa::make_tree<int>(2);
    auto right = mesa::make_tree<int>(3);
    auto actual = mesa::make_tree<int>(1, left, right);
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual->value == 1);
      CHECK(actual->left->value == 2);
      CHECK(actual->right->value == 3);
    }
  }

  WHEN( "mesa::make_tree is called with a double" ) {
    auto left = mesa::make_tree(2.71828);
    auto right = mesa::make_tree(1.618);
    auto actual = mesa::make_tree(3.14, left, right);
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual->value == 3.14);
      CHECK(actual->left->value == 2.71828);
      CHECK(actual->right->value == 1.618);
    }
  }

  WHEN( "mesa::make_tree is called with a string" ) {
    auto left = mesa::make_tree<std::string>("cruel");
    auto right = mesa::make_tree<std::string>("world");
    auto actual = mesa::make_tree<std::string>("goodbye", left, right);
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual->value == std::string("goodbye"));
      CHECK(actual->left->value == std::string("cruel"));
      CHECK(actual->right->value == std::string("world"));
    }
  }

  WHEN( "mesa::make_tree is called with a struct" ) {
    struct test_step2 {
      int x = 0;
      int y = 1;
    };
    test_step2 value;
    test_step2 lvalue;
    test_step2 rvalue;

    lvalue.x = 2;
    lvalue.y = 3;
    rvalue.x = 5;
    rvalue.y = 8;
    auto left = mesa::make_tree(lvalue);
    auto right = mesa::make_tree(rvalue);
    auto actual = mesa::make_tree(value, left, right);
    THEN( "the tree returned should contain 3 structs" ) {
      CHECK(actual->value.x == 0);
      CHECK(actual->value.y == 1);
      CHECK(actual->left->value.x == 2);
      CHECK(actual->left->value.y == 3);
      CHECK(actual->right->value.x == 5);
      CHECK(actual->right->value.y == 8);
    }
  }

}


SCENARIO( "making an unbalanced tree") {

  WHEN( "mesa::make_tree is called with a null right child" ) {
    auto left = mesa::make_tree<int>(13);
    auto actual = mesa::make_tree<int>(96, left, nullptr);
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual->value == 96);
      CHECK(actual->left->value == 13);
      CHECK(actual->right == nullptr);
    }
  }

  WHEN( "mesa::make_tree is called with a null left child" ) {
    auto right = mesa::make_tree<int>(34);
    auto actual = mesa::make_tree<int>(21, nullptr, right);
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual->value == 21);
      CHECK(actual->right->value == 34);
      CHECK(actual->left == nullptr);
    }
  }

}
