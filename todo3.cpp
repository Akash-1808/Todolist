#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Todo {
public:
    std::string Todo_name;
    std::vector<std::string> task;
};

std::vector<Todo> todo_list;

void add_task(int i) {
    int c = 1;
    while (c == 1) {
        std::string task;
        std::cout << "Enter task (or type 'quit' to stop adding tasks): ";
        std::cin >> task;
        if (task == "quit") {
            break;
        }
        todo_list[i].task.push_back(task);
        std::cout << "1 to add another task, 0 to quit: ";
        std::cin >> c;
    }
}

void remove_task(int i) {
    std::string task_name;
    std::cout << "Enter task name to remove: ";
    std::cin >> task_name;

    auto it = std::find(todo_list[i].task.begin(), todo_list[i].task.end(), task_name);
    if (it != todo_list[i].task.end()) {
        todo_list[i].task.erase(it); // Erase using iterator
        std::cout << "Task '" << task_name << "' removed successfully.\n";
    } else {
        std::cout << "Task '" << task_name << "' not found.\n";
    }
}

void mark_as_completed(int i) {
    std::string task_name, task_completed = " (completed)";
    std::cout << "Enter task name to mark as completed: ";
    std::cin >> task_name;

    bool found = false;

    for (int j = 0; j < todo_list[i].task.size(); ++j) {
        if (task_name == todo_list[i].task[j]) {
            todo_list[i].task[j] += task_completed;
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Task '" << task_name << "' marked as completed.\n";
    } else {
        std::cout << "Task '" << task_name << "' not found.\n";
    }
}

void create() {
    Todo newTodo;
    std::string name;

    std::cout << "Enter the Todo list name: ";
    std::cin >> name;
    newTodo.Todo_name = name;

    int c = 1;
    while (c == 1) {
        std::string task;
        std::cout << "Enter task (or type 'quit' to stop adding tasks): ";
        std::cin >> task;
        if (task == "quit") {
            break;
        }
        newTodo.task.push_back(task);
        std::cout << "1 to add another task, 0 to quit: ";
        std::cin >> c;
    }

    todo_list.push_back(newTodo);
}

void use() {
    for (int i = 0; i < todo_list.size(); i++) {
        std::string todo_name = todo_list[i].Todo_name;
        std::cout << todo_name << std::endl;
    }

    std::string name;
    std::cout << "Enter the Todo list name: ";
    std::cin >> name;

    for (int i = 0; i < todo_list.size(); i++) {
        if (name == todo_list[i].Todo_name) {
            for (int j = 0; j < todo_list[i].task.size(); j++) {
                std::string task = todo_list[i].task[j];
                std::cout << task << std::endl;
            }
            int n;

            do {
                std::cout << "\n1. add task\n";
                std::cout << "2. remove task\n";
                std::cout << "3. mark as completed\n";
                std::cout << "4. Quit\n";
                std::cout << "Choose an option: ";
                std::cin >> n;

                switch (n) {
                    case 1:
                        add_task(i);
                        break;
                    case 2:
                        remove_task(i);
                        break;
                    case 3:
                        mark_as_completed(i);
                        break;
                    case 4:
                        std::cout << "Quitting task list...\n";
                        break;
                    default:
                        std::cout << "Invalid option. Please choose again.\n";
                }

            } while (n != 4);
        }
    }
}

void remove_() {
    std::string todo_name;
    std::cout << "Enter todolist name to remove: ";
    std::cin >> todo_name;

    bool found = false;
    for (auto it = todo_list.begin(); it != todo_list.end(); ++it) {
        if (it->Todo_name == todo_name) {
            it = todo_list.erase(it); // erase returns the iterator to the next element
            found = true;
            break; // exit loop since we found and erased the element
        }
    }

    if (found) {
        std::cout << "Todo list '" << todo_name << "' removed successfully.\n";
    } else {
        std::cout << "Todo list '" << todo_name << "' not found.\n";
    }
}

int main() {
    int n;

    do {
        std::cout << "\n1. Create Todo list\n";
        std::cout << "2. Use Todo list\n";
        std::cout << "3. Remove Todo list\n";
        std::cout << "4. Quit\n";
        std::cout << "Choose an option: ";
        std::cin >> n;

        switch (n) {
            case 1:
                create();
                break;
            case 2:
                use();
                break;
            case 3:
                remove_();
                break;
            case 4:
                std::cout << "Quitting Todo list...\n";
                break;
            default:
                std::cout << "Invalid option. Please choose again.\n";
        }

    } while (n != 4);

    return 0;
}

