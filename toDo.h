//
// Created by simon on 10/10/2024.
//

#ifndef TODOLIST_TODO_H
#define TODOLIST_TODO_H

#include <string>

using namespace std;

class ToDo {
private:
    string name;
    bool completed;

public:
    ToDo(const string& name, bool completed = false)
            : name(name), completed(completed) {}

    string getName() const {
        return name;
    }

    bool isCompleted() const {
        return completed;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setCompleted(bool isCompleted) {
        completed = isCompleted;
    }

    void display() const {
        std::cout << "ToDo: " << name
                  << " | Completed: " << (completed ? "Yes" : "No") << std::endl;
    }
};



#endif //TODOLIST_TODO_H
