//
// Created by simon on 10/10/2024.
//

#ifndef TODOLIST_LISTOFLISTS_H
#define TODOLIST_LISTOFLISTS_H

#include "List.h"
#include <list>

using namespace std;

class ListOfList {
private:
    list<List> lists;

public:
    void newList(const string& title);

    void removeList(const std::string& title);

    //metodo che rende tutti i nomi delle liste
    //metodo aggiungere e rimuovi todo
    //metodo sposta todo (title di dove è,title di dove andrà)

    List& getList(const string& title);

    const list<List>& getLists() const {
        return lists;
    }//togliere


};


#endif //TODOLIST_LISTOFLISTS_H
