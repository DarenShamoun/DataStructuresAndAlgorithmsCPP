#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <utility>

#include <doctest.h>
#include "../src/bag.h"

namespace{
  constexpr int default_capacity = 0;
} // end anonymous namespace

SCENARIO( "Test mesa::bag<T> value_type") {

  WHEN( "mesa::bag is declared with an int type" ) {
    typedef int int_type;
    mesa::bag<int_type> actual;
    THEN( "the bag compiles" ) {
      REQUIRE_MESSAGE(&actual == &actual, "placeholder for compilation");
    } AND_THEN ( "the value_type is 'int'" ) {
      REQUIRE_MESSAGE( (std::is_same<mesa::bag<int>::value_type, int>() == true), 
          "expected 'value_type' to be 'int'");
    }
  }

  WHEN( "mesa::bag is declared with other types" ) {
    THEN ( "the value_type could be 'double'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::bag<double>::value_type, double>() == true), 
          "expected 'value_type' to be 'double'");
    } AND_THEN ( "the value_type could be 'char'" ) {
      CHECK_MESSAGE( (std::is_same<mesa::bag<char>::value_type, char>() == true), 
          "expected 'value_type' to be 'char'");
    }
  }

}

SCENARIO( "Test mesa::bag size and capacity" ) {

  WHEN( "constructing mesa::bag<int>" ) {
    mesa::bag<int> actual;
    THEN ("empty should return true and size = 16") {
      CHECK(actual.empty() == true);
      CHECK(actual.size() == 0);
      CHECK(actual.capacity() == default_capacity);
    } AND_THEN ( "begin and end should refer to the same position" ) {
      CHECK(actual.begin() == actual.end());
    }
  }

  WHEN( "constructing mesa::bag<std::string>" ) {
    mesa::bag<std::string> actual;
    THEN ("empty should return false and size = 16") {
      CHECK(actual.empty() == true);
      CHECK(actual.size() == 0);
      CHECK(actual.capacity() == default_capacity);
    }
  }

}

SCENARIO( "Test mesa::bag data pointer" ) {
  WHEN( "constructing an empty mesa::bag<double>" ) {
    THEN ("the std::distance between begin and end should equal the size") {
      mesa::bag<double> actual;
      CHECK(std::distance(actual.begin(), actual.end()) == actual.size());
    }
  }
}

SCENARIO( "Test mesa::bag<T> initializer list constructor" ) {

  WHEN( "mesa::bag is explicitly constructed from a list" ) {
    auto actual = mesa::bag<size_t>     {21,13,8,5,3,2,1,1,0};
    auto expected = std::vector<size_t> {21,13,8,5,3,2,1,1,0};
    THEN ("size, empty, and capacity should be correct") {
      CHECK(actual.empty() == expected.empty());
      CHECK(actual.size() == expected.size());
      CHECK(actual.capacity() == expected.capacity());
    }
    AND_THEN ("all int elements should match list using operator[]") {
      for (int i = 0; i < int(expected.size()); ++i) {
        CAPTURE(i);
        CHECK(actual[i] == expected[i]);
      }
    }
    AND_THEN ("all int elements should match list using at()") {
      for (int i = 0; i < int(expected.size()); ++i) {
        CAPTURE(i);
        CHECK(actual.at(i) == expected.at(i));
      }
    }
    AND_THEN ("the std::distance between begin and end should equal the size") {
      CHECK(std::distance(actual.data(), actual.end()) == actual.size());
    }
  }

}

SCENARIO( "Test const mesa::bag<T>" ) {

  WHEN( "mesa::bag is explicitly constructed from a list" ) {
    const auto actual = mesa::bag<size_t>     {21,13,8,5,3,2,1,1,0};
    const auto expected = std::vector<size_t> {21,13,8,5,3,2,1,1,0};
    THEN ("size, empty, and capacity should be correct") {
      CHECK(actual.empty() == expected.empty());
      CHECK(actual.size() == expected.size());
      CHECK(actual.capacity() == expected.capacity());
    }
    AND_THEN ("all int elements can be retrieved from const operator[]") {
      for (int i = 0; i < int(expected.size()); ++i) {
        CAPTURE(i);
        CHECK(actual[i] == expected[i]);
      }
    }
    AND_THEN ("all int elements can be retrieved from const at()") {
      for (int i = 0; i < int(expected.size()); ++i) {
        CAPTURE(i);
        CHECK(actual.at(i) == expected.at(i));
      }
    }
    AND_THEN ("the std::distance between begin and end should equal the size") {
      CHECK(std::distance(actual.begin(), actual.end()) == actual.size());
    }
  }

}

