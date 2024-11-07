//
// Created by simon on 07/11/2024.
//

#include <gtest/gtest.h>
#include "../ListOfLists.h"

TEST(ListOfListsTest, BasicOperations) {
    ListOfList myLists;
    myLists.newList("Work");
    myLists.newList("Personal");
    EXPECT_EQ(myLists.numberOfLists(), 2);

    auto& workList = myLists.getList("Work");
    workList.add(ToDo("Prepare report", false));
    EXPECT_EQ(workList.numberOfTodos(), 1);

    // Test getAllListNames
    ListOfList myListOfLists;
    myListOfLists.newList("Work");
    myListOfLists.newList("Personal");
    myListOfLists.newList("Shopping");
    auto names = myListOfLists.getAllListNames();
    EXPECT_EQ(names.size(), 3);
    auto it = names.begin();
    EXPECT_EQ(*it++, "Work");
    EXPECT_EQ(*it++, "Personal");
    EXPECT_EQ(*it, "Shopping");

    // Test addTodo e removeTodo
    ToDo todo("Prepare report", false);
    EXPECT_TRUE(myListOfLists.addTodo("Work", todo));
    EXPECT_EQ(myListOfLists.getList("Work").numberOfTodos(), 1);
    EXPECT_TRUE(myListOfLists.removeTodo("Work", "Prepare report"));
    EXPECT_EQ(myListOfLists.getList("Work").numberOfTodos(), 0);

    //test moveTodo
    ListOfList lists;
    lists.newList("Work");
    lists.newList("Personal");
    ToDo task1("Prepare report", false);
    ToDo task2("Email client", false);
    ToDo task3("Buy groceries", true);
    lists.getList("Work").add(task1);
    lists.getList("Work").add(task2);
    lists.getList("Personal").add(task3);
    EXPECT_TRUE(lists.moveTodo("Work", "Personal", "Prepare report"));
    EXPECT_EQ(lists.getList("Work").numberOfTodos(), 1);
    EXPECT_EQ(lists.getList("Personal").numberOfTodos(), 2);
    EXPECT_FALSE(lists.moveTodo("Work", "Personal", "Non-existent Task"));
}