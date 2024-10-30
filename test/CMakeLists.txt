add_executable(TestProject test.cpp)

target_sources(TestProject PRIVATE
        ${CMAKE_SOURCE_DIR}/ToDo.h
        ${CMAKE_SOURCE_DIR}/List.h
        ${CMAKE_SOURCE_DIR}/List.cpp
        ${CMAKE_SOURCE_DIR}/ListOfLists.cpp
        )