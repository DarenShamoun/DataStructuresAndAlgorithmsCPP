#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <utility>

#include <doctest.h>
#include "../src/bag.h"
#include "../src/stack.h"

SCENARIO( "Check stack equality") {
  GIVEN( "a single stack" ) {
    mesa::bag<int> stuff {1,3};
    mesa::stack<int> a {stuff};
    WHEN("compared with itself") {
      THEN( "it should be considered equal (reflexive property)" ) {
        REQUIRE (operator==(a,a));
      }
    }
  }

  GIVEN( "eqivalent stacks" ) {
    WHEN("two different stacks store the same values") {
      mesa::bag<int> stuff {2,7,1,8,2,8,2,8};
      mesa::stack<int> a {stuff};
      mesa::stack<int> b {stuff};
      THEN( "the two objects should be considered equal (a==b)" ) {
        REQUIRE (operator==(a,b));
      }
      AND_THEN( "symmetry should also hold (b==a)" ) {
        REQUIRE (operator==(b,a));
      }
    }
    WHEN("there are 3 equal stacks, a == b == c") {
      mesa::bag<int> stuff {1,1,2,3,5,8,13,21,34};
      mesa::stack<int> a {stuff};
      mesa::stack<int> b {stuff};
      mesa::stack<int> c {stuff};
      THEN( "equality is symmetric" ) {
        REQUIRE ( (operator==(a,b) && operator==(b,a)) );
      }
      AND_THEN( "equality is transitive" ) {
        REQUIRE ( (operator==(a,b) && operator==(b,c) && operator==(a,c)) );
      }
    }
  }

  GIVEN( "two unequal stacks" ) {
    WHEN("a = 1/3, b = 1/4") {
      mesa::stack<int> a;
      a.push(1);
      a.push(3);
      mesa::stack<int> b;
      b.push(1);
      b.push(4);

      THEN( "the two stacks should be considered not equal (a!=b)" ) {
        REQUIRE (operator!=(a,b));
      }
      AND_THEN( "symmetry should also hold (b!=a)" ) {
        REQUIRE (operator!=(b,a));
      }
    }
    WHEN("there are 3 unequal numbers, a != b != c") {
      mesa::stack<int> a;
      a.push(2);
      a.push(3);
      mesa::stack<int> b;
      b.push(2);
      b.push(9);
      mesa::stack<int> c;
      c.push(8);
      c.push(27);
      THEN( "a != b" ) {
        REQUIRE (operator!=(a,b));
      }
      AND_THEN( "b != c" ) {
        REQUIRE (operator!=(b,c));
      }
      AND_THEN( "a != c (transitive property)" ) {
        REQUIRE (operator!=(a,c));
      }
    }
  }
}



SCENARIO( "Check equal stack comparisons using <= and >=") {
  GIVEN( "a single stack" ) {
    mesa::bag<int> stuff {1,1,2,3,5,8,13,21,34};
    mesa::stack<int> a {stuff};
    WHEN("compared with itself") {
      THEN( "it should be considered equal (<= test) (reflexive property)" ) {
        REQUIRE (operator<=(a,a));
      } AND_THEN( "it should be considered equal (>= test)" ) {
        REQUIRE (operator>=(a,a));
      }
    }
  }

  GIVEN( "eqivalent stacks" ) {
    mesa::bag<int> stuff {1,1,2,3,5,8,13,21,34};
    WHEN("two different stacks store the same values") {
      mesa::stack<int> a {stuff};
      mesa::stack<int> b {stuff};
      THEN( "the two objects should be considered equal (a<=b)" ) {
        REQUIRE (operator<=(a,b));
      }
      AND_THEN( "symmetry should also hold (b<=a)" ) {
        REQUIRE (operator<=(b,a));
      }
      AND_THEN( "the two objects should be considered equal (a>=b)" ) {
        REQUIRE (operator>=(a,b));
      }
      AND_THEN( "symmetry should also hold (b>=a)" ) {
        REQUIRE (operator>=(b,a));
      }
    }
    WHEN("there are 3 equal stacks, a == b == c") {
      mesa::stack<int> a {stuff};
      mesa::stack<int> b {stuff};
      mesa::stack<int> c {stuff};
      THEN( "equality is symmetric using <=" ) {
        CHECK ( (operator<=(a,b) && operator<=(b,a)) );
      }
      AND_THEN( "equality is transitive using <=" ) {
        REQUIRE ( (operator<=(a,b) && operator<=(b,c) && operator<=(a,c)) );
      }
      AND_THEN( "equality is symmetric using >=" ) {
        CHECK ( (operator>=(a,b) && operator>=(b,a)) );
      }
      AND_THEN( "equality is transitive using >=" ) {
        REQUIRE ( (operator>=(a,b) && operator>=(b,c) && operator>=(a,c)) );
      }
    }
  }
}

SCENARIO( "Check unequal stack comparisons using < and >") {
  GIVEN( "two unequal stacks" ) {
    WHEN("a = 1/3, b = 1/4") {
      mesa::stack<int> a;
      a.push(1);
      a.push(3);
      mesa::stack<int> b;
      b.push(1);
      b.push(4);
      THEN( "a < b" ) {
        REQUIRE (operator<(a,b));
      }
      AND_THEN( "b > a" ) {
        REQUIRE (operator>(b,a));
      }
    }
    WHEN("there are 3 unequal numbers, a != b != c") {
      mesa::stack<int> a;
      a.push(3);
      a.push(2);
      mesa::stack<int> b;
      b.push(9);
      b.push(2);
      mesa::stack<int> c;
      c.push(27);
      c.push(8);
      THEN( "a < b" ) {
        REQUIRE (operator<(a,b));
        REQUIRE_MESSAGE (operator>(b,a), "b is not greater than a");
      }
      AND_THEN( "b < c" ) {
        REQUIRE (operator<(b,c));
        REQUIRE_MESSAGE (operator>(c,b), "c is not greater than b");
      }
      AND_THEN( "a < c" ) {
        REQUIRE (operator<(a,c));
      }
      AND_THEN( "c < a" ) {
        REQUIRE (operator>(c,a));
      }
    }
  }
}


