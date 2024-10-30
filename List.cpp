//
// Created by simon on 12/10/2024.
//

#include <list>
#include <iostream>
#include "List.h"

using namespace std;

bool List::add(const ToDo& todo) {
    for (const auto& i : lista) {
        if (todo.getName() == i.getName()) {
            cout << "You cannot have todo with the same name" << endl;
            return false;
        }
    }

    lista.push_back(todo);
    return true;
}


bool List::remove(const string& name) {
    for (auto i = lista.begin(); i != lista.end(); ++i) {
        if (i->getName() == name) {
            lista.erase(i);
            return true;
        }
    }
    cout << "ToDo not found." << endl;
    return false;
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

int List::numberOfCompletedTodos() const {
    int count = 0;
    for (const auto& todo : lista) {
        if (todo.isCompleted()) {
            count++;
        }
    }
    return count;
}

ToDo List::findTodoByKeyword(const string& keyword) {
    for (const auto& todo : lista) {
        if (todo.getName().find(keyword) != string::npos) {
            return todo;
        }
    }
    return ToDo(); //ritorno un todo vuoto nel caso non trovi nulla
}

