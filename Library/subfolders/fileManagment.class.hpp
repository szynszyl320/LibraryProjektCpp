#include <iostream>
#include <fstream>

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
            users << userBase.at(i).name << " " << userBase.at(i).password << " " << userBase.at(i).stringifyLentBooks() << endl;//" " << user.at(i).readBooks << endl;
        }
    }

    users.close();
}
