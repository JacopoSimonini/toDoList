cmake_minimum_required(VERSION 3.17)
project(ToDoList)

set(CMAKE_CXX_STANDARD 14)

add_executable(ToDoList main.cpp ToDo.h List.h ListOfLists.h List.cpp ListOfLists.cpp)

add_executable(TestProject test.cpp ToDo.h List.h ListOfLists.h List.cpp ListOfLists.cpp)