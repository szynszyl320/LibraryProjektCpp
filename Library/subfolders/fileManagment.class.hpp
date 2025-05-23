#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "book.class.hpp"
#include "user.class.hpp"

using namespace std;

void saveFiles(vector<Book> &bookBase, vector<User> &userBase) {
    ofstream books("saves/books.txt");
    if (books.is_open()) {
        for (int i = 0; i < bookBase.size(); i++) {
            books << bookBase.at(i).title << "|"
                  << bookBase.at(i).author << "|"
                  << bookBase.at(i).genre << "|"
                  << bookBase.at(i).isLent << endl;
        }
    }
    books.close();

    ofstream users("saves/users.txt");
    if (users.is_open()) {
        for (int i = 0; i < userBase.size(); i++) {
            users << userBase.at(i).name << "|"
                  << userBase.at(i).password << "|"
                  << userBase.at(i).stringifyBooks("lent") << "|"
                  << userBase.at(i).stringifyBooks("read") << endl;
        }
    }
    users.close();
}

void loadFiles(vector<Book> &bookBase, vector<User> &userBase) {
    bookBase.clear();
    userBase.clear();

    ifstream books("saves/books.txt");
    if (books.is_open()) {
        string line;
        while (getline(books, line)) {
            stringstream ss(line);
            string title, author, genre, isLentStr;
            getline(ss, title, '|');
            getline(ss, author, '|');
            getline(ss, genre, '|');
            getline(ss, isLentStr, '|');
            if (title.empty() || author.empty() || genre.empty() || isLentStr.empty()) continue;
            bool isLent = (isLentStr == "1");
            Book b(title, author, genre);
            b.isLent = isLent;
            bookBase.push_back(b);
        }
        books.close();
    }

    ifstream users("saves/users.txt");
    if (users.is_open()) {
        string line;
        while (getline(users, line)) {
            stringstream ss(line);
            string name, password, lentBooksStr, readBooksStr;
            getline(ss, name, '|');
            getline(ss, password, '|');
            getline(ss, lentBooksStr, '|');
            getline(ss, readBooksStr, '|');

            User u(name, password);
            if (!lentBooksStr.empty())
                u.lentBooks = u.destringifyBooks(lentBooksStr);
            if (!readBooksStr.empty())
                u.readBooks = u.destringifyBooks(readBooksStr);
            userBase.push_back(u);
        }
        users.close();
    }
}

