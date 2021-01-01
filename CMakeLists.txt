cmake_minimum_required(VERSION 3.10)

project(kjv_cli CXX)
file(GLOB_RECURSE source_list *.cc)
add_executable(kjv_cli ${source_list})

find_package(SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS} "./include")
target_link_libraries(kjv_cli ${SQLite3_LIBRARIES})

