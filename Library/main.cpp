#include <iostream>
#include <vector>
#include "subfolders/user.class.hpp"
#include "subfolders/fileManagment.class.hpp"

using namespace std;

vector<Book> BookBase = {
        Book("The Great Gatsby", "F. Scott Fitzgerald", "Fiction"),
        Book("To Kill a Mockingbird", "Harper Lee", "Fiction"),
        Book("1984", "George Orwell", "Dystopian"),
        Book("Pride and Prejudice", "Jane Austen", "Romance"),
        Book("The Hobbit", "J.R.R. Tolkien", "Fantasy"),
        Book("The Catcher in the Rye", "J.D. Salinger", "Fiction"),
        Book("Moby Dick", "Herman Melville", "Adventure"),
        Book("War and Peace", "Leo Tolstoy", "Historical"),
        Book("Hamlet", "William Shakespeare", "Tragedy"),
        Book("The Odyssey", "Homer", "Epic")
};

vector<User> UserBase = {
    User("test", "zaq"),
    User("tester", "zaq1@WSX")
};

void menuSettings() {
    cout << "Press x to close the program\nPress t to list books\nPress s to search for a specific book by title\nPress c to clear the window\nPress r to return a book\nPress l to lend a book by it's number\n>#: ";
}

int main()
{
    char userEntry = 'p';
    bool notLogged = false;
    string name, password;
    int userId;
    /**while(!notLogged) {
        cout << "Login or Sign up: (l for login s for signup): ";
        cin>> userEntry;
        switch(userEntry) {
        case 'l':
            cout << "Give name: ";
            cin>> name;
            cout << "Give password: ";
            cin>> password;
            notLogged = tryLogging(name, password, UserBase, userId);
            break;
            cout << "User not found!";
        case 's':
            cout << "Give name: ";
            cin>> name;
            cout << "Give password: ";
            cin>>password;
            UserBase.push_back(User(name,password));
            notLogged = true;
        }
    }**/
    userId = 0;
    while(true) {
        menuSettings();
        cin>>userEntry;
        switch(userEntry) {
        case 'x':
            saveFiles(BookBase, UserBase);
            return 0;
            break;
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
        }
    }
}


