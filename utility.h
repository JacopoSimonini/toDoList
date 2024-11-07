//
// Created by simon on 06/11/2024.
//

#ifndef TODOLIST_UTILITY_H
#define TODOLIST_UTILITY_H

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

    for (const auto& list :  myListOfLists.lists) {
        file << "List: " << list.title << endl;
        for (const auto& todo : list.lista) {
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





#endif //TODOLIST_UTILITY_H
