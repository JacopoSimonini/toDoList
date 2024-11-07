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

list<string> ListOfList::getAllListNames() const {
    list<string> listNames;
    for (const auto& list : lists) {
        listNames.push_back(list.getTitle());
    }
    return listNames;
}

bool ListOfList::addTodo(const string& listTitle, const ToDo& todo) {
    for (auto& list : lists) {
        if (list.getTitle() == listTitle) {
            return list.add(todo);
        }
    }
    cout << "List not found" << endl;
    return false;
}

bool ListOfList::removeTodo(const string& listTitle, const string& todoName) {
    for (auto& list : lists) {
        if (list.getTitle() == listTitle) {
            return list.remove(todoName);
        }
    }
    cout << "List not found" << endl;
    return false;
}

bool ListOfList::moveTodo(const string& sourceListTitle, const string& destinationListTitle, const string& todoName) {
    auto sourceIt = lists.end();
    auto destinationIt = lists.end();

    for (auto it = lists.begin(); it != lists.end(); ++it) {
        if (it->getTitle() == sourceListTitle) {
            sourceIt = it;
        } else if (it->getTitle() == destinationListTitle) {
            destinationIt = it;
        }
        if (sourceIt != lists.end() && destinationIt != lists.end()) break;
    }

    if (sourceIt == lists.end() || destinationIt == lists.end()) {
        cout << "Source or destination list not found." << endl;
        return false;
    }



    ToDo todo = sourceIt->findFirstTodoByKeyword(todoName);

    if (todo.getName().empty()) {
        cout << "ToDo not found in the source list." << endl;
        return false;
    }

    if (destinationIt->add(todo)) {
        sourceIt->remove(todo.getName());
        return true;
    } else {
        cout << "ToDo with the same name already exists in the destination list." << endl;
        return false;
    }
}
