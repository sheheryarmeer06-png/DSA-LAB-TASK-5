#include <iostream>
#include <limits>
#include <string>
#include "LinkedList/LinkedList.h"

using namespace std;

int main() {
    LinkedList library;
    int choice = 0;
    int id, index, index1, index2;
    string title;

    do {
        cout << "\n===== LIBRARY BOOK COLLECTION SYSTEM =====\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Check Collection Status\n";
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
            library.Print();
            break;

        case 2:
            cout << "Enter book ID: ";
            if (!(cin >> id)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID.\n";
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter book title: ";
            getline(cin, title);
            library.Insert(CreateBook(id, title));
            cout << "Book inserted at head.\n";
            break;

        case 3: {
            BookNode* removed = library.Remove();
            if (removed != nullptr) {
                cout << "Removed: " << removed->bookID << " - "
                     << removed->title << '\n';
                delete removed;
            } else {
                cout << "Collection is empty.\n";
            }
            break;
        }

        case 4:
            cout << "Enter book ID: ";
            if (!(cin >> id)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID.\n";
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter index (starting from 0): ";
            if (!(cin >> index)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid index.\n";
                break;
            }
            library.InsertAt(CreateBook(id, title), index);
            cout << "Book inserted.\n";
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
                BookNode* removed = library.RemoveAt(index);
                if (removed != nullptr) {
                    cout << "Removed: " << removed->title << '\n';
                    delete removed;
                } else {
                    cout << "Invalid index or empty collection.\n";
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
            if (library.Swap(index1, index2))
                cout << "Books swapped.\n";
            else
                cout << "Invalid index.\n";
            break;

        case 7:
            library.Sort();
            cout << "Books sorted by ID.\n";
            break;

        case 8:
            library.Reverse();
            cout << "Collection reversed.\n";
            break;

        case 9:
            if (library.IsEmpty())
                cout << "The collection is empty.\n";
            else
                cout << "The collection is not empty.\n";
            cout << "Total books: " << library.Size() << '\n';
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
