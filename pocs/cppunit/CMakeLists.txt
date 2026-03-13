cmake_minimum_required(VERSION 3.18)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CPPUNIT REQUIRED cppunit)

add_library(calculator src/calculator.cpp src/real_adder.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(cppunit_runner test/main.cpp test/test_calculator.cpp
    test/test_mock_example.cpp)
target_link_libraries(cppunit_runner PRIVATE calculator ${CPPUNIT_LIBRARIES})
target_include_directories(cppunit_runner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/test ${CPPUNIT_INCLUDE_DIRS})
set_target_properties(cppunit_runner PROPERTIES CXX_CLANG_TIDY ""
    CXX_INCLUDE_WHAT_YOU_USE "")

enable_testing()
add_test(NAME CppUnit_PoC COMMAND cppunit_runner)
