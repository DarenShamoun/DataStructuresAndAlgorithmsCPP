#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <algorithm>
#include <list>

#include <doctest.h>
#include "../src/binary_heap.h"

SCENARIO( "Test mesa::binary_heap<T>::push") {

  GIVEN( "an initally empty heap" ) {
    mesa::binary_heap<int> h;

    WHEN( "push is called once" ) {
      THEN( "front returns the new smallest value" ) {
        h.push(72);
        int actual = h.front();
        int expected = 72;
        CHECK(expected == actual);
        CHECK(1 == h.size());
      }
    }

    WHEN( "push is called 3 times" ) {
      THEN( "front returns the smallest value" ) {
        h.push(34);
        h.push(21);
        h.push(13);
        int actual = h.front();
        int expected = 13;
        CHECK(expected == actual);
        CHECK(3 == h.size());
      }
    }

    WHEN( "push is called many times" ) {
      THEN( "front returns the smallest value and the heap is still valid" ) {
        h.push(34);
        h.push(21);
        h.push(13);
        h.push(3);
        h.push(99);
        h.push(87);
        h.push(5);
        h.push(54);
        h.push(2);
        std::list<int> data = {2,3,5,13,21,34,54,87,99};
        while ( !data.empty() ) {
          int actual = h.front();
          int expected = data.front();
          CHECK(expected == actual);
          h.pop();
          data.pop_front();
        }
      }
    }

  }

}

