#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the menu options
void displayMenu() {
    cout << "====== To-Do List ======" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Done" << endl;
    cout << "4. Exit" << endl;
}

// Function to add a task to the list
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks in the list
void viewTasks(const vector<string>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to mark a task as done
void markTask(vector<string>& tasks) {
    size_t taskNumber;
    cout << "Enter task number to mark as done: ";
    cin >> taskNumber;
    cin.ignore(); // to clear the newline character from the input buffer
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task marked as done!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTask(tasks);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

