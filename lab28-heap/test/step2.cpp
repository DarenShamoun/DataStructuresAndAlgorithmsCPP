#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <algorithm>
#include <vector>

#include <doctest.h>
#include "../src/binary_heap.h"

SCENARIO( "Test mesa::binary_heap<T>::empty") {

  WHEN( "the heap is empty" ) {
    mesa::binary_heap<int> h;
    THEN( "empty returns true" ) {
      bool actual = h.empty();
      bool expected = true;
      CHECK(expected == actual);
    }
  }

  WHEN( "the heap is not empty" ) {
    std::vector<int> v = {1,2,3,4,5};
    mesa::binary_heap<int> h{v};
    THEN( "empty returns false" ) {
      bool actual = h.empty();
      bool expected = false;
      CHECK(expected == actual);
    }
  }

  WHEN( "the heap is constructed with an empty vector" ) {
    std::vector<int> v;
    mesa::binary_heap<int> h{v};
    THEN( "empty returns true" ) {
      bool actual = h.empty();
      bool expected = true;
      CHECK(expected == actual);
    }
  }

}

SCENARIO( "Test mesa::binary_heap<T>::size") {

  WHEN( "the heap is empty" ) {
    mesa::binary_heap<int> h;
    THEN( "size returns 0" ) {
      size_t actual = h.size();
      size_t expected = 0;
      CHECK(expected == actual);
    }
  }

  WHEN( "the heap is not empty" ) {
    std::vector<int> v = {1,2,3,4,5};
    mesa::binary_heap<int> h{v};
    THEN( "size returns the number of heap elements, not including the temp slot" ) {
      size_t actual = h.size();
      size_t expected = v.size();
      CHECK_MESSAGE(expected == actual, "If the actual size is 6, make sure you are not counting the temporary bookkeeping element in your size count");
    }
  }

}

SCENARIO( "Test mesa::binary_heap<T>::front") {

  WHEN( "the heap is not empty" ) {
    std::vector<int> v = {5,4,3,2,1};
    mesa::binary_heap<int> h{v};
    THEN( "front returns smallest value" ) {
      int actual = h.front();
      int expected = 1;
      CHECK(expected == actual);
    }
  }

  WHEN( "the heap has many duplicate elements" ) {
    std::vector<int> v (99, 21);
    v[72] = 13;
    mesa::binary_heap<int> h{v};
    THEN( "front returns smallest value" ) {
      int actual = h.front();
      int expected = 13;
      CHECK(expected == actual);
    }
  }

}

SCENARIO( "Test mesa::binary_heap<T>::clear") {

  WHEN( "the heap is empty" ) {
    mesa::binary_heap<int> h;
    CHECK(0 == h.size());
    THEN( "clear does nothing" ) {
      h.clear();
      CHECK(0 == h.size());
    }
  }

  WHEN( "the heap is not empty" ) {
    std::vector<int> v (99, 21);
    v[72] = 13;
    mesa::binary_heap<int> h{v};
    CHECK(v.size() == h.size());
    THEN( "clear resets the size" ) {
      h.clear();
      CHECK(0 == h.size());
    }
  }

}

