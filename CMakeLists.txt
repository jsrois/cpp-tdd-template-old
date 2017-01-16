cmake_minimum_required(VERSION 3.6)
project(template)

set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)
include(FindPkgConfig)

# We need thread support
find_package(Threads REQUIRED)

############### GoogleTest & FakeIt ##############################3


# Download and install GoogleTest
ExternalProject_Add(
        gtest
        URL https://github.com/google/googletest/archive/master.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        # Disable install step
        INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

include_directories("${source_dir}/googletest/include"
        "${source_dir}/googlemock/include")

# Download and install FakeIt
ExternalProject_Add(
        fakeit
        GIT_REPOSITORY https://github.com/eranpeer/FakeIt
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/fakeit
        # Disable install step
        INSTALL_COMMAND ""
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/fakeit/src/fakeit/single_header/gtest)

### OPENCV ###

pkg_search_module(OPENCV REQUIRED opencv)

##############

add_definitions( -DTEST_DATA_PATH="${CMAKE_SOURCE_DIR}/data" )

set(LIBRARY_FILES )
set(TEST_FILES
        test/main.test.cpp)

include_directories(src)
add_executable(unit ${LIBRARY_FILES} ${TEST_FILES})
target_link_libraries(unit
        libgtest
        libgmock
        ${OPENCV_LIBRARIES})

target_include_directories(unit PUBLIC ${OPENCV_INCLUDE_DIRS})
target_compile_options(unit PUBLIC ${OPENCV_CFLAGS_OTHER})

install(TARGETS unit DESTINATION bin)