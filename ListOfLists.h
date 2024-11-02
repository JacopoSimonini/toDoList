//
// Created by simon on 10/10/2024.
//

#ifndef TODOLIST_LISTOFLISTS_H
#define TODOLIST_LISTOFLISTS_H

#include "List.h"
#include <list>

using namespace std;

class ListOfList {
    friend void write(const ListOfList& myListOfLists, string title);
private:
    list<List> lists;

public:
    void newList(const string& title);

    void removeList(const std::string& title);

    int numberOfLists() const {
        return lists.size();
    }

    list<string> getAllListNames() const;

    bool addTodo(const string& listTitle, const ToDo& todo);

    bool removeTodo(const string& listTitle, const string& todoName);

    bool moveTodo(const string& sourceListTitle, const string& destinationListTitle, const string& todoName);

    List& getList(const string& title);

};


#endif //TODOLIST_LISTOFLISTS_H
