#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include <string>

#include <doctest.h>
#include <student.h>

SCENARIO( "Fill classroom from stdin") {

  GIVEN( "The load_classroom function" ) {

    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input
      ("Alice 12345 96  80  97  83  85  81  89  91  91  74  92  89  87\nBob 67890 70  90  84  70  85  94  100 88  92\n");
    std::cin.rdbuf(input.rdbuf());
    auto v = load_classroom();
    std::cin.rdbuf(orig);

    student alice {"Alice", 12345, {96,80,97,83,85,81,89,91,91,74,92,89,87}};
    student bob {"Bob", 67890, {70,90,84,70,85,94,100,88,92}};

    WHEN( "the class is loaded" ) {
      THEN( "the classroom size should be 2" ) {
        REQUIRE (v.size() == 2 );
      }
      AND_THEN( "Alice should be the first element in the vector" ) {
        REQUIRE (v[0]->name == alice.name );
        REQUIRE (v[0]->id == alice.id );
        REQUIRE (v[0]->grades == alice.grades );
      }
      AND_THEN( "Bob should be the next" ) {
        REQUIRE (v.back()->name == bob.name );
        REQUIRE (v.back()->id == bob.id );
        REQUIRE (v.back()->grades == bob.grades );
      }
    }

  }
}



