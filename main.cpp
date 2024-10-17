#include <iostream>
#include <fstream>
#include "toDo.h"
#include "list.h"
#include "listOfLists.h"

using namespace std;

void write(const ListOfList& myListOfLists) {
    ofstream file("todo_lists.txt", ios::out);  //ios::app
    if (!file.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& list : myListOfLists.getLists()) {
        file << "List: " << list.getTitle() << endl;
        for (const auto& todo : list.getTodos()) {
            file << todo.getName() << ": " << (todo.isCompleted() ? "Completed" : "Not_Completed") << endl;
        }
        file << endl;
    }

    file.close();
    cout << "Data written to file." << endl;
}




int main() {
    ListOfList myListOfLists;

    myListOfLists.newList("Work");
    myListOfLists.newList("Study");
    myListOfLists.newList("Personal");

    auto& workList = myListOfLists.getList("Work");
    auto& studyList = myListOfLists.getList("Study");
    auto& personalList = myListOfLists.getList("Personal");

    studyList.add(ToDo("c++"));

    workList.add(ToDo("Prepare report"));
    workList.add(ToDo("Email client"));
    workList.add(ToDo("Cleaning"));

    personalList.add(ToDo("Buy groceries"));
    personalList.add(ToDo("Call mom"));

    //myListOfLists.displayAll();

    personalList.setCompleted("Call mom");
    studyList.setCompleted("c++");

    //myListOfLists.removeList("Personal");

    write(myListOfLists);

    return 0;
}
