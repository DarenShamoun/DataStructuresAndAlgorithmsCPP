#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>

#include <doctest.h>
#include <tree.h>

SCENARIO( "Test tree(T)") {

  WHEN( "mesa::tree(T) is declared with an int type" ) {
    mesa::tree<int> actual;
    actual.value = 8;

    THEN( "the tree can be assigned a value" ) {
      REQUIRE(actual.value == 8);
      CHECK_MESSAGE(actual.left == nullptr, "Left child is not the nullptr");
      CHECK_MESSAGE(actual.right == nullptr, "Left child is not the nullptr");
    }
  }

  WHEN( "mesa::make_tree(T) is declared with a double type" ) {
    mesa::tree<double> actual;
    actual.value = 2.781828;
    THEN( "the tree can be assigned a value" ) {
      REQUIRE(actual.value == 2.781828);
      CHECK_MESSAGE(actual.left == nullptr, "Left child is not the nullptr");
      CHECK_MESSAGE(actual.right == nullptr, "Left child is not the nullptr");
    }
  }

}


