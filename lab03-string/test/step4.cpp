#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <lab3.h>
#include <doctest.h>

#include <string>

SCENARIO( "Format simple 2 word names") {

  GIVEN( "typical strings" ) {

    WHEN( "a string does not contain exactly 2 words" ) {
      THEN( "the string should be returned unchanged" ) {
        REQUIRE( name_format("howdy") == "howdy" );
        CHECK( name_format("can you hear me?") == "can you hear me?" );
        CHECK( name_format("woot!") == "woot!" );
        CHECK( name_format("this phrase ends in a space ") == "this phrase ends in a space " );
        CHECK( name_format("twas bryllyg, and Ye slythy toves Did gyre and gymble in ye wabe") == "twas bryllyg, and Ye slythy toves Did gyre and gymble in ye wabe" );
      }
    }

    WHEN( "strings contain exactly 2 words, separated by a space" ) {
      THEN( "format the string as Lastname, F." ) {
        REQUIRE( name_format("alex stepanov") == "Stepanov, A." );
        CHECK( name_format("edsger dijkstra") == "Dijkstra, E." );
        CHECK( name_format("hello world") == "World, H." );
      }
    }

    WHEN( "strings are names in a non-latin characterset" ) {
      THEN( "name formatting should be locale specific" ) {
        CHECK( name_format("antonín dvořák") == "Dvořák, A." );
        CHECK( name_format("devi lakṣmī") == "Lakṣmī, D." );
      }
    }

  }

  GIVEN( "empty strings" ) {

    WHEN( "strings contain nothing" ) {
      std::string s;
      THEN( "return an empty string" ) {
        CHECK( name_format(s) == s );
        CHECK( name_format(s).empty() );
      }
    }

  }

}



