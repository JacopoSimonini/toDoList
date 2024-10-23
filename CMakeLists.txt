cmake_minimum_required(VERSION 3.17)
project(ToDoList)

set(CMAKE_CXX_STANDARD 14)

add_executable(ToDoList main.cpp toDo.h list.h listOfLists.h list.cpp listOfLists.cpp)

add_executable(TestProject test.cpp toDo.h list.h listOfLists.h list.cpp listOfLists.cpp)