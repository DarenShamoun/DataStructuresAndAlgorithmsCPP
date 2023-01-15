#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <list.h>

SCENARIO( "Test list struct insert") {
  GIVEN( "a list" ) {
    list* node = new list;

    WHEN( "-13 and 21 are added in that order" ) {
      node = node->insert(-13);
      node = node->insert(21);
      THEN( "the list should contain {21,-13,0} in that order" ) {
        int actual = node->val;
        CHECK_MESSAGE (actual == 21, "The first list element contains " << actual);
        actual = node->next->val;
        CHECK_MESSAGE (actual == -13, "The second list element contains " << actual);
        actual = node->next->next->val;
        CHECK_MESSAGE (actual == 0, "The last list element contains " << actual);
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
        int actual = node->val;
        CHECK_MESSAGE (actual == 8, "The first list element contains " << actual);
        actual = node->next->val;
        CHECK_MESSAGE (actual == 5, "The second list element contains " << actual);
        actual = node->next->next->val;
        CHECK_MESSAGE (actual == 3, "The third list element contains " << actual);
        actual = node->next->next->next->val;
        CHECK_MESSAGE (actual == 2, "The fourth list element contains " << actual);
        actual = node->next->next->next->next->val;
        CHECK_MESSAGE (actual == 1, "The last list element contains " << actual);
      }
    }

  }
}


