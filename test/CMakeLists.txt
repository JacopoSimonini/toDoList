add_subdirectory(googletest-main)
add_executable(TestProject test.cpp)

target_sources(TestProject PRIVATE
        ${CMAKE_SOURCE_DIR}/ToDo.h
        ${CMAKE_SOURCE_DIR}/List.h
        ${CMAKE_SOURCE_DIR}/utility.h
        ${CMAKE_SOURCE_DIR}/List.cpp
        ${CMAKE_SOURCE_DIR}/ListOfLists.cpp
        )

target_include_directories(TestProject PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/test/googletest-main/googletest/include
        )

target_link_libraries(TestProject gtest gtest_main)

