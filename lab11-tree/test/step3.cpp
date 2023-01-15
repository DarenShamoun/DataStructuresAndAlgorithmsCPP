#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>

#include <doctest.h>
#include <tree.h>

SCENARIO( "Test mesa::make_tree(T)") {

  WHEN( "mesa::make_tree(T) is called with an int" ) {
    auto actual = mesa::make_tree<int>(1);
    THEN( "the tree returned should contain a value" ) {
      REQUIRE(actual->value == 1);
    }
  }

  WHEN( "mesa::make_tree(T) is called with a double" ) {
    auto actual = mesa::make_tree(3.14);
    THEN( "the tree returned should contain a value" ) {
      REQUIRE(actual->value == 3.14);
    }
  }

  WHEN( "mesa::make_tree(T) is called with a string" ) {
    std::string value = "hello, there!";
    auto actual = mesa::make_tree(value);
    THEN( "the tree returned should contain a value" ) {
      REQUIRE(actual->value == value);
    }
  }

  WHEN( "mesa::make_tree(T) is called with a struct" ) {
    struct test_step2 {
      int x = 3;
      int y = 4;
    };
    test_step2 value;

    auto actual = mesa::make_tree(value);
    THEN( "the tree returned should contain a pair of values: 3, 4" ) {
      REQUIRE(actual->value.x == 3);
      REQUIRE(actual->value.y == 4);
    }
  }

}


