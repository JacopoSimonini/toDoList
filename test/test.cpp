//
// Created by simon on 22/10/2024.
//

#include <cassert>
#include "../ToDo.h"
#include "../List.h"
#include "../ListOfLists.h"

using namespace std;

void testToDo() {
    ToDo task("Buy groceries", false);
    assert(task.getName() == "Buy groceries");
    assert(task.isCompleted() == false);
    task.setCompleted(true);
    assert(task.isCompleted() == true);
    cout << "testToDo passed." << endl;
}

void testList() {
    List workList("Personal");
    assert(workList.getTitle() == "Personal");

    workList.setTitle("Work");
    assert(workList.getTitle() == "Work");
    assert(workList.numberOfTodos() == 0);
    assert(workList.add(ToDo("Prepare report", false)) == true);
    assert(workList.add(ToDo("Email client", false)) == true);
    assert(workList.numberOfTodos() == 2);
    assert(workList.numberOfCompletedTodos() == 0);

    ToDo foundTodo = workList.findTodoByKeyword("report");
    assert(foundTodo.getName() == "Prepare report");
    foundTodo = workList.findTodoByKeyword("meeting");
    assert(foundTodo.getName() == "");

    workList.setCompleted("Prepare report");
    assert(workList.numberOfCompletedTodos() == 1);

    assert(workList.remove("Email client") == true);
    assert(workList.numberOfTodos() == 1);
    assert(workList.remove("Fake ToDo") == false); //dovrebbe stampare "ToDo not found."
    cout << "testList passed." << endl;
}


void testListOfLists() {
    ListOfList myLists;
    myLists.newList("Work");
    myLists.newList("Personal");
    assert(myLists.numberOfLists() == 2);
    auto& workList = myLists.getList("Work");
    workList.add(ToDo("Prepare report", false));
    assert(workList.numberOfTodos() == 1);
    cout << "testListOfLists passed." << endl;
}

int main() {

    testToDo();
    testList();
    testListOfLists();

    return 0;
}
