//
// Created by simon on 12/10/2024.
//

#include "ListOfLists.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void ListOfList::newList(const string& title) {
    bool verify = false;
    for(const auto& list : lists){
        if(title == list.getTitle()){
           cout << "You cannot have lists with the same titles" <<endl;
           verify = true;
        }
    }
    if(!verify){
        List elenco(title);
        lists.push_back(elenco);
    }
}

void ListOfList::removeList(const string& title) {
    bool found = false;
    auto it = lists.begin();
    for(auto& list : lists){
        if(title == list.getTitle()){
            found = true;
            lists.erase(it);
            break;
        }
        else{
            advance(it, 1);
        }
    }
    if (!found) {
        throw (out_of_range) "List not found";
    }
}

List& ListOfList::getList(const string& title) {
    for (auto& list : lists) {
        if (list.getTitle() == title) {
            return list;
        }
    }
    throw (out_of_range) "List not found";
}

