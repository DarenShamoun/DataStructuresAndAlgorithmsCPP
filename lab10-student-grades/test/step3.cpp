#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <student.h>
#include <doctest.h>

SCENARIO( "Stream a classroom") {

  GIVEN( "a classroom" ) {
    student a {"Alice", 1, {1,2,3}};
    student b {"Bob", 67890, {70,90,84,70,85,94,100,88,92}};
    student c {"Clara", 98765, {66,100,94,82,98,87,83,100,90,86}};

    std::vector<student*> v = {&a, &b, &c};

    WHEN( "the students are Alice, Bob, and Clara" ) {
      std::ostringstream os;
      os << v;
      auto actual = os.str();
      std::string line1 = "Name:\tAlice\tId:\t1\tAvg:\t2";
      std::string line2 = "Name:\tBob\tId:\t67890\tAvg:\t85.89";
      std::string line3 = "Name:\tClara\tId:\t98765\tAvg:\t88.6";
      THEN( "the first line should contain Alice data" ) {
        auto end = actual.find("2")+1;
        std::string actual_line = actual.substr(0, end);
        CHECK(actual_line == line1);
      }
      AND_THEN( "the second line should contain Bob data" ) {
        auto start = actual.find("Bob")-6;
        std::string actual_line = actual.substr(start, line2.size());
        CHECK(actual_line == line2);
      }
      AND_THEN( "the last line should contain Clara data" ) {
        auto start = actual.find("Clara")-6;
        std::string actual_line = actual.substr(start, line3.size());
        CHECK(actual_line == line3);
      }
    }
  }
}


