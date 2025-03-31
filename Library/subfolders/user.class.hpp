#include <iostream>
#include <vector>
#include "book.class.hpp"

using namespace std;

class User
{
private:
    string name;
    string password;
    vector<Book> lentBooks;
    vector<Book> readBooks;
public:
    User(string name, string password) {
        this->name = name;
        this->password = password;
    }

    int lendBook(vector<Book> &bookBase, int index) {
        if(index >= 0 && index < bookBase.size()) {
            this->lentBooks.push_back(bookBase.at(index));
            this->readBooks.push_back(bookBase.at(index));
            return 0;
        } else {
            return -1;
        }
    }

    int returnBook(int index) {
        if(index >= 0 && index < this->lentBooks.size()) {
            this->lentBooks.erase(index);
            return
        }
    }

};
