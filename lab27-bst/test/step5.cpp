#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <random>
#include <vector>

#include <doctest.h>
#include "../src/bstree.h"

SCENARIO( "Test bstree erase fixed node insertion order") {
  std::vector<int> expected = {1,3,4,6,7,8,10,13,14};
  auto vec = expected;

  GIVEN ( "the lab example tree" ) {
    mesa::bstree<int> test_tree;
    test_tree.insert(8);
    test_tree.insert(3);
    test_tree.insert(1);
    test_tree.insert(6);
    test_tree.insert(4);
    test_tree.insert(7);
    test_tree.insert(10);
    test_tree.insert(14);
    test_tree.insert(13);

    WHEN (" each value is removed" ) {
      THEN ( "contains(value) is false" ) {
        for (const auto& v: vec) {
          CAPTURE(v);
          CHECK(test_tree.contains(v) == true);
          test_tree.erase(v);
          CHECK(test_tree.contains(v) == false);
        }
        REQUIRE(test_tree.empty() == true);
      }
    }

  }
}

SCENARIO( "Test bstree erase random node insertion order") {
  std::vector<int> expected = {1,3,4,6,7,8,10,13,14};
  auto vec = expected;
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(vec.begin(), vec.end(), g);


  GIVEN ( "the lab example tree values with different insertion ordering" ) {
    mesa::bstree<int> test_tree;
    for (auto& v : vec) {
      test_tree.insert(v);
    }

    WHEN (" each value is removed" ) {
      THEN ( "contains(value) is false" ) {
        for (const auto& v: vec) {
          CAPTURE(v);
          CHECK(test_tree.contains(v) == true);
          test_tree.erase(v);
          CHECK(test_tree.contains(v) == false);
        }
        REQUIRE(test_tree.empty() == true);
      }
    }

  }
}

