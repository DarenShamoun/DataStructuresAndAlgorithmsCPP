#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <utility>
#include <doctest.h>
#include "../src/ring_buffer.h"


TEST_CASE("items_cleared_out_of_buffer_cant_be_read") 
{
    mesa::ring_buffer<int,1> buffer;

    REQUIRE_NOTHROW(buffer.push(1));

    buffer.clear();

    REQUIRE_THROWS_AS(buffer.pop(), std::domain_error);
}

TEST_CASE("clear_frees_up_capacity_for_another_write") 
{
    mesa::ring_buffer<int,1> buffer;

    REQUIRE_NOTHROW(buffer.push(1));

    buffer.clear();

    REQUIRE_NOTHROW(buffer.push(2));

    int expected = 2;
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("clear_does_nothing_on_empty_buffer") 
{
    mesa::ring_buffer<int,1> buffer;

    buffer.clear();

    REQUIRE_NOTHROW(buffer.push(1));

    int expected = 1;
    REQUIRE(expected == buffer.pop());
}



