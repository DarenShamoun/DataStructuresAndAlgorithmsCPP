#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/ring_buffer.h"


TEST_CASE("overwrite_acts_like_write_on_non_full_buffer") 
{
    mesa::ring_buffer<int,2> buffer;

    REQUIRE_NOTHROW(buffer.push(1));

    buffer.overwrite(2);

    int expected = 1;
    REQUIRE(expected == buffer.pop());

    expected = 2;
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("overwrite_replaces_the_oldest_item_on_full_buffer") 
{
    mesa::ring_buffer<int,2> buffer;

    REQUIRE_NOTHROW(buffer.push(1));
    REQUIRE_NOTHROW(buffer.push(2));

    buffer.overwrite(3);

    int expected = 2;
    REQUIRE(expected == buffer.pop());

    expected = 3;
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("overwrite_replaces_the_oldest_item_remaining_in_buffer_following_a_read") 
{
    mesa::ring_buffer<int,3> buffer;

    REQUIRE_NOTHROW(buffer.push(1));
    REQUIRE_NOTHROW(buffer.push(2));
    REQUIRE_NOTHROW(buffer.push(3));

    int expected = 1;
    REQUIRE(expected == buffer.pop());

    REQUIRE_NOTHROW(buffer.push(4));

    buffer.overwrite(5);

    expected = 3;
    REQUIRE(expected == buffer.pop());

    expected = 4;
    REQUIRE(expected == buffer.pop());

    expected = 5;
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("full_buffer_cant_be_written_after_overwrite") 
{
    mesa::ring_buffer<int,1> buffer;

    REQUIRE_NOTHROW(buffer.push(1));
    buffer.overwrite(2);
    REQUIRE_THROWS_AS(buffer.push(3), std::domain_error);

    int expected = 2;
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("check_correctness_with_string_type") 
{
    mesa::ring_buffer<std::string,3> buffer;

    REQUIRE_NOTHROW(buffer.push("hello"));
    REQUIRE_NOTHROW(buffer.push("world"));
    REQUIRE_NOTHROW(buffer.push("zombies"));

    std::string expected = "hello";
    REQUIRE(expected == buffer.pop());

    REQUIRE_NOTHROW(buffer.push("pants"));

    buffer.overwrite("banana");

    expected = "zombies";
    REQUIRE(expected == buffer.pop());

    expected = "pants";
    REQUIRE(expected == buffer.pop());

    expected = "banana";
    REQUIRE(expected == buffer.pop());
}

TEST_CASE("initial_clear_does_not_affect_wrapping_around")
{
    mesa::ring_buffer<int,2> buffer;

    buffer.clear();

    REQUIRE_NOTHROW(buffer.push(1));
    REQUIRE_NOTHROW(buffer.push(2));

    buffer.overwrite(3);
    buffer.overwrite(4);

    int expected = 3;
    REQUIRE(expected == buffer.pop());

    expected = 4;
    REQUIRE(expected == buffer.pop());

    REQUIRE_THROWS_AS(buffer.pop(), std::domain_error);
}



