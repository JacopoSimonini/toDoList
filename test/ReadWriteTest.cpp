//
// Created by simon on 07/11/2024.
//

#include <gtest/gtest.h>
#include "../utility.h"

using namespace std;

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