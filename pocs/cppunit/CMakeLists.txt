cmake_minimum_required(VERSION 3.18)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CPPUNIT REQUIRED cppunit)

add_library(calculator src/calculator.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(cppunit_runner test/test_calculator.cpp)
target_link_libraries(cppunit_runner PRIVATE calculator ${CPPUNIT_LIBRARIES})
target_include_directories(cppunit_runner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CPPUNIT_INCLUDE_DIRS})
set_target_properties(cppunit_runner PROPERTIES CXX_CLANG_TIDY ""
    CXX_INCLUDE_WHAT_YOU_USE "")

enable_testing()
add_test(NAME CppUnit_PoC COMMAND cppunit_runner)