SCENARIO( "Check bag equality") {
  GIVEN( "a single bag" ) {
    mesa::bag<int> a {1,3};
    WHEN("compared with itself") {
      THEN( "it should be considered equal (reflexive property)" ) {
        REQUIRE (operator==(a,a));
      }
    }
  }

  GIVEN( "eqivalent bags" ) {
    WHEN("two different bags store the same values") {
      mesa::bag<int> a {1,3,2,5,8};
      mesa::bag<int> b {1,3,2,5,8};
      THEN( "the two objects should be considered equal (a==b)" ) {
        REQUIRE (operator==(a,b));
      }
      AND_THEN( "symmetry should also hold (b==a)" ) {
        REQUIRE (operator==(b,a));
      }
    }
    WHEN("there are 3 equal bags, a == b == c") {
      mesa::bag<int> a {1,3,2,5,8,13,21,34};
      mesa::bag<int> b {1,3,2,5,8,13,21,34};
      mesa::bag<int> c {1,3,2,5,8,13,21,34};
      THEN( "equality is symmetric" ) {
        REQUIRE ( (operator==(a,b) && operator==(b,a)) );
      }
      AND_THEN( "equality is transitive" ) {
        REQUIRE ( (operator==(a,b) && operator==(b,c) && operator==(a,c)) );
      }
    }
  }

  GIVEN( "two unequal bags" ) {
    WHEN("a = 1/3, b = 1/4") {
      mesa::bag<int> a {1,3};
      mesa::bag<int> b {1,4};
      THEN( "the two bags should be considered not equal (a!=b)" ) {
        REQUIRE (operator!=(a,b));
      }
      AND_THEN( "symmetry should also hold (b!=a)" ) {
        REQUIRE (operator!=(b,a));
      }
    }
    WHEN("there are 3 unequal numbers, a != b != c") {
      mesa::bag<int> a {2,3};
      mesa::bag<int> b {2,9};
      mesa::bag<int> c {8,27};
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



SCENARIO( "Check equal bag comparisons using <= and >=") {
  GIVEN( "a single bag" ) {
    mesa::bag<int> a {1,3};
    WHEN("compared with itself") {
      THEN( "it should be considered equal (<= test) (reflexive property)" ) {
        REQUIRE (operator<=(a,a));
      } AND_THEN( "it should be considered equal (>= test)" ) {
        REQUIRE (operator>=(a,a));
      }
    }
  }

  GIVEN( "eqivalent bags" ) {
    WHEN("two different bags store the same values") {
      mesa::bag<int> a {1,3,2,5,8};
      mesa::bag<int> b {1,3,2,5,8};
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
    WHEN("there are 3 equal bags, a == b == c") {
      mesa::bag<int> a {1,3,2,5,8,13,21,34};
      mesa::bag<int> b {1,3,2,5,8,13,21,34};
      mesa::bag<int> c {1,3,2,5,8,13,21,34};
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

SCENARIO( "Check unequal bag comparisons using < and >") {
  GIVEN( "two unequal bags" ) {
    WHEN("a = 1/3, b = 1/4") {
      mesa::bag<int> a {1,3};
      mesa::bag<int> b {1,4};
      THEN( "a < b" ) {
        REQUIRE (operator<(a,b));
      }
      AND_THEN( "b > a" ) {
        REQUIRE (operator>(b,a));
      }
    }
    WHEN("there are 3 unequal numbers, a != b != c") {
      mesa::bag<int> a {2,3};
      mesa::bag<int> b {2,9};
      mesa::bag<int> c {8,27};
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


SCENARIO( "Test mesa::bag size and capacity when capacity is set" ) {

  constexpr int test_capacity = 10;
  WHEN( "constructing mesa::bag<int>(10)" ) {
    mesa::bag<int> actual(test_capacity);
    THEN ("empty should return false and capacity and size = 10") {
      CHECK(actual.empty() == false);
    }
    THEN ("empty should return false and capacity and size = 10") {
      CHECK(actual.size() == test_capacity);
      CHECK(actual.capacity() == test_capacity);
    }
    AND_THEN ( "all elements should be default initialized" ) {
      for (int i = 0; i < test_capacity; ++i) {
        REQUIRE_MESSAGE(actual[i] == 0, 
            "could not access element " << i << " using operator[]");
      }
    }
  }

}

SCENARIO( "Test mesa::bag copy constructor" ) {

  WHEN( "a copy is made" ) {
    mesa::bag<int> original {3,1,4,1,5,9};
    mesa::bag<int> copy = original;
    THEN ("the copy should have the same attributes as the original") {
      CHECK(copy.empty() == original.empty());
      CHECK(copy.size() == original.size());
      CHECK(copy.capacity() == original.capacity());
    } AND_THEN ( "all elements should be the same as the original" ) {
      for (int i = 0; i < int(original.size()); ++i) {
        REQUIRE_MESSAGE(copy[i] == original[i], "could not access element " << i << " using operator[]");
      }
    }
  }

  WHEN( "a copy is made between 2 cont bags" ) {
    const mesa::bag<int> original {3,1,4,1,5,9};
    const mesa::bag<int> copy = original;
    THEN ("the copy should have the same attributes as the original") {
      CHECK(copy.empty() == original.empty());
      CHECK(copy.size() == original.size());
      CHECK(copy.capacity() == original.capacity());
    } AND_THEN ( "all elements should be the same as the original" ) {
      for (int i = 0; i < int(original.size()); ++i) {
        REQUIRE_MESSAGE(copy[i] == original[i], "could not access element " << i << " using operator[]");
      }
    }
  }

}

SCENARIO( "Test mesa::bag copy assignment" ) {

  WHEN( "a copy is made" ) {
    mesa::bag<int> original {3,1,4,1,5,9};
    mesa::bag<int> copy {1,2,3};
    copy = original;
    THEN ("the copy should have the same attributes as the original") {
      CHECK(copy.empty() == original.empty());
      CHECK(copy.size() == original.size());
      CHECK(copy.capacity() == original.capacity());
    } AND_THEN ( "all elements should be the same as the original" ) {
      for (int i = 0; i < int(original.size()); ++i) {
        REQUIRE_MESSAGE(copy[i] == original[i], "could not access element " << i << " using operator[]");
      }
    }
  }

  WHEN( "a copy is made with an initialization list" ) {
    auto original = mesa::bag<double>{3,1,4,1,5,9};
    auto copy     = mesa::bag<double>{1,2,3};
    copy = original;
    THEN ("the copy should have the same attributes as the original") {
      CHECK(copy.empty() == original.empty());
      CHECK(copy.size() == original.size());
      CHECK(copy.capacity() == original.capacity());
    } AND_THEN ( "all elements should be the same as the original" ) {
      for (int i = 0; i < int(original.size()); ++i) {
        REQUIRE_MESSAGE(copy[i] == original[i], "could not access element " << i << " using operator[]");
      }
    }
  }

}

