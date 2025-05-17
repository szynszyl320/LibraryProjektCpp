#pragma once
#include <iostream>
#include <vector>
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

int findBookByTitle(vector<Book> &bookBase) {
    string title;
    cout << "Provide the title of the book you're looking for: ";
    cin.ignore();
    getline(cin, title);
    for(int i = 0; i < bookBase.size(); i++) {
        if(bookBase.at(i).title == title) {
            cout << "The book was found under the number: " << i << "\n\n";
            return 0;
        }
    }
    cout << "No book found with that title.\n";
    return -1;
}

void listBooks(const vector<Book> &bookBase) {
    for(int i = 0; i < bookBase.size(); i++) {
        cout << "|" << i+1 << "| |" << bookBase.at(i).title << "| |" << bookBase.at(i).author << "| |" << bookBase.at(i).genre << ((bookBase.at(i).isLent)? "| |not available|\n" : "| |available|\n");
    }
}

