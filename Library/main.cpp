#include <iostream>
#include <vector>
#include <conio.h>
#include "subfolders/user.class.hpp"
#include "subfolders/fileManagment.class.hpp"

using namespace std;

vector<Book> BookBase = {};

vector<User> UserBase = {};

void menuSettings() {
    cout << "Press x to close the program\nPress t to list books\nPress s to search for a specific book by title\nPress c to clear the window\nPress r to return a book\nPress l to lend a book by it's number\nPress o to list already read books\nPress m to list loaned books\nPress u to logout\n>#: ";
}

string getPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else if (isprint(ch)) {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

int main()
{
    char userEntry = 'p';
    bool notLogged = true;
    string name, password;
    int userId = -1;

    loadFiles(BookBase, UserBase);

    while(true) {
        while(notLogged) {
            cout << "Login or Sign up: (l for login, s for signup, x for exit): ";
            cin >> userEntry;
            switch(userEntry) {
            case 'l':
                cout << "Give name: ";
                cin >> name;
                cout << "Give password: ";
                password = getPassword();
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
            case 'x':
                return 0;
            default:
                cout << "Invalid option. Please enter 'l', 's' or 'x'." << endl;
                break;
            }
        }

        while(true) {
            menuSettings();
            cin >> userEntry;
            switch(userEntry) {
            case 'x':
                cout << "Goodbye!\n";
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
            case 'o':
                printReadBooks(UserBase.at(userId), BookBase);
                break;
            case 'm':
                printLoanedBooks(UserBase.at(userId), BookBase);
                break;
            case 'u':
                notLogged = true;
                system("cls");
                cout << "Logging out...\n";
                goto login_loop_end;
            default:
                cout << "Invalid option. Please try again\n";
                break;
            }
        }
        login_loop_end:;
    }
}


