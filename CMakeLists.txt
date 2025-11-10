cmake_minimum_required(VERSION 3.10)
project(LAB5 VERSION 0.1.0 LANGUAGES CXX)

enable_testing()

find_package(GTest REQUIRED)

add_executable(main src/main.cpp)
add_library(MainLib src/main.cpp)

target_compile_definitions(MainLib PRIVATE UNIT_TEST)

add_executable(unit_tests test/mainTest.cpp)

target_link_libraries(unit_tests PRIVATE 
    MainLib 
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)⏎  