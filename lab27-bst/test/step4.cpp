#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <random>
#include <vector>

#include <doctest.h>
#include "../src/bstree.h"

SCENARIO( "Test bstree begin and end") {
  std::vector<int> expected = {1,3,4,6,7,8,10,13,14};
  std::vector<int> rexpected = expected;
  std::reverse(rexpected.begin(), rexpected.end());
  auto vec = expected;
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(vec.begin(), vec.end(), g);


  GIVEN ( "the lab example tree values" ) {
    mesa::bstree<int> test_tree;
    for (auto& v : vec) {
      test_tree.insert(v);
    }

    WHEN (" iterating from begin to end" ) {
      THEN ( "the values should be sorted" ) {
        int count = 0;
        // MESSAGE("processing tree: " << test_tree );
        for (const auto& actual : test_tree) {
          CHECK(actual == expected[count]);
          ++count;
        }
      }
    }

    WHEN (" iterating from rbegin to rend" ) {
      THEN ( "the values should be sorted descending" ) {
        auto actual = test_tree.rbegin();
        for (const auto& expected_value : rexpected) {
          CHECK(*actual == expected_value);
          --actual;
        }

      }
    }

  }
}

