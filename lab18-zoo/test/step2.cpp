#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <algorithm>
#include <vector>

#include <doctest.h>
#include <zoo.h>

SCENARIO( "Test make_pets") {
  WHEN( "a make_pets is called" ) {
    auto pets = make_pets();

    THEN( "the vector returned should contain a Cat" ) {
      auto actual = std::find_if(pets.begin(), pets.end(), [] (Pet* p) {
                    return p->name() == std::string("Fluffy");
                    });
      REQUIRE_MESSAGE(actual != pets.end(), "Did not find a Cat named 'Fluffy'");
    }
    THEN( "the vector returned should contain a Dog" ) {
      auto actual = std::find_if(pets.begin(), pets.end(), [] (Pet* p) {
                    return p->name() == std::string("Fido");
                    });
      REQUIRE_MESSAGE(actual != pets.end(), "Did not find a Dog named 'Fido'");
    }
    THEN( "the vector returned should contain a Fish" ) {
      auto actual = std::find_if(pets.begin(), pets.end(), [] (Pet* p) {
                    return p->name() == std::string("Jaws");
                    });
      REQUIRE_MESSAGE(actual != pets.end(), "Did not find a Fish named 'Jaws'");
    }
    THEN( "the vector returned should contain a RoboDog" ) {
      auto actual = std::find_if(pets.begin(), pets.end(), [] (Pet* p) {
                    return p->name() == std::string("Robie");
                    });
      REQUIRE_MESSAGE(actual != pets.end(), "Did not find a RoboDog named 'Robie'");
    }
  }
}


