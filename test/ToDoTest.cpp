//
// Created by simon on 07/11/2024.
//

#include <gtest/gtest.h>
#include "../ToDo.h"

TEST(ToDoTest, BasicOperations) {
    ToDo task("Buy groceries", false);
    EXPECT_EQ(task.getName(), "Buy groceries");
    EXPECT_FALSE(task.isCompleted());

    task.setCompleted(true);
    EXPECT_TRUE(task.isCompleted());
}
