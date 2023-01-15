#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <algorithm>
#include <vector>

#include <doctest.h>
#include "../src/binary_heap.h"

SCENARIO( "Test mesa::binary_heap<T>::pop") {

  GIVEN( "the heap {8 14 16 19 14 21 26 65 32 31 19}" ) {
    std::vector<int> v = {14,19,16,19,8,21,26,65,32,31,14};
    mesa::binary_heap<int> h{v};

    WHEN( "pop has not been called" ) {
      THEN( "front returns smallest value" ) {
        int actual = h.front();
        int expected = 8;
        CHECK(expected == actual);
      }
    }

    WHEN( "pop is called once" ) {
      THEN( "front returns the new smallest value" ) {
        h.pop();
        int actual = h.front();
        int expected = 14;
        CHECK(expected == actual);
      }
    }

    WHEN( "pop is called 3 times" ) {
      THEN( "front returns the 4th smallest value" ) {
        h.pop();
        h.pop();
        h.pop();
        int actual = h.front();
        int expected = 16;
        CHECK(expected == actual);
      }
    }

    WHEN( "pop is called 4 times" ) {
      THEN( "front returns the 5th smallest value" ) {
        h.pop(); h.pop(); h.pop();
        h.pop();
        int actual = h.front();
        int expected = 19;
        CHECK(expected == actual);
      }
    }

    WHEN( "pop is called 5 times" ) {
      THEN( "front returns the 6th smallest value" ) {
        h.pop(); h.pop(); h.pop();
        h.pop();
        h.pop();
        int actual = h.front();
        int expected = 19;
        CHECK(expected == actual);
      }
    }

    WHEN( "pop is called 6 times" ) {
      THEN( "front returns the 7th smallest value" ) {
        h.pop(); h.pop(); h.pop();
        h.pop(); h.pop(); h.pop();
        int actual = h.front();
        int expected = 21;
        CHECK(expected == actual);
      }
    }

    WHEN( "pop is called 10 times" ) {
      THEN( "front returns the largest value" ) {
        h.pop(); h.pop(); h.pop();
        h.pop(); h.pop(); h.pop();
        h.pop(); h.pop(); h.pop();
        h.pop();
        int actual = h.front();
        int expected = 65;
        CHECK(expected == actual);
      }
    }

    WHEN( "pop is called 11 times" ) {
      THEN( "the heap is empty" ) {
        h.pop(); h.pop(); h.pop();
        h.pop(); h.pop(); h.pop();
        h.pop(); h.pop(); h.pop();
        h.pop();
        h.pop();
        CHECK(true == h.empty());
        CHECK(0 == h.size());
      }
    }

  }

}

