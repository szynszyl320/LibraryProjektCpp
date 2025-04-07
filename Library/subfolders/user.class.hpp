#include <iostream>
#include <vector>
#include "book.class.hpp"

using namespace std;


class User
{
public:
    string name;
    string password;
    vector<Book> lentBooks;
    vector<Book> readBooks;

    User(string name, string password) {
        this->name = name;
        this->password = password;
    }

    int lendBook(vector<Book> &bookBase, int index) {
        if(index >= 0 && index < bookBase.size()) {
            bookBase.at(index).isLent = true;
            this->lentBooks.push_back(bookBase.at(index));
            this->readBooks.push_back(bookBase.at(index));
            return 0;
        } else {
            return -1;
        }
    }

    int returnBook(int index, vector<Book> &bookBase) {
        if(index >= 0 && index < this->lentBooks.size()) {
            bookBase.at(findBookByTitle(this->lentBooks.at(index).title, bookBase)).isLent = false;
            this->lentBooks.erase(lentBooks.begin() + index);
            return 0;
        }
    }

};

tryLogging(string login, string password, vector<User> &userBase) {
    for (int i = 0; i < userBase.max_size(); i++) {
        if(login == userBase.at(i).name && password == userBase.at(i).password) {
            return 1;
        }
    }
    return 0;
}
