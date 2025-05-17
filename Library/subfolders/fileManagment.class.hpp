#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "book.class.hpp"
#include "user.class.hpp"

using namespace std;

void saveFiles(vector<Book> &bookBase, vector<User> &userBase) {

    ofstream books("saves/books.txt");

    if(books.is_open()) {
        for(int i = 0; i < bookBase.size(); i++) {
            books << bookBase.at(i).title << " " << bookBase.at(i).author << " " << bookBase.at(i).genre << " " << bookBase.at(i).isLent << endl;
        }
    }
    books.close();

    ofstream users("saves/users.txt");

    if(users.is_open()) {
        for (int i = 0; i < userBase.size(); i++) {
            users << userBase.at(i).name << " " << userBase.at(i).password << " "
                  << userBase.at(i).stringifyBooks("lent") << " "
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
            istringstream iss(line);
            vector<string> tokens;
            string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
            if (tokens.size() < 4) continue; // skip malformed lines

            // The last token is isLent, second-to-last is genre, third-to-last is author, the rest is title
            bool isLent = (tokens.back() == "1");
            string genre = tokens[tokens.size() - 2];
            string author = tokens[tokens.size() - 3];
            string title;
            for (size_t i = 0; i < tokens.size() - 3; ++i) {
                if (i > 0) title += " ";
                title += tokens[i];
            }
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
            istringstream iss(line);
            string name, password, lentBooksStr, readBooksStr;
            iss >> name >> password >> lentBooksStr >> readBooksStr;

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

