cmake_minimum_required(VERSION 3.12)

project(test_cases VERSION 1.0.0 LANGUAGES CXX)

make_test(step2 util.cpp util.h)
make_test(step3 util.cpp util.h)
make_test(step4 util.cpp util.h)
make_test(step5 util.cpp util.h)
make_test(step6 util.cpp util.h)

