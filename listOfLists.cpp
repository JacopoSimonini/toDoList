//
// Created by simon on 12/10/2024.
//

#include "listOfLists.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void ListOfList::newList(const string& title) {
    for(const auto& list : lists){
        if(title == list.getTitle())
            throw (invalid_argument) "You cannot have lists with the same titles";
    }
    List elenco(title);
    lists.push_back(elenco);
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

void ListOfList::displayAll() {
    std::cout << "List:" << std::endl;
    for (const auto& list : lists){
        list.display();
    }
}