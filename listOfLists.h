//
// Created by simon on 10/10/2024.
//

#ifndef TODOLIST_LISTOFLISTS_H
#define TODOLIST_LISTOFLISTS_H

#include "list.h"
#include <list>

using namespace std;

class ListOfList {
private:
    list<List> lists;

public:
    void newList(const string& title);

    void removeList(const std::string& title);

    void displayAll();

    List& getList(const string& title);


    const list<List>& getLists() const {
        return lists;
    }

};


#endif //TODOLIST_LISTOFLISTS_H
