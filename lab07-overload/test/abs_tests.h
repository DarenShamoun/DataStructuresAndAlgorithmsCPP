#pragma once

// These tests are shared in both step2 & step 3 execuatables
// step 2 uses overloads
// step 3 uses a template

SCENARIO( "Verify mesa::abs is constexpr") {
  GIVEN( "a valid input" ) {
    WHEN( "the function is called" ) {

      THEN( "an int returned can be assigned to a constexpr " ) {
        constexpr int actual = mesa::abs(1);
        // a test is redundant, but silences a warning
        // This is really a compiler test
        REQUIRE( actual == 1);
      }

      AND_THEN( "a char returned can be assigned to a constexpr " ) {
        constexpr char actual = mesa::abs(45);
        REQUIRE( actual == 45);
      }

      AND_THEN( "a double returned can be assigned to a constexpr " ) {
        constexpr double actual = mesa::abs(1.0);
        REQUIRE( actual == 1);
      }

      AND_THEN( "a long double returned can be assigned to a constexpr " ) {
        constexpr long double long_double_value = 3.14e88;
        constexpr long double actual = mesa::abs(long_double_value);
        REQUIRE( actual == long_double_value);
      }

    }
  }
}

SCENARIO( "take the absolute value of a number") {

  GIVEN( "signed integral types" ) {
    WHEN( "an int is positive" ) {
      int int_value = 3;
      int expected = int_value;
      THEN( "the same value should be returned" ) {
        REQUIRE( expected  == mesa::abs(int_value));
      }
    }
    WHEN( "an int is negative" ) {
      int int_value = -5;
      int expected = -int_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(int_value));
      }
    }
  
    WHEN( "an int32_t is positive" ) {
      int32_t int32_t_value = 13;
      int32_t expected = int32_t_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(int32_t_value));
      }
    }
    WHEN( "an int32_t is negative" ) {
      int32_t int32_t_value = -8;
      int32_t expected = -int32_t_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(int32_t_value));
      }
    }

    WHEN( "a short is positive" ) {
      short short_value = 31123;
      short expected = short_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(short_value));
      }
    }
    WHEN( "a short is negative" ) {
      short short_value = -31123;
      short expected = -short_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(short_value));
      }
    }

    WHEN( "a long is positive" ) {
      long long_value = 8675309;
      long expected = long_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(long_value));
      }
    }
    WHEN( "a long is negative" ) {
      long long_value = -6060842;
      long expected = -long_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(long_value));
      }
    }

    WHEN( "a char is positive" ) {
      char char_value = 127;
      char expected = char_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(char_value));
      }
    }
    WHEN( "a char is negative" ) {
      char char_value = -92;
      char expected = -char_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(char_value));
      }
    }

  }

  GIVEN( "unsigned integral types" ) {
    WHEN( "an unsigned int is positive" ) {
      unsigned int unsigned_value = 997;
      unsigned int expected = unsigned_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(unsigned_value));
      }
    }
    WHEN( "an unsigned int is negative" ) {
      unsigned int unsigned_value = -42;
      unsigned int expected = unsigned_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(unsigned_value));
      }
    }
  
    WHEN( "an uint32_t is positive" ) {
      uint32_t uint32_t_value = 314159;
      uint32_t expected = uint32_t_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(uint32_t_value));
      }
    }
    WHEN( "an uint32_t is negative" ) {
      uint32_t uint32_t_value = -314159;
      uint32_t expected = uint32_t_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(uint32_t_value));
      }
    }
    WHEN( "a unsigned long is positive" ) {
      unsigned long unsigned_long_value = 6060842;
      unsigned long expected = unsigned_long_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(unsigned_long_value));
      }
    }
    WHEN( "a unsigned long is negative" ) {
      unsigned long unsigned_long_value = -6060842;
      unsigned long expected = unsigned_long_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(unsigned_long_value));
      }
    }

    WHEN( "a unsigned char is positive" ) {
      unsigned char unsigned_char_value = 34;
      unsigned char expected = unsigned_char_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(unsigned_char_value));
      }
    }
    WHEN( "a unsigned char is negative" ) {
      unsigned char unsigned_char_value = -21;
      unsigned char expected = unsigned_char_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(unsigned_char_value));
      }
    }
  }

  GIVEN( "floating point types" ) {
    WHEN( "a float is positive" ) {
      float float_value = 3;
      float expected = float_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(float_value));
      }
    }
    WHEN( "a float is negative" ) {
      float float_value = -3;
      float expected = -float_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(float_value));
      }
    }
    WHEN( "a double is positive" ) {
      double double_value = 2.06e23;
      double expected = double_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(double_value));
      }
    }
    WHEN( "a double is negative" ) {
      double double_value = -3.1415e8;
      double expected = -double_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(double_value));
      }
    }
    WHEN( "a long double is positive" ) {
      long double long_double_value = 3.14e88;
      long double expected = long_double_value;
      THEN( "the same value should be returned" ) {
        CHECK( expected  == mesa::abs(long_double_value));
      }
    }
    WHEN( "a long double is negative" ) {
      long double long_double_value = -3.14e88;
      long double expected = -long_double_value;
      THEN( "the absolute value should be returned" ) {
        CHECK( expected  == mesa::abs(long_double_value));
      }
    }
  
  }

}


