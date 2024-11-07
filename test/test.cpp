//
// Created by simon on 22/10/2024.
//
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "../ToDo.h"
#include "../List.h"
#include "../ListOfLists.h"
#include "../utility.h"

using namespace std;
// google test
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

    ToDo foundTodo = workList.findFirstTodoByKeyword("report");
    assert(foundTodo.getName() == "Prepare report");
    foundTodo = workList.findFirstTodoByKeyword("meeting");
    assert(foundTodo.getName() == "");

    List myList("TestList");
    myList.add(ToDo("Prepare report", false));
    myList.add(ToDo("Prepare presentation", true));
    myList.add(ToDo("Buy groceries", true));
    auto result1 = myList.findTodosByKeyword("groceries");
    assert(result1.size() == 1);
    assert(result1.front().getName() == "Buy groceries");
    auto result2 = myList.findTodosByKeyword("meeting");
    assert(result2.empty());
    auto result3 = myList.findTodosByKeyword("Prepare");
    assert(result3.size() == 2);

    workList.setCompleted("Prepare report");
    assert(workList.numberOfCompletedTodos() == 1);

    assert(workList.remove("Email client") == true);
    assert(workList.numberOfTodos() == 1);
    assert(workList.remove("Fake ToDo") == false); //stampa "ToDo not found."

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


    //test getAllListNames()
    ListOfList myListOfLists;
    myListOfLists.newList("Work");
    myListOfLists.newList("Personal");
    myListOfLists.newList("Shopping");
    list<string> names = myListOfLists.getAllListNames();
    assert(names.size() == 3);
    auto it = names.begin();
    assert(*it == "Work");
    ++it;
    assert(*it == "Personal");
    ++it;
    assert(*it == "Shopping");


    //test addTodo()
    ToDo todo("Prepare report", false);
    bool result = myListOfLists.addTodo("Work", todo);
    assert(result == true);
    List& WorkList = myListOfLists.getList("Work");
    assert(WorkList.numberOfTodos() == 1);

    //test removeTodo()
    bool Result = myListOfLists.removeTodo("Work", "Prepare report");
    assert(Result == true);
    assert(WorkList.numberOfTodos() == 0);


    //test testMoveTodo()
    ListOfList lists;
    lists.newList("Work");
    lists.newList("Personal");
    ToDo task1("Prepare report", false);
    ToDo task2("Email client", false);
    ToDo task3("Buy groceries", true);
    lists.getList("Work").add(task1);
    lists.getList("Work").add(task2);
    lists.getList("Personal").add(task3);
    assert(lists.moveTodo("Work", "Personal", "Prepare report") == true);   // sposto un todo da una lista all'altra
    assert(lists.getList("Work").numberOfTodos() == 1);
    assert(lists.getList("Personal").numberOfTodos() == 2);
    assert(lists.moveTodo("Work", "Personal", "Cleaning") == false);       // sposto un todo che non esiste
    assert(lists.moveTodo("Study", "Personal", "Prepare report") == false);       // lista di origine non esiste
    assert(lists.moveTodo("Work", "Study", "Email client") == false);     // lista di destinazione non esiste
    lists.getList("Personal").add(ToDo("Email client", true));  // sposto un todo già presente nella lista di destinazione, aggiungo un duplicato
    assert(lists.moveTodo("Work", "Personal", "Email client") == false);
    assert(lists.getList("Work").numberOfTodos() == 1);
    assert(lists.getList("Personal").numberOfTodos() == 3);
    assert(lists.moveTodo("Personal", "Work", "Buy groceries") == true);       // sposto un todo completato tra liste
    assert(lists.getList("Personal").numberOfCompletedTodos() == 1);
    assert(lists.getList("Work").numberOfCompletedTodos() == 1);
    assert(lists.moveTodo("Personal", "Personal", "Prepare report") == false);    // sposto un todo tra la stessa lista

    cout << "testListOfLists passed." << endl;
}


void testReadWrite() {
    ListOfList lists;
    lists.newList("Work");
    lists.newList("Personal");

    lists.getList("Work").add(ToDo("Prepare report", false));
    lists.getList("Work").add(ToDo("Email client", true));
    lists.getList("Personal").add(ToDo("Buy groceries", false));
    lists.getList("Personal").add(ToDo("Exercise", true));

    string filename = "test_file.txt";

    write(lists, filename);

    ifstream infile(filename);
    assert(infile.is_open());
    infile.close();

    ListOfList loadedLists;
    read(loadedLists, filename);


    auto& loadedWorkList = loadedLists.getList("Work");
    assert(loadedWorkList.numberOfTodos() == 2);
    assert(loadedWorkList.findFirstTodoByKeyword("Prepare report").isCompleted() == false);
    assert(loadedWorkList.findFirstTodoByKeyword("Email client").isCompleted() == true);

    auto& loadedPersonalList = loadedLists.getList("Personal");
    assert(loadedPersonalList.numberOfTodos() == 2);
    assert(loadedPersonalList.findFirstTodoByKeyword("Buy groceries").isCompleted() == false);
    assert(loadedPersonalList.findFirstTodoByKeyword("Exercise").isCompleted() == true);

    remove(filename.c_str());

    cout << "All tests for read and write passed successfully." << endl;
}

int main() {

    testToDo();
    testList();
    testListOfLists();
    testReadWrite();

    cout << endl;
    cout << "All tests passed." << endl;

    return 0;
}