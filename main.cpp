#include <iostream>
#include <fstream>
#include "ToDo.h"
#include "List.h"
#include "ListOfLists.h"
#include "utility.h"

using namespace std;

int main() {
    ListOfList example;
    ListOfList myListOfLists;


    read(example,"example.txt");
    read(myListOfLists,"todo_lists.txt");

    example.newList("Work");

    auto& exampleList = example.getList("Work");

    exampleList.add(ToDo("Prepare report"));
    exampleList.add(ToDo("Email client"));



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

    personalList.setCompleted("Call mom");
    studyList.setCompleted("c++");
    //workList.setCompleted("Cleaning");

    //myListOfLists.removeList("Study");


    write(myListOfLists,"todo_lists.txt");
    write(example,"example.txt");

   return 0;
}
