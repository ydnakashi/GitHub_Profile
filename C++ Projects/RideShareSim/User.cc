#include "User.h"

User::User(char idCode, int idNum, const string& name, int rating, const Location& location):name(name), rating(rating), loc(location) {
    id = idCode + to_string(idNum);
}

void User::print() const {
    cout <<"\n  User ID: " <<id <<"\n  Rating: " <<rating <<"\n  Location: ";
    loc.print();
}