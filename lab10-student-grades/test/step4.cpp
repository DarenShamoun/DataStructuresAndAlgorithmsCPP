#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <string>

#include <doctest.h>
#include <student.h>

SCENARIO( "Add student to a classroom") {

  GIVEN( "an empty classroom and an input stream" ) {
    std::vector<student*> v;

    student alice {"Alice", 12345, {96,80,97,83,85,81,89,91,91,74,92,89,87}};
    student bob {"Bob", 67890, {70,90,84,70,85,94,100,88,92}};
    student clara {"Clara", 98765, {66,100,94,82,98,87,83,100,90,86}};


    WHEN( "the student is Alice" ) {
      std::istringstream buf ("Alice 12345 96  80  97  83  85  81  89  91  91  74  92  89  87");
      add_student(&v, buf);
      THEN( "Alice should be the first element in the vector" ) {
        REQUIRE (v[0]->name == alice.name );
        REQUIRE (v[0]->id == alice.id );
        REQUIRE (v[0]->grades == alice.grades );
      }
    }

    WHEN( "the student Bob is added after Alice" ) {
      std::istringstream buf1 ("Alice 12345 96  80  97  83  85  81  89  91  91  74  92  89  87");
      std::istringstream buf2 ("Bob 67890 70  90  84  70  85  94  100 88  92");
      add_student(&v, buf1);
      add_student(&v, buf2);
      THEN( "The classroom size should be 2" ) {
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


