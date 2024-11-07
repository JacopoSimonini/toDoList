//
// Created by simon on 10/10/2024.
//

#ifndef TODOLIST_LIST_H
#define TODOLIST_LIST_H

#include "ToDo.h"
#include <list>

using namespace std;

class ListOfList;   //forward declaration

class List {
friend void write(const ListOfList& myListOfLists, string title);

private:
string title;
list<ToDo> lista;

public:
List(const string& title)
        : title(title) {}


bool add(const ToDo& todo);

bool remove(const string& name);

int numberOfTodos() const {
    return lista.size();
}

int numberOfCompletedTodos() const;

void setTitle(const string& newTitle){
    title = newTitle;
}

ToDo findFirstTodoByKeyword(const string& keyword);

list<ToDo> findTodosByKeyword(const string& keyword);

void setCompleted(const string& name);

const string &getTitle() const {
    return title;
}

};

#endif //TODOLIST_LIST_H
