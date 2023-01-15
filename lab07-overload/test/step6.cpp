
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <string>
#include <doctest.h>

#include <lab7.h>

SCENARIO( "stream a point as bytes") {

  GIVEN( "a string stream and a point" ) {
      mesa::point a {0,0};
      std::stringstream actual;
      std::string expected = "[0,0]";

      actual << a;
      
      THEN( "the stream should contain '[0,0]'" ) {
        REQUIRE( actual.str() == expected );
      }
  
    WHEN( "the x and y are different" ) {
      mesa::point a {-2,-3};
      std::stringstream actual;
      std::string expected = "[-2,-3]";
      actual << a;
      THEN( "the x part should stream first" ) {
        REQUIRE( actual.str() == expected );
      }
    }
  
  }

}


