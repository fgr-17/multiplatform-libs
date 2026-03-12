cmake_minimum_required(VERSION 3.18)

project(CXX_PROJECT)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ standard required for build")
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "is C++ stndard a requirement")
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "enable/disable compiler specific extensions")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Werror")


set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_CXX_CLANG_FORMAT "clang-format")
set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "iwyu")

file(GLOB_RECURSE ALL_SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/pocs/*.cpp
    ${CMAKE_SOURCE_DIR}/pocs/*.c
    ${CMAKE_SOURCE_DIR}/pocs/*.h
)

add_custom_target(fix
    COMMAND ${CMAKE_SOURCE_DIR}/scripts/format-modified.sh
    COMMENT "Running clang-format on modified files..."
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
add_custom_target(fix-all
    COMMAND clang-format -i ${ALL_SOURCE_FILES}
    COMMENT "Running clang-format on all source files..."
)

enable_testing()

add_subdirectory(pocs/cppunit)

add_dependencies(cppunit_runner fix)