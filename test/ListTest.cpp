//
// Created by simon on 07/11/2024.
//

#include <gtest/gtest.h>
#include "../List.h"

TEST(ListTest, BasicOperations) {
    List workList("Personal");
    EXPECT_EQ(workList.getTitle(), "Personal");

    workList.setTitle("Work");
    EXPECT_EQ(workList.getTitle(), "Work");
    EXPECT_EQ(workList.numberOfTodos(), 0);

    EXPECT_TRUE(workList.add(ToDo("Prepare report", false)));
    EXPECT_TRUE(workList.add(ToDo("Email client", false)));
    EXPECT_EQ(workList.numberOfTodos(), 2);
    EXPECT_EQ(workList.numberOfCompletedTodos(), 0);

    // Test findFirstTodoByKeyword
    ToDo foundTodo = workList.findFirstTodoByKeyword("report");
    EXPECT_EQ(foundTodo.getName(), "Prepare report");
    foundTodo = workList.findFirstTodoByKeyword("meeting");
    EXPECT_EQ(foundTodo.getName(), "");

    // Test findTodosByKeyword
    List myList("TestList");
    myList.add(ToDo("Prepare report", false));
    myList.add(ToDo("Prepare presentation", true));
    myList.add(ToDo("Buy groceries", true));
    auto result1 = myList.findTodosByKeyword("groceries");
    EXPECT_EQ(result1.size(), 1);
    EXPECT_EQ(result1.front().getName(), "Buy groceries");
    auto result2 = myList.findTodosByKeyword("meeting");
    EXPECT_TRUE(result2.empty());
    auto result3 = myList.findTodosByKeyword("Prepare");
    EXPECT_EQ(result3.size(), 2);

    // Test setCompleted
    workList.setCompleted("Prepare report");
    EXPECT_EQ(workList.numberOfCompletedTodos(), 1);
    EXPECT_TRUE(workList.remove("Email client"));
    EXPECT_EQ(workList.numberOfTodos(), 1);
    EXPECT_FALSE(workList.remove("Fake ToDo"));
}
