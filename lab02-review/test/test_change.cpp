#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include <doctest.h>
#include <change.h>

SCENARIO( "make change") {
  WHEN ("buy_stuff() is called") {
    THEN("it should have no funds remaining") {
      auto actual = buy_stuff();
      CHECK (actual.funds == 0);
      CHECK (actual.items == 4);
    }
  }
}
