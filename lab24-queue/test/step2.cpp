#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/ring_buffer.h"


TEST_CASE("reading_empty_buffer_should_fail") 
{
    mesa::ring_buffer<int,1> buffer;

    REQUIRE_THROWS_AS(buffer.pop(), std::domain_error);
}

TEST_CASE("can_read_an_item_just_written") 
{
    mesa::ring_buffer<int,1> buffer;

    REQUIRE_NOTHROW(buffer.push(1));

    int expected = 1;
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("each_item_may_only_be_read_once") 
{
    mesa::ring_buffer<int,1> buffer;

    REQUIRE_NOTHROW(buffer.push(1));

    int expected = 1;
    REQUIRE(expected == buffer.pop());

    REQUIRE_THROWS_AS(buffer.pop(), std::domain_error);
}

TEST_CASE("items_are_read_in_the_order_they_are_written") 
{
    mesa::ring_buffer<int,2> buffer;

    REQUIRE_NOTHROW(buffer.push(1));
    REQUIRE_NOTHROW(buffer.push(2));

    int expected = 1;
    REQUIRE(expected == buffer.pop());

    expected = 2;
    REQUIRE(expected == buffer.pop());
}


TEST_CASE("full_buffer_cant_be_written") 
{
    mesa::ring_buffer<int,1> buffer;

    REQUIRE_NOTHROW(buffer.push(1));
    REQUIRE_THROWS_AS(buffer.push(2), std::domain_error);
}

TEST_CASE("a_read_frees_up_capacity_for_another_write") 
{
    mesa::ring_buffer<int,1> buffer;

    REQUIRE_NOTHROW(buffer.push(1));

    int expected = 1;
    REQUIRE(expected == buffer.pop());

    REQUIRE_NOTHROW(buffer.push(2));

    expected = 2;
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("read_position_is_maintained_even_across_multiple_writes") 
{
    mesa::ring_buffer<int,3> buffer;

    REQUIRE_NOTHROW(buffer.push(1));
    REQUIRE_NOTHROW(buffer.push(2));

    int expected = 1;
    REQUIRE(expected == buffer.pop());

    REQUIRE_NOTHROW(buffer.push(3));

    expected = 2;
    REQUIRE(expected == buffer.pop());

    expected = 3;
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("read_position_wraps_around") 
{
    mesa::ring_buffer<int,4> buffer;

    REQUIRE_NOTHROW(buffer.push(1));
    REQUIRE_NOTHROW(buffer.push(2));
    REQUIRE_NOTHROW(buffer.push(3));
    REQUIRE_NOTHROW(buffer.push(4));

    REQUIRE(1 == buffer.pop());

    REQUIRE_NOTHROW(buffer.push(5));

    REQUIRE(2 == buffer.pop());
    REQUIRE(3 == buffer.pop());

    REQUIRE_NOTHROW(buffer.push(6));
    REQUIRE_NOTHROW(buffer.push(7));
    REQUIRE_THROWS_AS(buffer.push(8), std::domain_error);
}

