//
// Created by simon on 10/10/2024.
//

#ifndef TODOLIST_LIST_H
#define TODOLIST_LIST_H

#include "toDo.h"
#include <list>

using namespace std;

class List {
private:
string title;
list<ToDo> lista;

public:
List(const string& title)
        : title(title) {}

void add(const ToDo& todo);

void remove(const string& name);

void setCompleted(const string& name);

void displayCompleted();

void displayNotCompleted();

void display() const;

const string &getTitle() const {
    return title;
}

};

#endif //TODOLIST_LIST_H
