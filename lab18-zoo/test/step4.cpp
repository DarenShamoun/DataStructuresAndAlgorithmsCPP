#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <algorithm>
#include <memory>
#include <vector>

#include <doctest.h>
#include <zoo.h>

SCENARIO( "Test make_animals") {
  WHEN( "a make_animals is called" ) {
    auto zoo = make_animals();

    THEN( "the vector returned should contain a Cat" ) {
      auto actual = std::find_if(zoo.begin(), zoo.end(), [] (const std::unique_ptr<Animal>& a) {
                    return a->name() == std::string("Fluffy");
                    });
      REQUIRE_MESSAGE(actual != zoo.end(), "Did not find a Cat named 'Fluffy'");
    }
    THEN( "the vector returned should contain a Dog" ) {
      auto actual = std::find_if(zoo.begin(), zoo.end(), [] (const std::unique_ptr<Animal>& a) {
                    return a->name() == std::string("Fido");
                    });
      REQUIRE_MESSAGE(actual != zoo.end(), "Did not find a Dog named 'Fido'");
    }
    THEN( "the vector returned should contain a Owl" ) {
      auto actual = std::find_if(zoo.begin(), zoo.end(), [] (const std::unique_ptr<Animal>& a) {
                    return a->name() == std::string("hootie");
                    });
      REQUIRE_MESSAGE(actual != zoo.end(), "Did not find a Owl named 'hootie'");
    }
    THEN( "the vector returned should contain a Wolf" ) {
      auto actual = std::find_if(zoo.begin(), zoo.end(), [] (const std::unique_ptr<Animal>& a) {
                    return a->name() == std::string("White Fang");
                    });
      REQUIRE_MESSAGE(actual != zoo.end(), "Did not find a Wolf named 'White Fang'");
    }
  }
}


