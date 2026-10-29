#include <iostream>
#include <limits>
#include <string>
#include "LinkedList/LinkedList.h"

using namespace std;

int main() {
    TaskList tasks;
    int choice = 0;
    int id, index, index1, index2;
    string description;

    do {
        cout << "\n===== STUDENT TASK MANAGER =====\n";
        cout << "1. Display All Tasks\n";
        cout << "2. Insert Task at Head\n";
        cout << "3. Remove Task from Head\n";
        cout << "4. Insert Task at Index\n";
        cout << "5. Remove Task at Index\n";
        cout << "6. Swap Tasks\n";
        cout << "7. Sort Tasks by ID\n";
        cout << "8. Reverse Task List\n";
        cout << "9. Check Task List Status\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1:
            tasks.Print();
            break;

        case 2:
            cout << "Enter task ID: ";
            if (!(cin >> id)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID.\n";
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter task description: ";
            getline(cin, description);
            tasks.Insert(CreateTask(id, description));
            cout << "Task inserted at head.\n";
            break;

        case 3: {
            TaskNode* removed = tasks.Remove();
            if (removed != nullptr) {
                cout << "Removed: " << removed->taskID << " - "
                     << removed->description << '\n';
                delete removed;
            } else {
                cout << "Task list is empty.\n";
            }
            break;
        }

        case 4:
            cout << "Enter task ID: ";
            if (!(cin >> id)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID.\n";
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter task description: ";
            getline(cin, description);
            cout << "Enter index (starting from 0): ";
            if (!(cin >> index)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid index.\n";
                break;
            }
            tasks.InsertAt(CreateTask(id, description), index);
            cout << "Task inserted.\n";
            break;

        case 5:
            cout << "Enter index (starting from 0): ";
            if (!(cin >> index)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid index.\n";
                break;
            }
            {
                TaskNode* removed = tasks.RemoveAt(index);
                if (removed != nullptr) {
                    cout << "Removed: " << removed->description << '\n';
                    delete removed;
                } else {
                    cout << "Invalid index or empty task list.\n";
                }
            }
            break;

        case 6:
            cout << "Enter first index: ";
            if (!(cin >> index1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid index.\n";
                break;
            }
            cout << "Enter second index: ";
            if (!(cin >> index2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid index.\n";
                break;
            }
            if (tasks.Swap(index1, index2))
                cout << "Tasks swapped.\n";
            else
                cout << "Invalid index.\n";
            break;

        case 7:
            tasks.Sort();
            cout << "Tasks sorted by ID.\n";
            break;

        case 8:
            tasks.Reverse();
            cout << "Task list reversed.\n";
            break;

        case 9:
            if (tasks.IsEmpty())
                cout << "The task list is empty.\n";
            else
                cout << "The task list is not empty.\n";
            cout << "Total tasks: " << tasks.Size() << '\n';
            break;

        case 10:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);

    return 0;
}
