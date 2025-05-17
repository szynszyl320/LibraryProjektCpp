#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "book.class.hpp"

using namespace std;

class User
{
public:
    string name;
    string password;
    vector<int> lentBooks;
    vector<int> readBooks;

    User(string name, string password) {
        this->name = name;
        this->password = password;
    }

    int lendBook(vector<Book>& bookBase, int index) {
        if(index >= 0 && index < bookBase.size()) {
            bookBase.at(index).isLent = true;
            this->lentBooks.push_back(index);
            this->readBooks.push_back(index);
            this->listUserBooks(bookBase);
            return 0;
        } else {
            return -1;
        }
    }

    int returnBook(int index, vector<Book>& bookBase) {
        if(index < 0 || index >= this->lentBooks.size()) {
            return -1;
        }
        bookBase.at(this->lentBooks.at(index)).isLent = false;
        this->lentBooks.erase(this->lentBooks.begin() + index);
        return 0;
    }

    string listUserBooks(const vector<Book>& BookBase) {
        string returnString;
        for (int i = 0; i < this->lentBooks.size(); i++) {
            returnString += "|" + to_string(i+1) + "| |" + BookBase.at(this->lentBooks.at(i)).title + "| |" + BookBase.at(this->lentBooks.at(i)).author + "|\n";
        }
        return returnString;
    }

    string stringifyBooks(string whichBook) {
        string returnString;
        if(whichBook == "lent") {
            for (int i = 0; i < this->lentBooks.size(); i++) {
                if (i > 0) returnString += ",";
                returnString += to_string(this->lentBooks.at(i));
            }
        } else if(whichBook == "read") {
            for (int i = 0; i < this->readBooks.size(); i++) {
                if (i > 0) returnString += ",";
                returnString += to_string(this->readBooks.at(i));
            }
        }
        return returnString;
    }

    vector<int> destringifyBooks(const string& str) {
        vector<int> result;
        istringstream iss(str);
        string token;
        while (getline(iss, token, ',')) {
            if (!token.empty()) {
                result.push_back(stoi(token));
            }
        }
        return result;
    }
};

int tryLogging(string login, string password, vector<User>& userBase, int& id) {
    for (int i = 0; i < userBase.size(); i++) {
        if(login == userBase.at(i).name && password == userBase.at(i).password) {
            id = i;
            return 1;
        }
    }
    return 0;
}

int returnABook(User& user, vector<Book>& bookBase) {
    int bookNumber;
    cout << user.listUserBooks(bookBase);
    cout << "Which book do you want to return?\n(give the number)>>";
    cin >> bookNumber;
    if(bookNumber == 0) {
        return 0;
    }
    user.returnBook(bookNumber-1, bookBase);
    return 0;
}

void lendABook(User& user, vector<Book>& bookBase) {
   listBooks(bookBase);
   int bookIndex;
   cout << "\nInput the book number you want to lend\n(number 0 leaves the lending selection)>> ";
   cin >> bookIndex;
   if(bookIndex == 0) {
        return;
   }
   user.lendBook(bookBase, bookIndex-1);
}
