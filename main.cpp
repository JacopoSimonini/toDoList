#include <iostream>
#include <fstream>
#include "ToDo.h"
#include "List.h"
#include "ListOfLists.h"

using namespace std;

void write(const ListOfList& myListOfLists, string title) {
    ofstream file(title , ios::out);
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
}


void read(ListOfList& myListOfLists, string title) {
    fstream file;
    file.open(title, fstream::in);

    if (!file.is_open()) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    List* currentList = nullptr;


    while (getline(file, line)) {
        if (!line.empty()) {
            if (line.find("List: ") != string::npos) {
                string listTitle = line.substr(6);  // rimuove "List: "
                try {
                    currentList = &myListOfLists.getList(listTitle);
                } catch (out_of_range& e) {
                    myListOfLists.newList(listTitle);
                    currentList = &myListOfLists.getList(listTitle);
                }
            } else {
                if (currentList != nullptr) {
                    size_t colonPos = line.find(":");
                    if (colonPos != string::npos) {
                        string todoName = line.substr(0, colonPos); // prende il ToDo
                        string status = line.substr(colonPos + 2); // prende lo stato del ToDo, il +2 serve per saltare ": "

                        bool isCompleted = (status == "Completed");
                        currentList->add(ToDo(todoName, isCompleted));
                    }
                }
            }
        }
    }
    file.close();
}




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

    //myListOfLists.displayAll();

    personalList.setCompleted("Call mom");
    studyList.setCompleted("c++");
    //workList.setCompleted("Cleaning");

    //myListOfLists.removeList("Study");


    write(myListOfLists,"todo_lists.txt");
    write(example,"example.txt");

   return 0;
}
