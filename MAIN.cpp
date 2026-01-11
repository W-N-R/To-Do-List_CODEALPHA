#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isDone;
};

void printTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your list is empty." << endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].isDone ? "[x] " : "[ ] ") << tasks[i].description << endl;
    }
}

int main() {
    vector<Task> todoList;
    int choice = 0;

    cout << "--- To-Do List App ---" << endl;

    while (choice != 5) {
        cout << "\n1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Done" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string taskName;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, taskName);
            Task newTask = {taskName, false};
            todoList.push_back(newTask);
            cout << "Task added successfully." << endl;
        }
        else if (choice == 2) {
            cout << "\n--- Current Tasks ---" << endl;
            printTasks(todoList);
        }
        else if (choice == 3) {
            int taskNum;
            cout << "Enter task number to mark done: ";
            cin >> taskNum;
            if (taskNum > 0 && taskNum <= todoList.size()) {
                todoList[taskNum - 1].isDone = true;
                cout << "Task marked as completed." << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        }
        else if (choice == 4) {
            int taskNum;
            cout << "Enter task number to remove: ";
            cin >> taskNum;
            if (taskNum > 0 && taskNum <= todoList.size()) {
                todoList.erase(todoList.begin() + taskNum - 1);
                cout << "Task removed." << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exiting app. Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
