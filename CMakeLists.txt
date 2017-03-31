# project
cmake_minimum_required(VERSION 3.2)
project(unnamed)
set(CMAKE_CXX_STANDARD 14)

# files
set(library_files )
set(test_files test/main.test.cpp test/handler.test.cpp.cpp)

# library
if ( library_files )
 add_library(${PROJECT_NAME} SHARED ${library_files})
endif()

# tests
add_executable(unit ${library_files} ${test_files})
target_link_libraries(unit)

target_include_directories(unit PRIVATE
        test/catch
        test/fakeit)

install(TARGETS unit DESTINATION bin)
