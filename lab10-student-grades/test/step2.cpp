#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <string>

#include <doctest.h>
#include <student.h>

SCENARIO( "Stream one student") {

  GIVEN( "a student" ) {

    WHEN( "the student = {Alice,1,{1,2,3}" ) {
      student s {"Alice", 1, {1,2,3}};
      student* p = &s;
      THEN( "the student should stream" ) {
        std::ostringstream os;
        os << p;
        std::string expected = "Name:\tAlice\tId:\t1\tAvg:\t2";
        auto actual = os.str();
        while (actual.back() != '2') actual.pop_back();
        CHECK(actual == expected);
        
      }
    }

    WHEN( "the student = {Bob,67890,{70,90,84,70,85,94,100,88,92}" ) {
      student s {"Bob", 67890, {70,90,84,70,85,94,100,88,92}};
      student* p = &s;
      THEN( "the student should stream" ) {
        std::ostringstream os;
        os << p;
        auto actual = os.str();
        actual.pop_back();
        std::string expected = "Name:\tBob\tId:\t67890\tAvg:\t85.89";
        CHECK(actual == expected);
        
      }
    }

    WHEN( "the student = {Clara,98765,{66,100,94,82,98,87,83,100,90,86}" ) {
      student s {"Clara", 98765, {66,100,94,82,98,87,83,100,90,86}};
      student* p = &s;
      THEN( "the student should stream" ) {
        std::ostringstream os;
        os << p;
        auto actual = os.str();
        std::string expected = "Name:\tClara\tId:\t98765\tAvg:\t88.6";
        while (actual.back() != '6') actual.pop_back();
        CHECK(actual == expected);
        
      }
    }


  }
}


