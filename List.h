//
// Created by simon on 10/10/2024.
//

#ifndef TODOLIST_LIST_H
#define TODOLIST_LIST_H

#include "ToDo.h"
#include <list>

using namespace std;

class List {
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

ToDo findTodoByKeyword(const string& keyword);

void setCompleted(const string& name);

const string &getTitle() const {
    return title;
}

//rimuovere
const list<ToDo>& getTodos() const {
    return lista;
}

};

#endif //TODOLIST_LIST_H
