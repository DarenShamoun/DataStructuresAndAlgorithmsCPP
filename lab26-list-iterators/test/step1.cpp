#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <type_traits>

#include <doctest.h>
#include "../src/list.h"

SCENARIO( "Test mesa::list<T>") {

  WHEN( "mesa::list is declared with an int type" ) {
    typedef int int_type;
    mesa::list<int_type> actual;
    THEN( "the list compiles" ) {
      CHECK_MESSAGE(&actual == &actual, "placeholder for compilation");
    } AND_THEN ( "the value_type is 'int'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list<int>::value_type, int>() == true), 
          "expected 'value_type' to be 'int'");
    }
  }

  WHEN( "mesa::list is declared with other types" ) {
    THEN ( "the value_type could be 'double'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list<double>::value_type, double>() == true), 
          "expected 'value_type' to be 'double'");
    } AND_THEN ( "the value_type could be 'char'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::list<char>::value_type, char>() == true), 
          "expected 'value_type' to be 'char'");
    }
  }

}

SCENARIO( "Test list push_front() and front()") {

  GIVEN( "an empty list" ) {
    mesa::list<int> test_list;

    WHEN( "push_front is called on an empty list" ) {
      int expected = 13;
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
    }

    WHEN( "push_front is called on a 2-element list" ) {
      int expected = 5;
      test_list.push_front(8);
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
    }

    WHEN( "push_front is called on a 3-element list" ) {
      int expected = 3;
      test_list.push_front(8);
      test_list.push_front(5);
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
    }

  }

  GIVEN( "a constant list is constructed" ) {
    int expected = 2;
    const mesa::list<int> test_list{expected};

    WHEN( "front is called on a const list" ) {
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
    }
  }

}

SCENARIO( "Test list empty()") {

  GIVEN( "an empty list" ) {
    mesa::list<int> test_list;
    THEN( "the list should show empty" ) {
      CHECK(test_list.empty() == true);
    }

    WHEN( "push_front is called on an empty list" ) {
      test_list.push_front(13);
      THEN( "the list should show false" ) {
        CHECK(test_list.empty() == false);
      }
    }

    WHEN( "push_front is called on a 2-element list" ) {
      int expected = 5;
      test_list.push_front(8);
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
      AND_THEN( "the list should show false" ) {
        CHECK(test_list.empty() == false);
      }
    }

  }

  GIVEN( "a constant list is constructed" ) {
    int expected = 2;
    const mesa::list<int> test_list{expected};

    WHEN( "empty is called on a const list" ) {
      THEN( "the list should show false" ) {
        CHECK(test_list.empty() == false);
      }
    }
  }

  GIVEN( "an empty constant list is constructed" ) {
    const mesa::list<int> test_list;
    WHEN( "empty is called on an empty const list" ) {
      THEN( "the list should show true" ) {
        CHECK(test_list.empty() == true);
      }
    }
  }

}

SCENARIO( "Test list size()") {

  GIVEN( "an empty list" ) {
    mesa::list<int> test_list;
    WHEN( "the list is empty" ) {
      THEN( "the size == 0" ) {
        CHECK(test_list.size() == 0);
      }
    }

    WHEN( "push_front is called on an empty list" ) {
      int expected = 13;
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
      AND_THEN( "size is 1" ) {
        CHECK(test_list.size() == 1);
      }
    }

    WHEN( "push_front is called on a 2-element list" ) {
      int expected = 5;
      test_list.push_front(8);
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
      AND_THEN( "size is 2" ) {
        CHECK(test_list.size() == 2);
      }
    }

    WHEN( "push_front is called on a 3-element list" ) {
      int expected = 3;
      test_list.push_front(8);
      test_list.push_front(5);
      test_list.push_front(expected);
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
      AND_THEN( "size is 3" ) {
        CHECK(test_list.size() == 3);
      }
    }

  }

  GIVEN( "a constant list is constructed" ) {
    WHEN( "the list is empty" ) {
      const mesa::list<int> test_list;

      THEN( "the size == 0" ) {
        CHECK(test_list.size() == 0);
      }
    }

    WHEN( "a const list is not empty" ) {
      int expected = 21;
      const mesa::list<int> test_list{expected};
      THEN( "front should == expected" ) {
        CHECK(test_list.front() == expected);
      }
      AND_THEN( "size is 1" ) {
        CHECK(test_list.size() == 1);
      }
    }
  }

}

SCENARIO( "Test list pop_front()") {

  GIVEN( "an empty list" ) {
    mesa::list<int> test_list;
    WHEN( "the list is empty" ) {
      THEN( "the pop_front should do nothing" ) {
        CHECK(test_list.empty() == true);
        CHECK(test_list.size() == 0);
        test_list.pop_front();
        CHECK(test_list.empty() == true);
        CHECK(test_list.size() == 0);
      }
    }

    WHEN( "pop_front is called on a list with only 1 element" ) {
      test_list.push_front(13);
      CHECK(test_list.size() == 1);
      THEN( "it should empty the list" ) {
        test_list.pop_front();
        CHECK(test_list.empty() == true);
        CHECK(test_list.size() == 0);
      }
    }

    WHEN( "pop_front is called on a 2-element list" ) {
      int expected = 5;
      test_list.push_front(expected);
      test_list.push_front(8);
      CHECK(test_list.size() == 2);
      THEN( "the front element is removed with 1 remaining" ) {
        test_list.pop_front();
        CHECK(test_list.front() == expected);
        CHECK(test_list.size() == 1);
        CHECK(test_list.empty() == false);
      }
    }

    WHEN( "pop_front is called on a 3-element list" ) {
      int expected = 3;
      test_list.push_front(8);
      test_list.push_front(expected);
      test_list.push_front(5);
      CHECK(test_list.size() == 3);
      THEN( "the front element is removed with 2 remaining" ) {
        test_list.pop_front();
        CHECK(test_list.front() == expected);
        CHECK(test_list.size() == 2);
      }
    }

  }

}


