cmake_minimum_required(VERSION 3.10)

project(kjv_cli CXX)

add_executable(kjv_cli src/main.cc)

find_package(SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(kjv_cli ${SQLite3_LIBRARIES})

