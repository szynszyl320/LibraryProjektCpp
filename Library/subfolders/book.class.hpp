#include <iostream>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string genre;
    bool isLent;

    Book(string title, string author, string genre) {
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->isLent = false;
    }

};

int findBookByTitle(string title, vector<Book> &bookBase) {
    for(int i = 0; i < bookBase.max_size(); i++) {
        if(bookBase.at(i).title == title) {
            return i;
        }
    }
    return -1;
}

void listBooks(vector<Book> &bookBase) {
    for(int i = 0; i < bookBase.size(); i++) {
        cout << "|" << i+1 << "| |" << bookBase.at(i).title << "| |" << bookBase.at(i).author << "| |" << bookBase.at(i).genre << ((bookBase.at(i).isLent)? "| |not avaliable|\n" : "| |available|\n");
    }
}
