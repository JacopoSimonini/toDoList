//
// Created by simon on 22/10/2024.
//

#include <cassert>
#include "toDo.h"
#include "list.h"
#include "listOfLists.h"

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
    List workList("Work");
    workList.add(ToDo("Prepare report", false));
    workList.add(ToDo("Email client", false));
    assert(workList.getTitle() == "Work");
    assert(workList.getTodos().size() == 2);
    workList.setCompleted("Prepare report");
    auto it = workList.getTodos().begin();
    assert(it->isCompleted() == true);
    cout << "testList passed." << endl;
}

void testListOfLists() {
    ListOfList myLists;
    myLists.newList("Work");
    myLists.newList("Personal");
    assert(myLists.getLists().size() == 2);
    auto& workList = myLists.getList("Work");
    workList.add(ToDo("Prepare report", false));
    assert(workList.getTodos().size() == 1);
    cout << "testListOfLists passed." << endl;
}

int main() {

    testToDo();
    testList();
    testListOfLists();

    cout << "All tests passed" << endl;

    return 0;
}
