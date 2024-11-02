//
// Created by simon on 22/10/2024.
//

#include <cassert>
#include "../ToDo.h"
#include "../List.h"
#include "../ListOfLists.h"
#include <windows.h>

using namespace std;

void testToDo() {
    ToDo task("Buy groceries", false);
    assert(task.getName() == "Buy groceries");
    assert(task.isCompleted() == false);
    task.setCompleted(true);
    assert(task.isCompleted() == true);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "testToDo passed." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "testList passed." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "testListOfLists passed." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


int main() {

    testToDo();
    testList();
    testListOfLists();

    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);   //colora il terminale di verde (7 al posto del 2 per tornare grigio)
    cout << "All tests passed." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    return 0;
}