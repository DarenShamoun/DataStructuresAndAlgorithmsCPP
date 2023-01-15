#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include <doctest.h>
#include <echo.h>

SCENARIO( "echo something") {
  WHEN ("echo() is called") {
    THEN("it should echo its input arguments") {
      std::string expected = "hello, world!";
      auto actual = echo(expected);
      CHECK (actual == expected);
    }
  }
}
