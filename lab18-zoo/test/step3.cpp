#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <doctest.h>
#include <zoo.h>

SCENARIO( "Play with pets") {
  GIVEN( "an vector of Pet*" ) {
    auto pets = make_pets();
    WHEN( "n is 1" ) {
      THEN( "each pet should be played with once" ) {
        std::ostringstream actual;
        auto cout_buff = std::cout.rdbuf(); // save pointer to std::cout buffer
        std::cout.rdbuf(actual.rdbuf());     // sub local for cout
        play_with_pets(pets, 1);
        std::cout.rdbuf(cout_buff);          // restore cout

        std::string expected = "cuddle, purr ...\n";
        auto pos = actual.str().find_first_of(expected); 
        REQUIRE_MESSAGE(pos != std::string::npos, "Did not play with a Cat");
        
        expected = "fetch!!\n";
        pos = actual.str().find_first_of(expected); 
        REQUIRE_MESSAGE(pos != std::string::npos, "Did not play with a Dog");
        
        expected = "swim ...\n";
        pos = actual.str().find_first_of(expected); 
        REQUIRE_MESSAGE(pos != std::string::npos, "Did not play with a Fish");
        
        expected = "beep!\n";
        pos = actual.str().find_first_of(expected); 
        REQUIRE_MESSAGE(pos != std::string::npos, "Did not play with a RoboDog");
      }
    }

    WHEN( "n is 2" ) {
      THEN( "each pet should be played with twice" ) {
        std::ostringstream actual;
        auto cout_buff = std::cout.rdbuf(); // save pointer to std::cout buffer
        std::cout.rdbuf(actual.rdbuf());     // sub local for cout
        play_with_pets(pets, 2);
        std::cout.rdbuf(cout_buff);          // restore cout

        std::string expected = "cuddle, purr ...\n";
        auto first = actual.str().find_first_of(expected); 
        auto last = actual.str().find_last_of(expected); 
        CHECK_MESSAGE(first != std::string::npos, "Did not play with a Cat");
        CHECK_MESSAGE(last != first, "Did not play with a Cat a second time");
        
        expected = "fetch!!\n";
        first = actual.str().find_first_of(expected); 
        last = actual.str().find_last_of(expected); 
        CHECK_MESSAGE(first != std::string::npos, "Did not play with a Dog");
        CHECK_MESSAGE(last != std::string::npos, "Did not play with a Dog a second time");
        CHECK_MESSAGE(last != first, "Did not play with a Dog a second time");
        
        expected = "swim ...\n";
        first = actual.str().find_first_of(expected); 
        last = actual.str().find_last_of(expected); 
        CHECK_MESSAGE(first != std::string::npos, "Did not play with a Fish");
        CHECK_MESSAGE(last != std::string::npos, "Did not play with a Fish a second time");
        CHECK_MESSAGE(last != first, "Did not play with a Fish a second time");
        
        expected = "beep!\n";
        first = actual.str().find_first_of(expected); 
        last = actual.str().find_last_of(expected); 
        CHECK_MESSAGE(first != std::string::npos, "Did not play with a RoboDog");
        CHECK_MESSAGE(last != std::string::npos, "Did not play with a RoboDog a second time");
        CHECK_MESSAGE(last != first, "Did not play with a RoboDog a second time");
      }
    }
  }
}


