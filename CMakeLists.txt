# Just for the sake of easy lib inclusion in CMake based projects
# Not for use in **Arduino** projects!

cmake_minimum_required(VERSION 3.12.0)

project(VISL VERSION 0.0.1 LANGUAGES CXX C)

set(VIS_SOURCE_DIR "src")

file(GLOB_RECURSE VIS_SOURCES
        "${VIS_SOURCE_DIR}/*.h"
        "${VIS_SOURCE_DIR}/*.cpp")
        
list(FILTER VIS_SOURCES EXCLUDE REGEX "^[VIS-]")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(VISL_TEST_PROGRAM ON)

add_library(VISL STATIC ${VIS_SOURCES})
target_include_directories(VISL PUBLIC "${VIS_SOURCE_DIR}")

if(VISL_TEST_PROGRAM)
add_executable(visl-test "test/main.cpp")
target_include_directories(visl-test PUBLIC "${VIS_SOURCE_DIR}")
target_link_libraries(visl-test VISL)
target_compile_options(visl-test PRIVATE -g)
endif()

