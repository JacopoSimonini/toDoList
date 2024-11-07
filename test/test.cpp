//
// Created by simon on 22/10/2024.
//

#include <gtest/gtest.h>
#include "../ToDo.h"
#include "../List.h"
#include "../ListOfLists.h"
#include "../utility.h"
#include <fstream>
#include <string>
#include <list>

using namespace std;

// Test classe ToDo
TEST(ToDoTest, BasicOperations) {
    ToDo task("Buy groceries", false);
    EXPECT_EQ(task.getName(), "Buy groceries");
    EXPECT_FALSE(task.isCompleted());

    task.setCompleted(true);
    EXPECT_TRUE(task.isCompleted());
}



// Test classe List
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



// Test classe ListOfLists
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



// Test classe utility
TEST(ReadWriteTest, SaveAndLoadLists) {
    ListOfList lists;
    lists.newList("Work");
    lists.newList("Personal");

    lists.getList("Work").add(ToDo("Prepare report", false));
    lists.getList("Work").add(ToDo("Email client", true));
    lists.getList("Personal").add(ToDo("Buy groceries", false));
    lists.getList("Personal").add(ToDo("Exercise", true));

    const string filename = "test_file.txt";

    write(lists, filename);

    ifstream infile(filename);
    EXPECT_TRUE(infile.is_open());
    infile.close();

    ListOfList loadedLists;
    read(loadedLists, filename);

    auto& loadedWorkList = loadedLists.getList("Work");
    EXPECT_EQ(loadedWorkList.numberOfTodos(), 2);
    EXPECT_FALSE(loadedWorkList.findFirstTodoByKeyword("Prepare report").isCompleted());
    EXPECT_TRUE(loadedWorkList.findFirstTodoByKeyword("Email client").isCompleted());

    auto& loadedPersonalList = loadedLists.getList("Personal");
    EXPECT_EQ(loadedPersonalList.numberOfTodos(), 2);
    EXPECT_FALSE(loadedPersonalList.findFirstTodoByKeyword("Buy groceries").isCompleted());
    EXPECT_TRUE(loadedPersonalList.findFirstTodoByKeyword("Exercise").isCompleted());

    remove(filename.c_str());
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
