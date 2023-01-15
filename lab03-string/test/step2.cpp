#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <lab3.h>
#include <doctest.h>

#include <string>

SCENARIO( "Capitalize the first word if the text appears to be a sentence") {

  GIVEN( "typical strings" ) {

    WHEN( "a string does not end in a period" ) {
      THEN( "the string should be returned unchanged" ) {
        REQUIRE( sentence_case("howdy") == "howdy" );
        CHECK( sentence_case("hello, world") == "hello, world" );
        CHECK( sentence_case("can you hear me?") == "can you hear me?" );
        CHECK( sentence_case("woot!") == "woot!" );
        CHECK( sentence_case("this phrase ends in a space ") == "this phrase ends in a space " );
        CHECK( sentence_case("twas bryllyg, and Ye slythy toves Did gyre and gymble in ye wabe") == "twas bryllyg, and Ye slythy toves Did gyre and gymble in ye wabe" );
      }
    }

    WHEN( "strings end in a period" ) {
      THEN( "the first letter should be changed to uppercase" ) {
        REQUIRE( sentence_case("hello, world.") == "Hello, world." );
        REQUIRE( sentence_case("the rain in spain lays mainly on the plain.") == "The rain in spain lays mainly on the plain." );
      }
    }

  }

  GIVEN( "empty strings" ) {

    WHEN( "strings contain nothing" ) {
      std::string s;
      THEN( "return an empty string" ) {
        CHECK( sentence_case(s) == s );
        CHECK( sentence_case(s).empty() );
      }
    }

  }

}



