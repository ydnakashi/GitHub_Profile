#include "File.h"

File::File(string n, string cont, Date& d) {
    name = n;
    content = cont;
    date = d;
}

bool File::lessThan(Date& date) {
    return this->date.lessThan(date);
}

void File::print() {
    cout <<this->name <<" ";
    date.print();
}

void File::printContents() {
    this->print();
    cout <<content;
}

Date File::getDate() {
    return date;
}

string File::getName() {
    return name;
}