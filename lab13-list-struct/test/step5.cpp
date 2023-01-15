#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <string>

#include <doctest.h>
#include <list.h>

SCENARIO( "Test list struct output stream overload") {
  std::stringstream ss;
  GIVEN( "a list" ) {
    list* node = new list;

    WHEN( "-13 and 21 are added in that order" ) {
      node = node->insert(-13);
      node = node->insert(21);
      THEN( "the list should contain {21,-13,0} in that order" ) {
        ss << node;
        std::string actual = ss.str();
        std::string expected = "21 -13 0 ";
        CHECK (actual == expected);
      }
    }
  }

  GIVEN( "a list with value 1" ) {
    list* node = new list{1};
    WHEN( "2,3,5,8 are added in that order" ) {
      node = node->insert(2);
      node = node->insert(3);
      node = node->insert(5);
      node = node->insert(8);
      THEN( "the list should contain {8,5,3,2,1} in that order" ) {
        ss << node;
        std::string actual = ss.str();
        std::string expected = "8 5 3 2 1 ";
        CHECK (actual == expected);
      }
    }

  }
}


