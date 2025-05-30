#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> loadTasks(const string& filename) {
    vector<string> tasks;
    ifstream file(filename);
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    return tasks;
}

void saveTasks(const vector<string>& tasks, const string& filename) {
    ofstream file(filename);
    for (const string& task : tasks) {
        file << task << endl;
    }
}

void showTasks(const vector<string>& tasks) {
    cout << "\nYour To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
    cout << endl;
}

int main() {
    string filename = "tasks.txt";
    vector<string> tasks = loadTasks(filename);

    while (true) {
        cout << "------ TO-DO LIST ------\n";
        cout << "1. View tasks\n";
        cout << "2. Add task\n";
        cout << "3. Delete task\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore();  // ignore newline

        if (choice == 1) {
            showTasks(tasks);
        }
        else if (choice == 2) {
            cout << "Enter new task: ";
            string newTask;
            getline(cin, newTask);
            tasks.push_back(newTask);
            saveTasks(tasks, filename);
            cout << "Task added!\n";
        }
        else if (choice == 3) {
            showTasks(tasks);
            cout << "Enter task number to delete: ";
            int del;
            cin >> del;
            if (del >= 1 && del <= tasks.size()) {
                tasks.erase(tasks.begin() + del - 1);
                saveTasks(tasks, filename);
                cout << "Task deleted!\n";
            }
            else {
                cout << "Invalid number.\n";
            }
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}