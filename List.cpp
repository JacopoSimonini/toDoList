//
// Created by simon on 12/10/2024.
//

#include <list>
#include <iostream>
#include "List.h"

using namespace std;

void List::add(const ToDo& todo) {
    bool verify = false;
    for(const auto& i : lista){
        if( todo.getName() == i.getName()){
            cout << "You cannot have todo with the same name" <<endl;
            verify = true;
        }
    }
    if(!verify){
        lista.push_back(todo);
    }
}

void List::remove(const string& name) {
    for (auto i = lista.begin(); i != lista.end(); ++i) {
        if (i->getName() == name) {
            lista.erase(i);
            return;
        }
    }
    cout << "ToDo not found." << endl;
}

void List::setCompleted(const string& name) {
    for (auto i = lista.begin(); i != lista.end(); ++i) {
        if (i->getName() == name) {
            i->setCompleted(true);
            return;
        }
    }
        cout << "ToDo not found." << endl;
}
