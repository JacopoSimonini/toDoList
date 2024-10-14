//
// Created by simon on 12/10/2024.
//

#include <list>
#include <iostream>
#include "list.h"

using namespace std;

void List::add(const ToDo& todo) {
    lista.push_back(todo);
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

void List::displayCompleted(){
    for (const auto& todo : lista) {
        if (todo.isCompleted()) {
            todo.display();
        }
    }
}

void List::displayNotCompleted(){
    for (const auto& todo : lista) {
        if (!todo.isCompleted()) {
            todo.display();
        }
    }
}

void List::display() const {
    for (const auto& todo : lista) {
        todo.display();
    }
}