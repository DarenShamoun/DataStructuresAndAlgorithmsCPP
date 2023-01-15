#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <doctest.h>
#include <zoo.h>

SCENARIO( "treat animals") {
  GIVEN( "an vector of unique_ptr<Animal>" ) {
    auto zoo = make_animals();
    WHEN( "n is 1" ) {
      THEN( "each animal should complain about a shot" ) {
        std::ostringstream actual;
        auto cout_buff = std::cout.rdbuf(); // save pointer to std::cout buffer
        std::cout.rdbuf(actual.rdbuf());     // sub local for cout
        treat_animals(zoo);
        std::cout.rdbuf(cout_buff);          // restore cout

        std::string expected = "meow.\n";
        auto pos = actual.str().find_first_of(expected); 
        REQUIRE_MESSAGE(pos != std::string::npos, "Did not give a Cat a shot");
        
        expected = "arf, arf!\n";
        pos = actual.str().find_first_of(expected); 
        REQUIRE_MESSAGE(pos != std::string::npos, "Did not give a Dog a shot");
        
        expected = "Hoot!\n";
        pos = actual.str().find_first_of(expected); 
        REQUIRE_MESSAGE(pos != std::string::npos, "Did not give a Owl a shot");
        
        expected = "Woo woo woooooooo!\n";
        pos = actual.str().find_first_of(expected); 
        REQUIRE_MESSAGE(pos != std::string::npos, "Did not give a Wolf a shot");
      }
    }
  }
}


