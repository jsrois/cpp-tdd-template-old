cmake_minimum_required(VERSION 3.2)
project(template)

set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)

# We need thread support
find_package(Threads REQUIRED)

include(deps/gtest)
include(deps/fakeit)

add_definitions( -DTEST_DATA_PATH="${CMAKE_SOURCE_DIR}/data" )

set(LIBRARY_FILES )
set(TEST_FILES
        test/main.test.cpp)

include_directories(src)
add_executable(unit ${LIBRARY_FILES} ${TEST_FILES})
target_link_libraries(unit
        libgtest
        libgmock)


install(TARGETS unit DESTINATION bin)
