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

    //metodo che rende tutti i nomi delle liste
    //metodo aggiungere todo
    //metodo rimuove todo
    //metodo sposta todo (title di dove è,title di dove andrà)

    List& getList(const string& title);

};


#endif //TODOLIST_LISTOFLISTS_H
