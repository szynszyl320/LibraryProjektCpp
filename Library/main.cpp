#include <iostream>
#include <vector>
#include "subfolders/user.class.hpp"
#include "subfolders/fileManagment.class.hpp"

using namespace std;

vector<Book> BookBase = {};

vector<User> UserBase = {};

void menuSettings() {
    cout << "Press x to close the program\nPress t to list books\nPress s to search for a specific book by title\nPress c to clear the window\nPress r to return a book\nPress l to lend a book by it's number\n>#: ";
}

int main()
{
    char userEntry = 'p';
    bool notLogged = true;
    string name, password;
    int userId = -1;
    
    loadFiles(BookBase, UserBase);
    
    while(notLogged) {
        cout << "Login or Sign up: (l for login s for signup): ";
        cin >> userEntry;
        switch(userEntry) {
        case 'l':
            cout << "Give name: ";
            cin >> name;
            cout << "Give password: ";
            cin >> password;
            if (tryLogging(name, password, UserBase, userId)) {
                notLogged = false;
            } else {
                cout << "User not found or wrong password!" << endl;
            }
            break;
        case 's':
            cout << "Give name: ";
            cin >> name;
            cout << "Give password: ";
            cin >> password;
            UserBase.push_back(User(name, password));
            userId = UserBase.size() - 1;
            notLogged = false;
            cout << "User registered and logged in!" << endl;
            break;
        default:
            cout << "Invalid option. Please enter 'l' or 's'." << endl;
            break;
        }
    }
    
    while(true) {
        menuSettings();
        cin >> userEntry;
        switch(userEntry) {
        case 'x':
            saveFiles(BookBase, UserBase);
            return 0;
        case 'c':
            system("cls");
            break;
        case 't':
            listBooks(BookBase);
            break;
        case 's':
            findBookByTitle(BookBase);
            break;
        case 'r':
            returnABook(UserBase.at(userId), BookBase);
            break;
        case 'l':
            lendABook(UserBase.at(userId), BookBase);
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }
}


