#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <classes.h>

SCENARIO( "Test Dog class") {
  
  WHEN( "a default Dog is created" ) {
    dog d;
    THEN( "the default name == 'Fido'" ) {
      REQUIRE (d.name() == "Fido");
    }
    THEN( "the default Size == 'Size::MEDIUM'" ) {
      REQUIRE (d.size() == dog_size::MEDIUM);
    }
  }

  WHEN( "a LARGE Dog is created with name 'Max'" ) {
    dog d {"Max", dog_size::LARGE};
    THEN( "the name == 'Max'" ) {
      REQUIRE (d.name() == "Max");
    }
    THEN( "the Size == 'Size::LARGE'" ) {
      REQUIRE (d.size() == dog_size::LARGE);
    }
  }

  WHEN( "a SMALL Dog is created with name 'Princess'" ) {
    dog d {"Princess", dog_size::SMALL};
    THEN( "the name == 'Princess'" ) {
      REQUIRE (d.name() == "Princess");
    }
    THEN( "the Size == 'Size::SMALL'" ) {
      REQUIRE (d.size() == dog_size::SMALL);
    }
  }

  WHEN( "a Dog is created with name 'Princess'" ) {
    dog d {"Princess", dog_size::SMALL};
    THEN( "the name == 'Princess'" ) {
      REQUIRE (d.name() == "Princess");
    }
    d.name("Fluffy");
    AND_WHEN( "the the name is changed to 'Fluffy'" ) {
      THEN( "the name should now equal 'Fluffy'" ) {
        REQUIRE (d.name() == "Fluffy");
      }
    }
  }
  WHEN( "a LARGE Dog is created" ) {
    dog d {"Cujo", dog_size::LARGE};
    THEN( "bark should return 'Woof'" ) {
      REQUIRE (d.bark() == "Woof");
    }
  }

  WHEN( "a Medium Dog is created" ) {
    dog d {"Balto", dog_size::MEDIUM};
    THEN( "bark should return 'Ruff'" ) {
      REQUIRE (d.bark() == "Ruff");
    }
  }

  WHEN( "a Small Dog is created" ) {
    dog d {"Benji", dog_size::SMALL};
    THEN( "bark should return 'Yip'" ) {
      REQUIRE (d.bark() == "Yip");
    }
  }


}


