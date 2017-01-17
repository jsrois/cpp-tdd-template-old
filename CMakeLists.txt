# project
cmake_minimum_required(VERSION 3.2)
project(elevator)
set(CMAKE_CXX_STANDARD 14)

# dependencies
include(deps/gtest)
include(deps/fakeit)

# files
set(library_files src/elevator.cpp src/elevator.h)
set(test_files
        test/main.test.cpp test/elevator.test.cpp)

# library
if ( library_files )
 add_library(${PROJECT_NAME} SHARED ${library_files})
endif()

# tests
add_executable(unit ${library_files} ${test_files})
target_link_libraries(unit
        libgtest
        libgmock)


install(TARGETS unit DESTINATION bin)
